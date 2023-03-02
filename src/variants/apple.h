#ifndef APPLE_H
#define APPLE_H

#include <CoreGraphics/CoreGraphics.h>


void print_resolutions(void){
    uint32_t count;
    CGGetActiveDisplayList(0, NULL, &count);

    CGDirectDisplayID displays[count];
    CGGetActiveDisplayList(count, displays, &count);

    for (uint32_t i = 0; i < count; i++) {
        uint32_t width = CGDisplayPixelsWide(displays[i]);
        uint32_t height = CGDisplayPixelsHigh(displays[i]);

        printf("Display %d: %ux%u\n", i+1, width, height);
    }
}



#endif /* APPLE_H */


