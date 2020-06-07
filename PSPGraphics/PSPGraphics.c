#include <pspdisplay.h>
#include <pspgu.h>
#include <math.h>

#include "./PSPGraphics.h"
#include "../common/vram.h"

void *frame_buffer, *display_frame_buffer, *depth_buffer;
static unsigned int __attribute__((aligned(16))) list[262144];

void init_graphics()
{
    frame_buffer = getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_8888);
    display_frame_buffer = getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_8888);
    depth_buffer = getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_4444);

    sceGuInit();

    sceGuStart(GU_DIRECT, list);

    sceGuDrawBuffer(GU_PSM_8888, frame_buffer, BUFFER_WIDTH);
    sceGuDispBuffer(SCREEN_WIDTH, SCREEN_HEIGHT, display_frame_buffer, BUFFER_WIDTH);
    sceGuDepthBuffer(depth_buffer, BUFFER_WIDTH);

    sceGuOffset(WIDTH_OFFSET, HEIGHT_OFFSET);
    sceGuViewport(VIEWPORT_ORIGIN_X, VIEWPORT_ORIGIN_Y, SCREEN_WIDTH, SCREEN_HEIGHT);
    sceGuDepthRange(MAX_DEPTH_RANGE, MIN_DEPTH_RANGE);
    sceGuScissor(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    sceGuEnable(GU_SCISSOR_TEST);

    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblank();
    sceGuDisplay(GU_TRUE);
}

void use_graphics()
{
    sceGuStart(GU_DIRECT, list);
}

void stop_using_graphics()
{
    sceGuFinish();
    sceGuSync(0, 0);
}

void get_vram_memory(unsigned int n_triangles, Vector3f **vertices)
{
    (*vertices) = (struct Vector3f *)sceGuGetMemory(n_triangles * sizeof(struct Vector3f));
}

void swap_buffers()
{
    sceGuSwapBuffers();
}

void clear_color_buffer(unsigned int color)
{
    sceGuClearColor(color);
    sceGuClear(GU_COLOR_BUFFER_BIT);
}

void clear_depth_buffer(unsigned int depth)
{
    sceGuClearDepth(depth);
    sceGuClear(GU_DEPTH_BUFFER_BIT);
}

void change_color(unsigned int color)
{
    sceGuColor(color);
}

void draw_triangle_array_2D(Vector3f *vertices, unsigned int n_vertices)
{
    sceGuDrawArray(GU_TRIANGLES, GU_VERTEX_32BITF | GU_TRANSFORM_2D, n_vertices, 0, vertices);
}