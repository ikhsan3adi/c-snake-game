// Nama Program : ui.c
// Deskripsi    : Implementasi tampilan dan interaksi pengguna dalam permainan snake,
//                bertujuan mengimplementasikan rendering grafis dan penanganan input pemain
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#include "ui.h"
#include <string.h>

char scoreText[20];

void initialize_ui()
{
  // Inisialisasi curses
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  nodelay(stdscr, TRUE);

  // Inisialisasi warna
  if (has_colors() == FALSE)
  {
    endwin();
    fprintf(stderr, "Terminal tidak mendukung warna\n");
    exit(1);
  }
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);    // Makanan
  init_pair(2, COLOR_GREEN, COLOR_BLACK);  // Ular
  init_pair(3, COLOR_YELLOW, COLOR_BLACK); // Border
}

void render_ui(Game *game)
{
  erase();

  // Gambar border
  attron(COLOR_PAIR(3));
  draw_border(0, 0, game->screen_width, game->screen_height);
  attroff(COLOR_PAIR(3));

  // Gambar makanan
  attron(COLOR_PAIR(1));
  mvaddch(game->game_food.position.y + 1,
          game->game_food.position.x * 2 + 1,
          '@');
  attroff(COLOR_PAIR(1));

  attron(COLOR_PAIR(2));

  // Gambar badan/segmen ular
  for (int i = 0; i < game->game_snake.length; i++)
  {
    mvaddch(game->game_snake.segments[i].y + 1,
            game->game_snake.segments[i].x * 2 + 1,
            'o');
  }

  // Gambar kepala ular
  mvaddch(game->game_snake.head.y + 1,
          game->game_snake.head.x * 2 + 1,
          get_snake_head_symbol(&game->game_snake));
  attroff(COLOR_PAIR(2));

  // Tampilkan skor
  sprintf(scoreText, "Score: %d", game->score);
  mvaddstr(0, game->screen_width - strlen(scoreText), scoreText);
}

void draw_border(int y, int x, int width, int height)
{
  // Top border
  mvaddch(y, x, ACS_ULCORNER);
  mvaddch(y, x + width * 2 + 1, ACS_URCORNER);
  for (int i = 1; i < width * 2 + 1; i++)
  {
    mvaddch(y, x + i, ACS_HLINE);
  }

  // Side borders
  for (int i = 1; i < height + 1; i++)
  {
    mvaddch(y + i, x, ACS_VLINE);
    mvaddch(y + i, x + width * 2 + 1, ACS_VLINE);
  }

  // Bottom border
  mvaddch(y + height + 1, x, ACS_LLCORNER);
  mvaddch(y + height + 1, x + width * 2 + 1, ACS_LRCORNER);
  for (int i = 1; i < width * 2 + 1; i++)
  {
    mvaddch(y + height + 1, x + i, ACS_HLINE);
  }
}

void show_game_over_ui(Game *game)
{
  // Tampilkan pesan game over
  attron(COLOR_PAIR(3));

  if (game->game_snake.length >= MAX_SNAKE_LENGTH)
  {
    // Pesan kemenangan
    mvaddstr(game->screen_height / 2,
             game->screen_width - 20,
             "     Selamat! Anda Menang!     ");
    mvaddstr(game->screen_height / 2 + 1,
             game->screen_width - 20,
             "Tekan SPACE untuk main ulang");
  }
  else
  {
    // Pesan game over
    mvaddstr(game->screen_height / 2,
             game->screen_width - 16,
             "        Game Over        ");
    mvaddstr(game->screen_height / 2 + 1,
             game->screen_width - 16,
             "Tekan SPACE untuk restart");
  }
}

int ui_handle_input(Game *game)
{
  int ch = wgetch(stdscr); // Mendapatkan input

  switch (ch)
  {
  case KEY_LEFT:
    game_handle_input(game, vector2_create(-1, 0));
    break;
  case KEY_RIGHT:
    game_handle_input(game, vector2_create(1, 0));
    break;
  case KEY_UP:
    game_handle_input(game, vector2_create(0, -1));
    break;
  case KEY_DOWN:
    game_handle_input(game, vector2_create(0, 1));
    break;
  case ' ':
    if (!game->is_running)
      game_restart(game);
    break;
  case 27: // ESC key
    if (!game->is_running)
      quit_game();
  }

  return 0;
}

void quit_game()
{
  endwin();

  printf("\e[1;1H\e[2J");
  printf("\e[?25h");

  exit(0);
}