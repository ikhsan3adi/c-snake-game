// Nama Program : game.h
// Deskripsi    : Deklarasi struktur dan fungsi utama untuk logika permainan snake,
//                bertujuan merancang kerangka utama permainan dan menentukan alur permainan
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"
#include "vector.h"
#include <stdbool.h>

// Struktur untuk merepresentasikan status permainan secara keseluruhan
typedef struct
{
  Snake game_snake;  // Ular
  Food game_food;    // Makanan
  int score;         // Skor saat ini
  bool is_running;   // Status permainan
  int screen_width;  // Lebar layar
  int screen_height; // Tinggi layar
} Game;

// Fungsi untuk membuat objek permainan baru
// screen_width: parameter input passing by value, tipe int, lebar layar
// screen_height: parameter input passing by value, tipe int, tinggi layar
// Mengembalikan objek permainan baru bertipe Game
Game game_create(int screen_width, int screen_height);

// Prosedur untuk memperbarui logika permainan
// game: parameter input/output passing by reference, tipe Game*, menunjuk ke objek permainan yang akan diperbarui
void game_update(Game *game);

// Fungsi untuk memeriksa apakah permainan telah berakhir
// game: parameter input passing by reference, tipe Game*, menunjuk ke objek permainan yang akan diperiksa
// Mengembalikan true jika permainan berakhir, false jika tidak
bool is_game_over(Game *game);

// Prosedur untuk merestart permainan
// game: parameter input/output passing by reference, tipe Game*, menunjuk ke objek permainan yang akan direset
void game_restart(Game *game);

// Prosedur untuk menangani input dari pengguna
// game: parameter input/output passing by reference, tipe Game*, menunjuk ke objek permainan yang akan diperbarui berdasarkan input
// new_dir: parameter input passing by value, tipe Vector2, arah baru untuk ular
void game_handle_input(Game *game, Vector2 new_dir);

#endif // GAME_H