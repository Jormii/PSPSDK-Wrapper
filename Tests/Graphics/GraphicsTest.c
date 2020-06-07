#include <pspkernel.h>
#include <pspdisplay.h>

#include "../../common/callbacks.h"
#include "../../PSPGraphics/PSPGraphics.h"
#include "../../PSPDebug/PSPDebug.h"

PSP_MODULE_INFO("PSPInputText", PSP_MODULE_USER, 1, 1);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

void test_draw_triangle(float z)
{
    Vector3f *vertices;
    get_vram_memory(3, &vertices);

    vertices[0].x = (SCREEN_WIDTH / 2);
    vertices[0].y = (SCREEN_HEIGHT / 4);
    vertices[0].z = z;

    vertices[1].x = (SCREEN_WIDTH / 4);
    vertices[1].y = (3 * SCREEN_HEIGHT / 4);
    vertices[1].z = z;

    vertices[2].x = (3 * SCREEN_WIDTH / 4);
    vertices[2].y = (3 * SCREEN_HEIGHT / 4);
    vertices[2].z = z;

    draw_triangle_array_2D(vertices, 3);
}

void test_draw_triangle_2(float z)
{
    Vector3f *vertices;
    get_vram_memory(3, &vertices);

    vertices[0].x = (SCREEN_WIDTH / 2);
    vertices[0].x = vertices[0].x + vertices[0].x / 3;
    vertices[0].y = (SCREEN_HEIGHT / 4);
    vertices[0].z = z;

    vertices[1].x = (SCREEN_WIDTH / 4);
    vertices[1].x = vertices[1].x + vertices[1].x / 3;
    vertices[1].y = (3 * SCREEN_HEIGHT / 4);
    vertices[1].z = z;

    vertices[2].x = (3 * SCREEN_WIDTH / 4);
    vertices[2].x = vertices[2].x + vertices[2].x / 3;
    vertices[2].y = (3 * SCREEN_HEIGHT / 4);
    vertices[2].z = z;

    draw_triangle_array_2D(vertices, 3);
}

void test_draw_triangle_3(float z)
{
    Vector3f *vertices;
    get_vram_memory(3, &vertices);

    vertices[0].x = (SCREEN_WIDTH / 2);
    vertices[0].x = vertices[0].x - vertices[0].x / 3;
    vertices[0].y = (SCREEN_HEIGHT / 4);
    vertices[0].z = z;

    vertices[1].x = (SCREEN_WIDTH / 4);
    vertices[1].x = vertices[1].x - vertices[1].x / 3;
    vertices[1].y = (3 * SCREEN_HEIGHT / 4);
    vertices[1].z = z;

    vertices[2].x = (3 * SCREEN_WIDTH / 4);
    vertices[2].x = vertices[2].x - vertices[2].x / 3;
    vertices[2].y = (3 * SCREEN_HEIGHT / 4);
    vertices[2].z = z;

    draw_triangle_array_2D(vertices, 3);
}

int main()
{
    init_graphics();

    init_debug();
    set_text_color(255, 255, 255);

    setupCallbacks();

    while (running())
    {
        use_graphics();

        clear_color_buffer(0);
        clear_depth_buffer(0);

        change_color(0xff0000ff);
        test_draw_triangle(-1);

        change_color(0xff00ff00);
        test_draw_triangle_2(1);

        change_color(0xffff0000);
        test_draw_triangle_3(0);

        stop_using_graphics();

        sceDisplayWaitVblankStart();
        swap_buffers();
        set_cursor_position(get_left_margin(), get_top_margin());
        debug_print("Hola, muy buenas noches");
    }

    return 0;
}