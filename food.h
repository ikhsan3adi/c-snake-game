// Nama Program : food.h
// Deskripsi    : Definisi struktur dan fungsi untuk manajemen makanan dalam permainan,
//                bertujuan merancang mekanisme generasi dan interaksi makanan dengan ular
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#ifndef FOOD_H
#define FOOD_H

#include "vector.h"
#include "snake.h"

// Struktur untuk merepresentasikan objek makanan dalam permainan
typedef struct
{
  Vector2 position; // Posisi makanan
} Food;

// Fungsi untuk membuat objek makanan baru
// screen_width: parameter input passing by value, tipe int, lebar layar
// screen_height: parameter input passing by value, tipe int, tinggi layar
// snake: parameter input passing by reference, tipe Snake*, menunjuk ke objek ular untuk menghindari tabrakan
// Mengembalikan objek makanan baru bertipe Food
Food create_food(int screen_width, int screen_height, Snake *snake);

// Fungsi untuk menghasilkan posisi makanan secara acak
// screen_width: parameter input passing by value, tipe int, lebar layar
// screen_height: parameter input passing by value, tipe int, tinggi layar
// snake: parameter input passing by reference, tipe Snake*, menunjuk ke objek ular untuk menghindari tabrakan
// Mengembalikan posisi makanan yang valid bertipe Vector2
Vector2 food_generate_position(int screen_width, int screen_height, Snake *snake);

#endif // FOOD_H