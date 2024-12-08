// Nama Program : food.h
// Deskripsi    : Definisi struktur dan fungsi untuk manajemen makanan dalam permainan,
//                bertujuan merancang mekanisme generasi dan interaksi makanan dengan ular
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#ifndef FOOD_H
#define FOOD_H

#include "vector.h"
#include "snake.h"
#include <stdlib.h>

typedef struct
{
  Vector2 position;
} Food;

// Membuat makanan baru
Food create_food(int screen_width, int screen_height, Snake *snake);

// Menghasilkan posisi makanan baru
Vector2 food_generate_position(int screen_width, int screen_height, Snake *snake);

#endif