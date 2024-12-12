// Nama Program : vector.c
// Deskripsi    : Implementasi fungsi-fungsi manipulasi vector untuk mendukung representasi
//                dan perhitungan koordinat dalam permainan.
//                Bertujuan mengimplementasikan operasi dasar vector dalam permainan.
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#include "vector.h"

// Fungsi untuk membuat vektor 2D baru
// x: parameter input passing by value, tipe int, mewakili koordinat x dari vektor
// y: parameter input passing by value, tipe int, mewakili koordinat y dari vektor
// Mengembalikan vektor baru dengan koordinat (x, y) bertipe Vector2
Vector2 vector2_create(int x, int y)
{
  Vector2 vec = {x, y}; // Inisialisasi vektor baru dengan koordinat (x, y)
  return vec;
}

// Fungsi untuk membandingkan dua vektor
// a: parameter input passing by value, tipe Vector2, vektor pertama untuk dibandingkan
// b: parameter input passing by value, tipe Vector2, vektor kedua untuk dibandingkan
// Mengembalikan true jika kedua vektor sama, false jika tidak
bool vector2_equals(Vector2 a, Vector2 b)
{
  return a.x == b.x && a.y == b.y;
}

// Fungsi untuk menjumlahkan dua vektor
// a: parameter input passing by value, tipe Vector2, vektor pertama
// b: parameter input passing by value, tipe Vector2, vektor kedua
// Mengembalikan hasil penjumlahan kedua vektor bertipe Vector2
Vector2 vector2_add(Vector2 a, Vector2 b)
{
  Vector2 vec = {a.x + b.x, a.y + b.y}; // Inisialisasi hasil penjumlahan dengan koordinat (a.x + b.x, a.y + b.y)
  return vec;
}

// Fungsi untuk memeriksa apakah posisi berada dalam batas layar
// pos: parameter input passing by value, tipe Vector2, posisi yang akan diperiksa
// width: parameter input passing by value, tipe int, lebar layar
// height: parameter input passing by value, tipe int, tinggi layar
// Mengembalikan true jika posisi dalam batas, false jika tidak
bool vector2_is_in_bounds(Vector2 pos, int width, int height)
{
  return pos.x >= 0 && pos.x < width &&
         pos.y >= 0 && pos.y < height;
}