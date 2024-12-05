#include "vector.h"

Vector2 vector2_create(int x, int y)
{
  Vector2 vec = {x, y};
  return vec;
}

bool vector2_equals(Vector2 a, Vector2 b)
{
  return a.x == b.x && a.y == b.y;
}

Vector2 vector2_add(Vector2 a, Vector2 b)
{
  Vector2 vec = {a.x + b.x, a.y + b.y};
  return vec;
}

bool vector2_is_in_bounds(Vector2 pos, int width, int height)
{
  return pos.x >= 0 && pos.x < width &&
         pos.y >= 0 && pos.y < height;
}