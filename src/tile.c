#include "tile.h"

bool tile_calculate_alive(Tile *tile, unsigned int neighbors_alive) {
    if (neighbors_alive < 2) {
        return false;
    }
    if (neighbors_alive == 3) {
        return true;
    }
    if (tile->alive && neighbors_alive == 2) {
        return true;
    }
    if (neighbors_alive > 3) {
        return false;
    }
}

Tile **tile_universe_init(unsigned int width, unsigned int height) {
    Tile **universe = malloc(sizeof(Tile*) * width);
    for (int x=0; x<width; x++) {
        Tile *col = malloc(sizeof(Tile) * width);
        for (int y=0; y<height; y++) {
            col[y] = (Tile){ .alive = false };
        }
        universe[x] = col;
    }
    return universe;
}

void tile_universe_deinit(Tile **universe) {
    unsigned int width = sizeof(universe) / sizeof(universe[0]);
    for (int x=0; x<width; x++) {
        free(universe[x]);
    }
    free(universe);
}
