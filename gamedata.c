// Nama Program : gamedata.c
// Deskripsi    : Implementasi logika penyimpanan dan pemuatan data permainan,
//                bertujuan untuk menyimpan dan memuat data permainan ke dan dari file biner.
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#include <stdio.h>
#include <string.h>
#include "gamedata.h"

void save_game_data(const char *filename, GameData *game_data)
{
  FILE *file = fopen(filename, "wb"); // Membuka file dalam mode write binary
  if (file != NULL)
  {
    fwrite(game_data, sizeof(GameData), 1, file); // Menyimpan objek GameData ke file
    fclose(file);
  }
}

GameData load_game_data(const char *filename)
{
  // kamus
  GameData game_data; // tempat menyimpan data game dari file

  FILE *file = fopen(filename, "rb"); // Membuka file dalam mode read binary
  if (file != NULL)
  {
    fread(&game_data, sizeof(GameData), 1, file); // Memuat objek GameData dari file
    fclose(file);
  }
  else
  {
    // Jika file tidak ada, set nilai default
    strcpy(game_data.hi_score.player_name, "Unknown");
    game_data.hi_score.score = 0;
    game_data.hi_score.level = 2;
    game_data.settings.level = 2;
    game_data.settings.speed = SPEED_2;

    // Inisialisasi leaderboard dengan nilai default
    for (int i = 0; i < MAX_LEADERBOARD_SIZE; i++)
    {
      strcpy(game_data.leaderboard[i].player_name, "Unknown");
      game_data.leaderboard[i].score = 0;
      game_data.leaderboard[i].level = 0;
      game_data.leaderboard[i].date = create_date(1900, 1, 1, 0, 0, 0);
    }
  }
  return game_data;
}

void delete_game_data(const char *filename)
{
  // Menghapus file dengan nama yang diberikan
  remove(filename);
}
