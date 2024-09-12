#ifndef __SCOOTD_H_
#define __SCOOTD_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>






typedef struct
{
	unsigned int state;

} scoot_device;


scoot_device * scootd_util_open_shared_memory(char *strFileName);










#endif
