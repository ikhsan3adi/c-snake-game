// Nama Program : main.c
// Deskripsi    : Program Permainan Snake
//                Mengimplementasikan permainan klasik snake
//                dengan kontrol menggunakan keyboard dan tampilan console
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#include <unistd.h>
#include "game.h"
#include "gamedata.h"
#include "ui.h"

#define SCREEN_WIDTH 50           // lebar default area permainan
#define SCREEN_HEIGHT 30          // tinggi default area permainan
#define GAME_DATA_FILE "data.dat" // nama file tempat menyimpan data permainan

int main(int argc, char *argv[])
{
  // Kamus data
  GameData game_data; // variabel untuk menyimpan data permainan
  Game game;          // variabel untuk menyimpan state permainan

  // Inisialisasi dimensi layar
  int screen_width = SCREEN_WIDTH;
  int screen_height = SCREEN_HEIGHT;

  // Inisialisasi UI
  initialize_ui();

  // Muat data permainan dari file
  game_data = load_game_data(GAME_DATA_FILE);

  // Tampilkan menu
  show_menu(&game_data);

  // Buat permainan
  game = game_create(screen_width, screen_height, &game_data);

  // Loop utama permainan
  while (game.is_running)
  {
    // Tangani input
    ui_handle_input(&game, NULL);

    // Perbarui logika permainan, update Game state
    game_update(&game);

    // Render tampilan berdasarkan state game
    render_ui(&game);

    // Tampilkan tampilan game over/pause jika tidak sedang berjalan
    if (!game.is_running || game.is_pause)
    {
      // Cek apakah skor saat ini melebihi hi-score (kecuali pause)
      if (game.current_score.score > game.hi_score.score && !game.is_pause)
      {
        get_player_name(&game);                                   // ambil dan assign nama pemain ke game score
        set_game_hi_score(&game, &game_data, game.current_score); // perbarui hi-score
      }

      // simpan data game terbaru
      save_game_data(GAME_DATA_FILE, &game_data);

      show_game_over_ui(&game);                 // Tampilkan UI game over
      while (!game.is_running || game.is_pause) // Menunggu input
      {
        ui_handle_input(&game, &game_data);
      }
    }

    // Tunda untuk mengontrol kecepatan permainan
    usleep(game_data.settings.speed);
  }

  quit_game();

  return 0;
}