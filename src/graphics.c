#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include "graphics.h"

int GRAPHICS_init(Graphics *graphics) {
    if (!graphics -> windowTitle) graphics -> windowTitle ="No Name";
    if (!graphics -> width) graphics -> width = 800;
    if (!graphics -> height) graphics -> height = 600;

    if (!glfwInit()) 
    {
        fprintf(stderr, "error can't  initialize GLFW");
        return 1;
    }

    graphics->window = glfwCreateWindow(
        graphics->width, 
        graphics->height, 
        graphics->windowTitle, 
        NULL, 
        NULL
    ); 

    if (!graphics -> window) {
        fprintf(stderr, "error creating window");
        return 1;
    }

        /* Make the window's context current */
    glfwMakeContextCurrent(graphics->window);

    return 0;
}

void GRAPHICS_free(Graphics *graphics) {
    glfwTerminate();
}
