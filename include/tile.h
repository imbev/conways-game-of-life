#ifndef tile_h
#define tile_h

#include <stdbool.h>

typedef struct Tile
{
    bool alive;
    bool next;
} Tile;

typedef struct Universe {
    Tile **tiles;
    unsigned int width;
    unsigned int height;
} Universe;

bool tile_calculate_alive(Tile *tile, unsigned int neighbors_alive);

Universe *tile_universe_init(unsigned int width, unsigned int height);

void tile_universe_deinit(Universe *universe);

#endif
