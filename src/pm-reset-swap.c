/*
 * mark a swap device as not usable for thaw
 *
 * Copyright 2006 Red Hat, Inc.
 *
 * Authors:
 *   Peter Jones <pjones@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#define _GNU_SOURCE 1

#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* XXX this is a total hack for bad system headers. */
typedef u_int32_t __u32;
#include <linux/pmu.h>

typedef u_int64_t sector_t;

/*
 * Here's what the disk looks like after a successful hibernate:

 00000000  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
 *
 00000400  01 00 00 00 ff df 03 00  00 00 00 00 00 00 00 00  |................|
 00000410  00 00 00 00 00 00 00 00  00 00 00 00 73 77 61 70  |............swap|
 00000420  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
 *
 00000fe0  00 00 00 00 01 00 00 00  00 00 00 00 53 57 41 50  |............SWAP|
 00000ff0  53 50 41 43 45 32 53 31  53 55 53 50 45 4e 44 00  |SPACE2S1SUSPEND.|

 * And here's what it looks like if you haven't hibernated to it:

 00000000  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
 *
 00000400  01 00 00 00 ff df 03 00  00 00 00 00 00 00 00 00  |................|
 00000410  00 00 00 00 00 00 00 00  00 00 00 00 73 77 61 70  |............swap|
 00000420  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
 *
 00000ff0  00 00 00 00 00 00 53 57  41 50 53 50 41 43 45 32  |......SWAPSPACE2|

 *
 */

/* The signature offset is annoying.  The struct is:
 * struct swsusp_header {
 *     char reserved[PAGE_SIZE - 20 - sizeof(sector_t)];
 *     sector_t image;
 *     char orig_sig[10];
 *     char sig[10];
 * }
 */
off_t get_sig_offset(int orig)
{
    int pagesize = sysconf(_SC_PAGESIZE);

    return (off_t)((sizeof (char) * pagesize) - (orig ? 20 : 10));
}

static inline int
print_usage(FILE *output, int retval)
{
    fprintf(output, "usage: pm-reset-swap <device node>\n");
    return retval;
}

int check_resume_block(FILE *dev, off_t offset)
{
    char buf[11] = {0,};
    off_t location = offset + get_sig_offset(0);

    if (fseek(dev, location, SEEK_SET) < 0)
        return -1;
    if (fread(buf, sizeof (char), 10, dev) != 10)
        return -1;

    if (!strncmp(buf, "S1SUSPEND", 9))
        return 1;

    return 0;
}

int clear_resume_block(FILE *dev, off_t offset)
{
    char buf[21] = {0,};
    off_t location = offset + get_sig_offset(1);

    if (fseek(dev, location, SEEK_SET) < 0)
        return -1;

    if (fread(buf, sizeof (char), 20, dev) != 20)
        return -1;

    if (fseek(dev, location, SEEK_SET) < 0)
        return -1;

    memmove(buf+10, buf, 10);
    memset(buf, '\0', 10);

    if (fwrite(buf, sizeof (char), 20, dev) != 20)
        return -1;

    return 0;
}

int main(int argc, char *argv[])
{
    FILE *dev = NULL;
    int rc;

    if (argc != 2)
        return print_usage(stderr, 1);

    if (!strcmp(argv[1], "--help")) {
        return print_usage(stdout, 0);
    }

    if (!(dev = fopen(argv[1], "r+b"))) {
        fprintf(stderr, "Could not open \"%s\": %m\n", argv[1]);
        return 1;
    }

    rc = check_resume_block(dev, 0);
    if (rc < 0) {
        fprintf(stderr, "Could not check \"%s\" for swap signature: %m\n",
                argv[1]);
        fclose(dev);
        return 2;
    }
    rc = 1;
    if (rc == 1) {
        if (clear_resume_block(dev, 0)) {
            fprintf(stderr, "Could not clear swap signature on \"%s\": %m\n",
                    argv[1]);
            fclose(dev);
            return 1;
        }
    }
        
    fclose(dev);
    return 0;
}

/*
 * vim:ts=8:sw=4:sts=4:et
 */
