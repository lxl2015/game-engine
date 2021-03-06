#ifndef GAME_H
#define GAME_H

#include "engine/color.h"

#include <iostream>

const uint SCREEN_WIDTH = 1024;
const uint SCREEN_HEIGHT = 576;

const uint TILE_CHUNK_LOWER_BITS = 4;
const uint TILE_CHUNK_SIZE = 1 << 4;
const uint TILE_CHUNK_LOWER_BITS_MASK = TILE_CHUNK_SIZE - 1;

const uint TILES_PER_SCREEN_X = 16;
const uint TILES_PER_SCREEN_Y = 9;

const double METERS_TO_PIXELS = SCREEN_WIDTH / TILES_PER_SCREEN_X; // Each tile is a meter

const uint TILE_WIDTH = SCREEN_WIDTH / TILES_PER_SCREEN_X;
const uint TILE_HEIGHT = SCREEN_HEIGHT / TILES_PER_SCREEN_Y;
const color_t TILE_COLOR = rgb(100, 100, 100);

typedef bool tile_t;

struct tile_chunk_t {
  tile_t* tiles;
};

struct world_t {
  tile_chunk_t* tile_chunks;
};

typedef double meters;
typedef double pixels;

struct location_t {
  // Which tile
  int tile_x;
  int tile_y;

  // Offset in tile
  meters x;
  meters y;
};

struct screen_location_t {
  pixels x;
  pixels y;
};

struct game_state_t {
  game_state_t() : initialized(false) {}
  bool initialized;

  location_t player_location;
  world_t world;
};

#endif
