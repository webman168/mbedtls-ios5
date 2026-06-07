#ifndef IOS5_SHIM_H
#define IOS5_SHIM_H

#include <sys/time.h>
#include <string.h>

// Forcefully kill Apple's broken buffer-overflow macro wrappers 
// so standard C macro expansion works correctly inside memcpy
#ifdef memcpy
#undef memcpy
#endif

#ifdef memmove
#undef memmove
#endif

// Define missing constants so the compiler doesn't throw a fit
#define CLOCK_MONOTONIC 1

// Shim clock_gettime using gettimeofday
static inline int clock_gettime(int clock_id, struct timespec *tp) {
    struct timeval tv;
    if (gettimeofday(&tv, NULL) != 0) return -1;
    tp->tv_sec = tv.tv_sec;
    tp->tv_nsec = tv.tv_usec * 1000;
    return 0;
}

#endif
