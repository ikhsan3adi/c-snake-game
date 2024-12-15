// Nama Program : gamedata.h
// Deskripsi    : Header file untuk pengelolaan data permainan,
//                mendefinisikan struktur GameData dan fungsi-fungsi untuk menyimpan,
//                memuat, dan menghapus data permainan.
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "score.h"
#include "settings.h"

#define MAX_LEADERBOARD_SIZE 10

// struct untuk menyimpan data permainan
typedef struct
{
  Score hi_score;                          // Data skor tertinggi
  Score leaderboard[MAX_LEADERBOARD_SIZE]; // Data leaderboard permainan
  Settings settings;                       // Data pengaturan
} GameData;

// Prosedur untuk menyimpan data permainan ke file biner
// filename: parameter input passing by value, tipe const char*, nama file untuk menyimpan data
// game_data: parameter input passing by reference, tipe GameData*, pointer ke objek GameData yang akan disimpan
void save_game_data(const char *filename, GameData *game_data);

// Fungsi untuk memuat data permainan dari file biner
// filename: parameter input passing by value, tipe const char*, nama file untuk dimuat datanya
// Mengembalikan GameData dari file atau GameData dengan nilai default
GameData load_game_data(const char *filename);

//! Prosedur untuk menghapus data permainan (belum dipakai)
// filename: parameter input passing by value, tipe const char*, nama file untuk dihapus
void delete_game_data(const char *filename);

#endif // GAMEDATA_H