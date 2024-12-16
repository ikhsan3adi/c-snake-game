// Nama Program : game.h
// Deskripsi    : Deklarasi struktur dan fungsi utama untuk logika permainan snake,
//                bertujuan merancang kerangka utama permainan dan menentukan alur permainan
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"
#include "vector.h"
#include "gamedata.h"
#include <stdbool.h>

// Struktur untuk merepresentasikan status permainan secara keseluruhan
typedef struct
{
  Snake game_snake;    // Ular
  Food game_food;      // Makanan
  Score current_score; // Skor saat ini
  Score hi_score;      // Skor tertinggi saat ini
  Settings settings;   // Pengaturan game
  bool is_running;     // Status permainan (game over)
  bool is_pause;       // Status permainan (pause)
  bool is_winning;     // Status permainan (menang)
  int screen_width;    // Lebar layar
  int screen_height;   // Tinggi layar
} Game;

// Fungsi untuk membuat objek permainan baru
// screen_width: parameter input passing by value, tipe int, lebar layar
// screen_height: parameter input passing by value, tipe int, tinggi layar
// game_data: parameter input passing by reference, tipe GameData, data permainan
// Mengembalikan objek permainan baru bertipe Game
Game game_create(int screen_width, int screen_height, GameData *game_data);

// Prosedur untuk mengubah hi_score
// game: parameter output passing by reference, tipe Game*, menunjuk ke objek permainan yang akan diperbarui
// game_data: parameter output passing by reference, tipe GameData*, menunjuk ke objek data permainan yang akan diperbarui
// current_score: parameter input passing by value, tipe Score
void set_game_hi_score(Game *game, GameData *game_data, Score current_score);

// Prosedur untuk memperbarui leaderboard
// game: parameter output passing by reference, tipe Game*, menunjuk ke objek permainan yang akan diperbarui
// game_data: parameter output passing by reference, tipe GameData*, menunjuk ke objek data permainan yang akan diperbarui
// current_score: parameter input passing by value, tipe Score
// rank_index: parameter input passing by value, tipe int, lokasi index di leaderboard untuk skor baru
void update_leaderboard(Game *game, GameData *game_data, Score current_score, int rank_index);

// Fungsi untuk mengecek apakah skor dapat masuk ke leaderboard
// game_data: parameter output passing by reference, tipe GameData*, menunjuk ke objek data permainan
// current_score: parameter input passing by value, tipe Score, skor saat ini
// Mengembalikan peringkat baru di leaderboard, -1 jika tidak masuk leaderboard
int in_leaderboard(GameData *game_data, Score current_score);

// Prosedur untuk memperbarui logika permainan
// game: parameter input/output passing by reference, tipe Game*, menunjuk ke objek permainan yang akan diperbarui
void game_update(Game *game);

// Fungsi untuk memeriksa apakah permainan telah berakhir (ular menabrak tembok atau ular itu sendiri)
// game: parameter input passing by reference, tipe Game*, menunjuk ke objek permainan yang akan diperiksa
// Mengembalikan true jika permainan berakhir, false jika tidak
bool is_game_over(Game *game);

// Prosedur untuk merestart permainan
// game: parameter input/output passing by reference, tipe Game*, menunjuk ke objek permainan yang akan direset
// game_data: parameter output passing by reference, tipe GameData*, menunjuk ke objek data permainan
void game_restart(Game *game, GameData *game_data);

// Prosedur untuk menangani input dari pengguna untuk mengubah arah pergerakan ular
// game: parameter input/output passing by reference, tipe Game*, menunjuk ke objek permainan yang akan diperbarui berdasarkan input
// new_dir: parameter input passing by value, tipe Vector2, arah baru untuk ular
void game_handle_input(Game *game, Vector2 new_dir);

#endif // GAME_H