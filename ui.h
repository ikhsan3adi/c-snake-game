#ifndef UI_H
#define UI_H

#include <curses.h>
#include "game.h"

// Inisialisasi antarmuka
void initialize_ui();

// Render game
void render_ui(Game *game);

// Gambar border
void draw_border(int y, int x, int width, int height);

// Tampilkan layar game over
void show_game_over_ui(Game *game);

// Tangani input
int ui_handle_input(Game *game);

// Keluar dari permainan
void quit_game();

#endif