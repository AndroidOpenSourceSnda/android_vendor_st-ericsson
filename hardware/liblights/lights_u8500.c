/*
 * Copyright (C) 2014 XianGxin
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "lights"

#include <cutils/log.h>
#include <errno.h>
#include <fcntl.h>
#include <hardware/lights.h>

static pthread_once_t g_init = PTHREAD_ONCE_INIT;
static pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;

/* LCD backlight related variables */
static int g_backlight = 255;
char const *const LCD_FILE =  "/sys/class/leds/lcd-backlight/brightness";
char const *const BUTTON_FILE =  "/sys/class/leds/button-backlight/brightness";

static int write_cmd(char const *path, char *cmd, int size)
{
	int fd, ret;

	fd = open(path, O_WRONLY);
	if (fd < 0) {
		ALOGE("Cannot open %s\n", path);
		return -ENODEV;
	}

	ALOGD("write_cmd: %s to %s\n", cmd, path);
	ret = write(fd, cmd, size);
	if (ret != size)
		ALOGE("Error. Wrote: %d, should have written: %d\n", ret, size);

	close(fd);
	return ret;
}

static int close_lights(struct light_device_t *dev)
{
	if (dev)
		free(dev);
	return 0;
}

static int is_lit(struct light_state_t const* state)
{
    return state->color & 0x00ffffff;
}

static int rgb_to_brightness(struct light_state_t const* state)
{
	int color = state->color & 0x00ffffff;

	/*
	 * ref: hardware/libhardware/include/hardware/lights.h
	 * unsigned char brightness = ((77*((color>>16)&0x00ff))
	 *	+ (150*((color>>8)&0x00ff)) + (29*(color&0x00ff))) >> 8;
	 */
	return ((77*((color>>16)&0x00ff)) +
		(150*((color>>8)&0x00ff)) + (29*(color&0x00ff))) >> 8;
}

static int set_light_buttons(struct light_device_t *dev,
		struct light_state_t const *state)
{
    int err = 0;
    char buffer[20];
    pthread_mutex_lock(&g_lock);

    int brightness = is_lit(state)?80:0;
    int bytes = sprintf(buffer, "%d\n", brightness);	
    err = write_cmd(BUTTON_FILE, buffer, bytes); 

    pthread_mutex_unlock(&g_lock);
    return err;
}

static int set_light_backlight(struct light_device_t *dev,
		struct light_state_t const *state)
{
	int err = 0;
	char buffer[20];
	int brightness = rgb_to_brightness(state);

	ALOGV("%s : rgb_to_backlight = %d\n", __func__, brightness);
	pthread_mutex_lock(&g_lock);
	g_backlight = brightness;
	int bytes = sprintf(buffer, "%d\n", brightness);
	err = write_cmd(LCD_FILE, buffer, bytes);
	pthread_mutex_unlock(&g_lock);
	return err;
}

void init_globals(void)
{
	pthread_mutex_init(&g_lock, NULL);
}

static int open_lights(const struct hw_module_t *module, char const *name,
		struct hw_device_t **device)
{

	ALOGD("light ID: %s\n", name);

	int (*set_light) (struct light_device_t * dev,
			struct light_state_t const *state);

	if (0 == strcmp(LIGHT_ID_BACKLIGHT, name)) {
		set_light = set_light_backlight;
	} else if (0 == strcmp(LIGHT_ID_BUTTONS, name)) {
		set_light = set_light_buttons;
	} else {
		return -EINVAL;
	}

	pthread_once(&g_init, init_globals);

	struct light_device_t *dev = malloc(sizeof(struct light_device_t));
	memset(dev, 0, sizeof(*dev));
	dev->common.tag = HARDWARE_DEVICE_TAG;
	dev->common.version = 0;
	dev->common.module = (struct hw_module_t *) module;
	dev->common.close = (int (*)(struct hw_device_t *)) close_lights;
	dev->set_light = set_light;

	*device = (struct hw_device_t *) dev;
	return 0;
}

static struct hw_module_methods_t lights_module_methods = {
	.open = open_lights,
};

struct hw_module_t HAL_MODULE_INFO_SYM = {
	.tag = HARDWARE_MODULE_TAG,
	.version_major = 1,
	.version_minor = 0,
	.id = LIGHTS_HARDWARE_MODULE_ID,
	.name = "ST-Ericsson Ux500 Light module",
	.author = "XianGxin",
	.methods = &lights_module_methods,
};
