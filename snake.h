#ifndef SNAKE_H
#define SNAKE_H

#define MAX_SNAKE_LENGTH 256

#include "vector.h"

typedef struct
{
  Vector2 head;
  Vector2 segments[MAX_SNAKE_LENGTH];
  Vector2 direction;
  int length;
} Snake;

// Membuat ular
Snake create_snake(int start_x, int start_y);

// Menggerakkan ular
void snake_move(Snake *snake);

// Memeriksa tabrakan dengan diri sendiri
bool snake_collides_with_self(Snake *snake);

// Menumbuhkan ular
bool snake_grow(Snake *snake);

// Mendapatkan simbol kepala ular berdasarkan arah
char get_snake_head_symbol(Snake *snake);

// Mengubah arah ular
void snake_change_direction(Snake *snake, Vector2 new_direction);

#endif