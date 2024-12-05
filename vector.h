#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

typedef struct
{
  int x;
  int y;
} Vector2;

Vector2 vector2_create(int x, int y);

bool vector2_equals(Vector2 a, Vector2 b);

Vector2 vector2_add(Vector2 a, Vector2 b);

bool vector2_is_in_bounds(Vector2 pos, int width, int height);

#endif