// Nama Program : main.c
// Deskripsi    : Program Permainan Snake
//                Mengimplementasikan permainan klasik snake
//                dengan kontrol menggunakan keyboard dan tampilan console
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <curses.h>
#include "game.h"
#include "ui.h"

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 30
#define FRAME_DELAY 110000 // 110 ms

int main(int argc, char *argv[])
{
  // Atur seed acak
  srand(time(NULL));

  // Inisialisasi dimensi layar
  int screen_width = SCREEN_WIDTH;
  int screen_height = SCREEN_HEIGHT;

  // Inisialisasi UI
  initialize_ui();

  // Buat permainan
  Game game = game_create(screen_width, screen_height);

  // Loop utama permainan
  while (game.is_running)
  {
    // Tangani input
    ui_handle_input(&game);

    // Perbarui logika permainan
    game_update(&game);

    // Render
    render_ui(&game);

    // Tampilkan tampilan game over jika tidak sedang berjalan
    if (!game.is_running)
    {
      show_game_over_ui(&game);
      while (!game.is_running) // Menunggu input
      {
        ui_handle_input(&game);
      }
    }

    // Tunda untuk mengontrol kecepatan permainan
    usleep(FRAME_DELAY);
  }

  quit_game();

  return 0;
}