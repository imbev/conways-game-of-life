#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "SDL3/SDL.h"

#include "color.h"
#include "tile.h"

#define width 30
#define height 30
#define size 20

int main(void)
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("Failed to init sdl.\n%s\n", SDL_GetError());
    }

    SDL_Window *window = SDL_CreateWindow("Conway's Game of Life", width * size, height * size, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    SDL_Event e;
    bool running = true;

    Tile **universe = tile_universe_init(width, height);

    srand(time(NULL));
    
    universe[10][10].alive = true;
    universe[11][10].alive = true;
    universe[14][10].alive = true;
    universe[15][10].alive = true;
    universe[16][10].alive = true;
    universe[11][8].alive = true;
    universe[13][9].alive = true;

    Uint64 interval = 250;
    Uint64 next_time = SDL_GetTicks() + interval;

    while (running)
    {
        Uint64 time = SDL_GetTicks();

        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_EVENT_QUIT:
                running = false;
                break;
            }
        }

        if (time < next_time) {
            continue;
        }

        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                unsigned int neighbors_alive = 0;
                if (x != 0 && y != height-1) {
                    neighbors_alive += universe[x-1][y+1].alive;
                }
                if (y != height-1) {
                    neighbors_alive += universe[x][y+1].alive;
                }
                if (x != width-1 && y != height-1) {
                    neighbors_alive += universe[x+1][y+1].alive;
                }
                if (x != 0) {
                    neighbors_alive += universe[x-1][y].alive;
                }
                if (x != width-1) {
                    neighbors_alive += universe[x+1][y].alive;
                }
                if (x != 0 && y != 0) {
                    neighbors_alive += universe[x-1][y-1].alive;
                }
                if (y != 0) {
                    neighbors_alive += universe[x][y-1].alive;
                }
                if (x != width-1 && y != 0) {
                    neighbors_alive += universe[x+1][y-1].alive;
                }
                universe[x][y].next = tile_calculate_alive(&universe[x][y], neighbors_alive);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        Color color = (Color)(rand() % 4);
        renderer_set_color(renderer, color);
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                universe[x][y].alive = universe[x][y].next;
                if (!universe[x][y].alive) {
                    continue;
                }
                SDL_FRect rect = { .w = size, .h = size, .x = x * size, .y = y * size };
                SDL_RenderFillRect(renderer, &rect);
            }
        }

        SDL_RenderPresent(renderer);
        next_time = time + interval;
    }

    tile_universe_deinit(universe);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}