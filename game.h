// Nama Program : game.h
// Deskripsi    : Header file untuk logika utama permainan,
//                mendefinisikan struktur Game dan fungsi-fungsi untuk mengelola permainan.
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

/**
 * Fungsi untuk membuat objek permainan baru
 * @param screen_width lebar layar
 * @param screen_height tinggi layar
 * @param game_data menunjuk ke objek GameData yang menyimpan data permainan
 * @return objek permainan baru bertipe Game
 */
Game game_create(int screen_width, int screen_height, GameData *game_data);

/**
 * Prosedur untuk mengubah hi_score di game dan game_data
 * @param game menunjuk ke objek permainan yang akan diperbarui
 * @param game_data menunjuk ke objek data permainan yang akan diperbarui
 * @param current_score skor saat ini
 */
void set_game_hi_score(Game *game, GameData *game_data, Score current_score);

/**
 * Prosedur untuk memperbarui leaderboard
 * @param game menunjuk ke objek permainan yang akan diperbarui
 * @param game_data menunjuk ke objek data permainan yang akan diperbarui
 * @param current_score skor saat ini
 * @param rank_index lokasi index di leaderboard untuk skor baru
 */
void update_leaderboard(Game *game, GameData *game_data, Score current_score, int rank_index);

/**
 * Fungsi untuk mengecek apakah skor dapat masuk ke leaderboard
 * @param game_data menunjuk ke objek data permainan
 * @param current_score skor saat ini
 * @return index peringkat jika masuk leaderboard, -1 jika tidak masuk leaderboard
 */
int in_leaderboard(GameData *game_data, Score current_score);

/**
 * Prosedur untuk memperbarui logika permainan
 * @param game menunjuk ke objek permainan yang akan diperbarui
 */
void game_update(Game *game);

/**
 * Fungsi untuk memeriksa apakah permainan telah berakhir (ular menabrak tembok atau ular itu sendiri)
 * @param game menunjuk ke objek permainan yang akan diperiksa
 * @return true jika permainan berakhir, false jika tidak
 */
bool is_game_over(Game *game);

/**
 * Prosedur untuk merestart permainan
 * @param game menunjuk ke objek permainan yang akan direset
 * @param game_data menunjuk ke objek data permainan
 */
void game_restart(Game *game, GameData *game_data);

/**
 * Prosedur untuk menangani input dari pengguna untuk mengubah arah pergerakan ular
 * @param game menunjuk ke objek permainan yang akan diperbarui berdasarkan input
 * @param new_dir arah baru untuk ular
 */
void game_handle_input(Game *game, Vector2 new_dir);

#endif // GAME_H