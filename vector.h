// Nama Program : vector.h
// Deskripsi    : Definisi struktur dan fungsi vektor untuk manajemen koordinat dalam permainan snake,
//                bertujuan menyediakan abstraksi koordinat untuk mendukung pergerakan objek
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

// Struktur untuk merepresentasikan vektor 2D
// x: subvar bertipe int, mewakili koordinat x dari vektor
// y: subvar bertipe int, mewakili koordinat y dari vektor
typedef struct
{
  int x; // Koordinat x
  int y; // Koordinat y
} Vector2;

// Fungsi untuk membuat vektor 2D baru
// x: parameter input passing by value, tipe int, mewakili koordinat x dari vektor
// y: parameter input passing by value, tipe int, mewakili koordinat y dari vektor
// Mengembalikan vektor baru dengan koordinat (x, y) bertipe Vector2
Vector2 vector2_create(int x, int y);

// Fungsi untuk membandingkan dua vektor
// a: parameter input passing by value, tipe Vector2, vektor pertama untuk dibandingkan
// b: parameter input passing by value, tipe Vector2, vektor kedua untuk dibandingkan
// Mengembalikan true jika kedua vektor sama, false jika tidak
bool vector2_equals(Vector2 a, Vector2 b);

// Fungsi untuk menjumlahkan dua vektor
// a: parameter input passing by value, tipe Vector2, vektor pertama
// b: parameter input passing by value, tipe Vector2, vektor kedua
// Mengembalikan hasil penjumlahan kedua vektor bertipe Vector2
Vector2 vector2_add(Vector2 a, Vector2 b);

// Fungsi untuk memeriksa apakah posisi berada dalam batas layar
// pos: parameter input passing by value, tipe Vector2, posisi yang akan diperiksa
// width: parameter input passing by value, tipe int, lebar layar
// height: parameter input passing by value, tipe int, tinggi layar
// Mengembalikan true jika posisi dalam batas, false jika tidak
bool vector2_is_in_bounds(Vector2 pos, int width, int height);

#endif // VECTOR_H