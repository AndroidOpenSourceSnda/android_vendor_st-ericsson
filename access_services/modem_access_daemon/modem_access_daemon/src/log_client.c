/*
 * Copyright (C) ST-Ericsson SA 2011. All rights reserved.
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <string.h>

#include <util_mainloop.h>
#include <util_log.h>
#include "mad_log.h"


static int s_mad_log_fd = -1;
static int s_mad_log_file_wd = -1;
static int s_mad_log_dir_wd = -1;
static util_log_type_t s_mad_log_level = (UTIL_LOG_TYPE_INFO | UTIL_LOG_TYPE_ERROR);

void mad_set_log_level(util_log_type_t log_level)
{
    if (log_level > 0) {
        /* It should not be possible to turn off ERROR logs. */
        s_mad_log_level = (log_level | UTIL_LOG_TYPE_ERROR);
    }
}

util_log_type_t mad_get_log_level()
{
    return s_mad_log_level;
}

int mad_log_select_callback(const int fd, const void *data_p)
{
    struct inotify_event *inotify_data_p = NULL;
    char tmp_data[100];
    int res = -1;
    (void)data_p;
    util_log_type_t log_level = UTIL_LOG_TYPE_UNKNOWN;

    res = read(fd, &tmp_data, sizeof(tmp_data));

    if (res < 0) {
        MAD_LOG_E("Error %d (%s) when reading inotify ",
                 errno, strerror(errno));
        goto exit;
    }

    inotify_data_p = (struct inotify_event *)tmp_data;

    if ((inotify_data_p->mask & IN_IGNORED) > 0) {
        MAD_LOG_I("log configuration file updated, waiting for file to settle");
    }

    if ((inotify_data_p->mask & IN_CREATE) > 0 && strncmp(inotify_data_p->name, UTIL_LOG_FILE_NAME, inotify_data_p->len) == 0) {

        MAD_LOG_D("log file created add new watch");
        (void)inotify_rm_watch(s_mad_log_fd, s_mad_log_file_wd);
        s_mad_log_file_wd = inotify_add_watch(s_mad_log_fd, UTIL_LOG_FILE, IN_MODIFY);

        if (s_mad_log_file_wd < 0) {
            MAD_LOG_E("Error %d (%s) when adding watch on file ",
                     errno, strerror(errno), UTIL_LOG_FILE);
        }
    }

    if ((inotify_data_p->mask & IN_IGNORED) == 0) {
        log_level = util_read_log_file(UTIL_LOG_MODULE_CN);
        mad_set_log_level(log_level);
    }

exit:
    return TRUE;
}

void mad_log_init()
{
    util_log_type_t log_level = UTIL_LOG_TYPE_UNKNOWN;
    log_level = util_read_log_file(UTIL_LOG_MODULE_MAD);
    mad_set_log_level(log_level);
    s_mad_log_fd = inotify_init();

    if (s_mad_log_fd < 0) {
        MAD_LOG_E("Error %d (%s) when init inotify",
                 errno, strerror(errno), UTIL_LOG_FILE);
        goto exit;
    }

    s_mad_log_file_wd = inotify_add_watch(s_mad_log_fd, UTIL_LOG_FILE, IN_MODIFY | IN_MOVE_SELF);

    if (s_mad_log_file_wd < 0) {
        MAD_LOG_E("Error %d (%s) when adding watch on file %s",
                 errno, strerror(errno), UTIL_LOG_FILE);
    }

    s_mad_log_dir_wd = inotify_add_watch(s_mad_log_fd, UTIL_LOG_DIR, IN_CREATE);

    if (s_mad_log_dir_wd < 0) {
        MAD_LOG_E("Error %d (%s) when adding watch on dir %s",
                 errno, strerror(errno), UTIL_LOG_DIR);
    }

    util_mainloop_add_watch(EVENT_READ, s_mad_log_fd, (void *)NULL, mad_log_select_callback, NULL);

exit:
    return;
}

void mad_log_close()
{
    util_mainloop_remove_watch(EVENT_READ, s_mad_log_fd);
    (void)inotify_rm_watch(s_mad_log_fd, s_mad_log_file_wd);
    (void)inotify_rm_watch(s_mad_log_fd, s_mad_log_dir_wd);
    close(s_mad_log_fd);
}
