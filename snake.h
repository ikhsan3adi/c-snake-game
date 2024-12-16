// Nama Program : snake.h
// Deskripsi    : Deklarasi struktur dan fungsi untuk manajemen ular dalam permainan,
//                bertujuan mendefinisikan struktur data dan antarmuka untuk mengontrol perilaku ular
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#ifndef SNAKE_H
#define SNAKE_H

#include <stdbool.h>
#include "vector.h"

// Definisi maksimum panjang ular sekaligus maksimum skor
#define MAX_SNAKE_LENGTH 256

// Struktur untuk merepresentasikan objek ular dalam permainan
typedef struct
{
  Vector2 head;                       // Posisi kepala ular
  Vector2 segments[MAX_SNAKE_LENGTH]; // Array untuk menyimpan posisi segmen-segmen tubuh ular
  int length;                         // Panjang ular (jumlah segmen)
  Vector2 direction;                  // Arah gerakan ular
} Snake;

// Fungsi untuk membuat ular baru
// start_x: posisi awal x dari kepala ular
// start_y: posisi awal y dari kepala ular
// Mengembalikan objek ular baru bertipe Snake
Snake create_snake(int start_x, int start_y);

// Prosedur untuk menggerakkan ular
// snake: parameter input/output passing by reference, menunjuk ke objek ular yang akan diperbarui
void snake_move(Snake *snake);

// Fungsi untuk memeriksa apakah ular bertabrakan dengan dirinya sendiri
// snake: parameter input passing by reference, menunjuk ke objek ular yang akan diperiksa
// Mengembalikan true jika ular bertabrakan dengan dirinya sendiri, false jika tidak
bool snake_collides_with_self(Snake *snake);

// Prosedur untuk menumbuhkan ular
// snake: parameter output passing by reference, menunjuk ke objek ular yang akan diperbarui
void snake_grow(Snake *snake);

// Fungsi untuk mendapatkan simbol yang merepresentasikan kepala ular berdasarkan arah gerakan
// snake: parameter input passing, menunjuk ke objek ular yang akan diperiksa
// Mengembalikan karakter yang merepresentasikan kepala ular ('>', '<', 'v', '^')
char get_snake_head_symbol(Snake *snake);

// Prosedur untuk mengubah arah gerakan ular
// snake: parameter input/output passing by reference, menunjuk ke objek ular yang akan diperbarui
// new_direction: arah baru untuk ular, bertipe Vector2
void snake_change_direction(Snake *snake, Vector2 new_direction);

#endif // SNAKE_H