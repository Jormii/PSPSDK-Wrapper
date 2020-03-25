#include <pspgu.h>

#include "./PSPGraphics.h"
#include "../common/vram.h"

void *frame_buffer, *display_frame_buffer, *depth_buffer;
static unsigned int __attribute__((aligned(16))) list[262144];

void init_graphics() {
    frame_buffer = getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_8888);
    display_frame_buffer = getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_8888);
    depth_buffer = getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_4444);

    sceGuInit();
    
    sceGuDrawBuffer(GU_PSM_8888, frame_buffer, BUFFER_WIDTH);
    sceGuDispBuffer(SCREEN_WIDTH, SCREEN_WIDTH, display_frame_buffer, BUFFER_WIDTH);
    sceGuDepthBuffer(depth_buffer, BUFFER_WIDTH);

    sceGuOffset(WIDTH_OFFSET, HEIGHT_OFFSET);
    sceGuViewport(VIEWPORT_ORIGIN_X, VIEWPORT_ORIGIN_Y, SCREEN_WIDTH, SCREEN_HEIGHT);
    sceGuDepthRange(MAX_DEPTH_RANGE, MIN_DEPTH_RANGE);
    sceGuScissor(0, 0, SCREEN_HEIGHT, SCREEN_WIDTH);
    sceGuEnable(GU_SCISSOR_TEST);

    sceGuSync(0, 0);
    sceGuDisplay(GU_TRUE);
}