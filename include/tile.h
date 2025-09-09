#ifndef tile_h
#define tile_h

#include <stdbool.h>
#include <stdlib.h>

typedef struct Tile
{
    bool alive;
    bool next;
} Tile;

bool tile_calculate_alive(Tile *tile, unsigned int neighbors_alive);

Tile **tile_universe_init(unsigned int width, unsigned int height);

void tile_universe_deinit(Tile **universe);

#endif
