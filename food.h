// Nama Program : food.h
// Deskripsi    : Definisi struktur dan fungsi untuk manajemen makanan dalam permainan,
//                bertujuan merancang mekanisme generasi dan interaksi makanan dengan ular
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#ifndef FOOD_H
#define FOOD_H

#include "vector.h"
#include "snake.h"

// Struktur untuk merepresentasikan objek makanan dalam permainan
typedef struct
{
  Vector2 position; // Posisi makanan
} Food;

/**
 * Fungsi untuk membuat objek makanan baru
 * @param screen_width lebar layar
 * @param screen_height tinggi layar
 * @param snake menunjuk ke objek ular untuk menghindari tabrakan
 * @return objek makanan baru bertipe Food
 */
Food create_food(int screen_width, int screen_height, Snake *snake);

/**
 * Fungsi untuk menghasilkan posisi makanan secara acak
 * @param screen_width lebar layar
 * @param screen_height tinggi layar
 * @param snake menunjuk ke objek ular untuk menghindari tabrakan
 * @return posisi makanan yang valid bertipe Vector2
 */
Vector2 food_generate_position(int screen_width, int screen_height, Snake *snake);

#endif // FOOD_H