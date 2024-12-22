// Nama Program : vector.h
// Deskripsi    : Definisi struktur dan fungsi vektor untuk manajemen koordinat dalam permainan snake,
//                bertujuan menyediakan abstraksi koordinat untuk mendukung pergerakan objek
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

// Struktur untuk merepresentasikan vektor 2D
typedef struct
{
  int x; // Komponen x dari vektor
  int y; // Komponen y dari vektor
} Vector2;

/**
 * Fungsi untuk membuat vektor 2D baru
 * @param x parameter input passing by value, tipe int, mewakili koordinat x dari vektor
 * @param y parameter input passing by value, tipe int, mewakili koordinat y dari vektor
 * @return Mengembalikan vektor baru dengan koordinat (x, y) bertipe Vector2
 */
Vector2 vector2_create(int x, int y);

/**
 * Fungsi untuk membandingkan dua vektor
 * @param a parameter input passing by value, tipe Vector2, vektor pertama untuk dibandingkan
 * @param b parameter input passing by value, tipe Vector2, vektor kedua untuk dibandingkan
 * @return Mengembalikan true jika kedua vektor sama, false jika tidak
 */
bool vector2_equals(Vector2 a, Vector2 b);

/**
 * Fungsi untuk menjumlahkan dua vektor
 * @param a parameter input passing by value, tipe Vector2, vektor pertama
 * @param b parameter input passing by value, tipe Vector2, vektor kedua
 * @return Mengembalikan hasil penjumlahan kedua vektor bertipe Vector2
 */
Vector2 vector2_add(Vector2 a, Vector2 b);

/**
 * Fungsi untuk memeriksa apakah posisi berada dalam batas layar
 * @param pos parameter input passing by value, tipe Vector2, posisi yang akan diperiksa
 * @param width parameter input passing by value, tipe int, lebar layar
 * @param height parameter input passing by value, tipe int, tinggi layar
 * @return Mengembalikan true jika posisi dalam batas, false jika tidak
 */
bool vector2_is_in_bounds(Vector2 pos, int width, int height);

#endif // VECTOR_H