// Nama Program : vector.h
// Deskripsi    : Definisi struktur dan fungsi vektor untuk manajemen koordinat dalam permainan snake,
//                bertujuan menyediakan abstraksi koordinat untuk mendukung pergerakan objek
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

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