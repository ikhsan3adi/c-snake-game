// Nama Program : vector.c
// Deskripsi    : Implementasi fungsi-fungsi manipulasi vector untuk mendukung representasi
//                dan perhitungan koordinat dalam permainan.
//                Bertujuan mengimplementasikan operasi dasar vector dalam permainan.
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

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