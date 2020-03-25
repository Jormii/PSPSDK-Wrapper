#ifndef PSP_GRAPHICS_H
#define PSP_GRAPHICS_H

#define BUFFER_WIDTH 512
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272

#define VIEWPORT_ORIGIN_X 2048
#define VIEWPORT_ORIGIN_Y 2048
#define WIDTH_OFFSET VIEWPORT_ORIGIN_X - (SCREEN_WIDTH >> 1)
#define HEIGHT_OFFSET VIEWPORT_ORIGIN_Y - (SCREEN_HEIGHT >> 1)

#define MIN_DEPTH_RANGE 0
#define MAX_DEPTH_RANGE 65535

typedef struct _Vector3f {
    float x, y, z;
} Vector3f;

void init_graphics();

#endif