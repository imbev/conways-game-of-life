#include "color.h"

void renderer_set_color(SDL_Renderer *renderer, Color color) {
    switch (color) {
        case RED:
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 100);
            break;
        case GREEN:
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 100);
            break;
        case BLUE:
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 100);
            break;
        case WHITE:
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
            break;
    }
}