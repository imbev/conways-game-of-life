#ifndef color_h
#define color_h

#include "SDL3/SDL.h"

typedef enum Color {
    RED,
    GREEN,
    BLUE,
    WHITE,
} Color;

void renderer_set_color(SDL_Renderer *renderer, Color color);

#endif
