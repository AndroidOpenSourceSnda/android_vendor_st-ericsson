/*****************************************************************************/
/**
*  ST-Ericsson, 2011 - All rights reserved
*  Reproduction and Communication of this document is strictly prohibited
*  unless specifically authorized in writing by ST-Ericsson
*
* \file
* \brief   9P dth array unitary test
* \author  ST-Ericsson
*/
/*****************************************************************************/

#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <assert.h>

#include "spfs.h"
#include "spclient.h"

enum dth_type {
	DTH_8 = 1,
	DTH_16 = 2,
	DTH_32 = 4,
	DTH_64 = 8,
};

extern int spc_chatty;

static void usage()
{
	fprintf(stderr, "9readarray -d -p port -o offset addr path type\n");
	exit(1);
}

int get_data_size(char *type)
{
	int size = 0;

	/* Check data size according to type string. */
	if (strcmp(type, "u8") == 0)
		size = sizeof(uint8_t);
	else if (strcmp(type, "s8") == 0)
		size = sizeof(int8_t);
	else if (strcmp(type, "u16") == 0)
		size = sizeof(uint16_t);
	else if (strcmp(type, "s16") == 0)
		size = sizeof(int16_t);
	else if (strcmp(type, "u32") == 0)
		size = sizeof(uint32_t);
	else if (strcmp(type, "s32") == 0)
		size = sizeof(int32_t);
	else if (strcmp(type, "u64") == 0)
		size = sizeof(uint64_t);
	else if (strcmp(type, "s64") == 0)
		size = sizeof(int64_t);
	else {
		fprintf(stderr,
			"invalid type.\nCorrects values are among u8, s8, u16,"
			"s16, u32, s32, u64, s64\n");
		exit(-1);
	}

	return size;
}

void printData(int size, u8 *data, int nbbytes, int offset)
{
	int i, j;
	int64_t value;
	u8 *buff;

	i = j = 0;
	value = 0;
	buff = (u8 *) &value;

	if (offset == 0) {
		/* Read the whole array. */
		for (i = 0; i < nbbytes; i += size) {
			for (j = 0; j < size; j++)
				*(buff + j) = *(data + i + j);

			printf("%lld ", value);
		}
	} else {
		/* Read a single element array. */
		for (j = 0; j < size; j++)
			*(buff + j) = *(data + i + j);

		printf("%lld ", value);
	}
	printf("\n");

}

int main(int argc, char **argv)
{
	int n, off, size;
	int c, port;
	char *addr;
	char *uname, *path, *s_offset, *s_port, *type;
	Spuser *user;
	Spcfsys *fs;
	Spcfid *fid;
	char buf[512];

	port = 9999;
	off = size = 0;

	user = sp_uid2user(geteuid());
	if (!user) {
		fprintf(stderr, "cannot retrieve user %d\n", geteuid());
		exit(1);
	}

	uname = user->uname;
	while ((c = getopt(argc, argv, "dp:o:")) != -1) {
		switch (c) {
		case 'd':
			spc_chatty = 1;
			break;

		case 'u':
			uname = optarg;
			break;

		case 'p':
			s_port = optarg;
			if (*s_port == '\0')
				usage();
			port = atoi(s_port);
			break;

		case 'o':
			s_offset = optarg;
			if (*s_offset == '\0')
				usage();
			off = atoi(s_offset);
			break;

		default:
			usage();
		}
	}

	if (argc - optind < 2)
		usage();

	addr = argv[optind];
	path = argv[optind + 1];
	type = argv[optind + 2];

	if (*type == '\0')
		usage();

	size = get_data_size(type);

	fs = spc_netmount(addr, uname, port);
	fid = spc_open(fs, path, Oread);
	if (!fid) {
		fprintf(stderr, "cannot open\n");
		exit(1);
	}

	while ((n = spc_read(fid, (u8 *) buf, sizeof(buf), off)) > 0) {
		printData(size, (u8 *) buf, n, off);
		off += n;
	}

	spc_close(fid);
	spc_umount(fs);

	exit(0);
}
