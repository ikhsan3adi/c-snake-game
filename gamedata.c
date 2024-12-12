// Nama Program : gamedata.c
// Deskripsi    : Implementasi logika penyimpanan dan pemuatan data permainan,
//                bertujuan untuk menyimpan dan memuat data permainan ke dan dari file biner.
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#include <stdio.h>
#include <string.h>
#include "gamedata.h"

// Prosedur untuk menyimpan data permainan ke file biner
// filename: parameter input passing by value, tipe const char*, nama file untuk menyimpan data
// game_data: parameter input passing by reference, tipe GameData*, pointer ke objek GameData yang akan disimpan
void save_game_data(const char *filename, GameData *game_data)
{
  FILE *file = fopen(filename, "wb"); // Membuka file dalam mode write binary
  if (file != NULL)
  {
    fwrite(game_data, sizeof(GameData), 1, file); // Menyimpan objek GameData ke file
  }
  fclose(file);
}

// Fungsi untuk memuat data permainan dari file biner
// filename: parameter input passing by value, tipe const char*, nama file untuk dimuat datanya
// Mengembalikan GameData dari file atau GameData dengan nilai default
GameData load_game_data(const char *filename)
{
  // kamus
  GameData game_data; // tempat menyimpan data game dari file

  FILE *file = fopen(filename, "rb"); // Membuka file dalam mode read binary
  if (file != NULL)
  {
    fread(&game_data, sizeof(GameData), 1, file); // Memuat objek GameData dari file
  }
  else
  {
    // Jika file tidak ada, set nilai default
    strcpy(game_data.hi_score.player_name, "Unknown");
    game_data.hi_score.score = 0;
    game_data.settings.level = 2;
    game_data.settings.speed = SPEED_2;
  }
  fclose(file);
  return game_data;
}

// Prosedur untuk menghapus data permainan
// filename: parameter input passing by value, tipe const char*, nama file untuk dihapus
void delete_game_data(const char *filename)
{
  // Menghapus file dengan nama yang diberikan
  remove(filename);
}
