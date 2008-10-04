/*
 * suspend functions for machines with Mac-style pmu
 *
 * Copyright 2006 Red Hat, Inc.
 *
 * Based on work from:
 *    Peter Jones <pjones@redhat.com>
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

#if !defined(PMU_IOC_CAN_SLEEP) || !defined(PMU_IOC_SLEEP)
#error you must have working pmu kernel headers installed to build this program.
#endif

static int
pmu_can_sleep(const int fd)
{
    unsigned long arg = 0;
    if (ioctl(fd, PMU_IOC_CAN_SLEEP, &arg) < 0 || arg != 1)
        return 1;
    return 0;
}
    
static int
pmu_sleep(const int fd)
{
    unsigned long arg = 0;

    if (ioctl(fd, PMU_IOC_SLEEP, arg) < 0)
        return 1;
    return 0;
}

static inline int
print_usage(FILE *output, int retval)
{
    fprintf(output, "usage: pm-pmu --suspend | --check\n");
    return retval;
}

int main(int argc, char *argv[])
{
    int task=0,fd=0,ret=0;
    if (argc != 2)
        return print_usage(stderr, 1);
    if (!strcmp(argv[1], "--help")) {
        task=1;
    } else if (!strcmp(argv[1],"--check")) {
        task=2;
    } else if (!strcmp(argv[1],"--suspend")) {
        task=3;
    }
    switch (task) {
        case 0: ret = print_usage(stderr, 1); break;
        case 1: ret = print_usage(stdout, 0); break;
        case 2: /* this is intentional */
        case 3:
            if (access("/dev/pmu", W_OK)) {
                ret = 1;
            } else {
                if ((fd = open("/dev/pmu", O_RDWR)) < 0) {
                    perror("open");
                    return 1;
                }
            
                ret = pmu_can_sleep(fd);
                if (!ret && task == 3) 
                    ret = pmu_sleep(fd);
                close(fd);
            }
            break;
    }
   return ret; 
}

/*
 * vim:ts=8:sw=4:sts=4:et
 */
