/*
 * utility.c
 *
 *  Created on: Feb 12, 2021
 *      Author: pivanov
 */

#include <stdio.h>

#define TEXT_FORMAT "%zu %s"
#define TEXT_FORMAT_EXT "%zu.%zu %s"
#define TEXT_BUFFER_SZ 128

char text_buffer[TEXT_BUFFER_SZ];
const char* units[] = {"B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};

const char* format_size_t(size_t size) {
    int i = 0;
    size_t remainder = 0;
    while (size > 1024) {
    	remainder %= 1024;
        size /= 1024;
        i++;
    }
    if (remainder > 0) {
    	snprintf(text_buffer, TEXT_BUFFER_SZ, TEXT_FORMAT, size, units[i]);
    }
    else {
    	snprintf(text_buffer, TEXT_BUFFER_SZ, TEXT_FORMAT_EXT, size, remainder, units[i]);
    }
    return text_buffer;
}
