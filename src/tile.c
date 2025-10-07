#include "tile.h"
#include <assert.h>
#include <stdlib.h>

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
    return false;
}

Universe *tile_universe_init(unsigned int width, unsigned int height) {
    Universe *universe = malloc(sizeof(Universe));
    universe->tiles = malloc(sizeof(Tile*) * width);
    universe->width = width;
    universe->height = height;

    for (unsigned int x=0; x<width; x++) {
        Tile *col = malloc(sizeof(Tile) * width);
        for (unsigned int y=0; y<height; y++) {
            col[y] = (Tile){ .alive = false };
        }
        universe->tiles[x] = col;
    }
    return universe;
}

void tile_universe_deinit(Universe *universe) {
    for (unsigned int x=0; x<universe->width; x++) {
        free(universe->tiles[x]);
    }
    free(universe->tiles);
    free(universe);
}
