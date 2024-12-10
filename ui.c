// Nama Program : ui.c
// Deskripsi    : Implementasi tampilan dan interaksi pengguna dalam permainan snake,
//                bertujuan mengimplementasikan rendering grafis dan penanganan input pemain
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#include <string.h>
#include <time.h>
#include <curses.h>
#include "ui.h"

char buffer[100]; // Buffer untuk menyimpan text sementara

// Prosedur untuk menginisialisasi antarmuka pengguna (UI)
// Mengatur tampilan, warna, dan pengaturan awal untuk tampilan permainan.
void initialize_ui()
{
  // Atur seed acak
  srand(time(NULL));

  // Inisialisasi curses
  initscr();             // Inisialisasi & mengaktifkan tampilan curses
  cbreak();              // Mengaktifkan mode cbreak, yang memungkinkan input karakter tanpa menunggu enter
  noecho();              // Menonaktifkan echo input, sehingga karakter yang dimasukkan tidak ditampilkan
  keypad(stdscr, TRUE);  // Mengaktifkan pengenalan tombol khusus (cth. arrow key)
  curs_set(0);           // Menyembunyikan kursor
  nodelay(stdscr, TRUE); // Mengatur input non-blocking, sehingga getch() tidak menunggu input

  // Inisialisasi warna
  if (has_colors() == FALSE)
  {
    endwin();                                            // Mengakhiri mode curses jika terminal tidak mendukung warna
    fprintf(stderr, "Terminal tidak mendukung warna\n"); // Menampilkan pesan kesalahan
    exit(1);                                             // Keluar dari program dengan status kesalahan
  }
  // Inisialisasi warna
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);    // Makanan warna merah
  init_pair(2, COLOR_GREEN, COLOR_BLACK);  // Ular warna hijau
  init_pair(3, COLOR_YELLOW, COLOR_BLACK); // Border warna kuning
}

// Prosedur untuk menampilkan judul game dengan ascii art
void show_title()
{
  attron(COLOR_PAIR(2)); // beri warna hijau
  mvprintw(2, 10, " _____                _           _____                         ");
  mvprintw(3, 10, "/  ___|              | |         |  __ \\                        ");
  mvprintw(4, 10, "\\ `--.  _ __    __ _ | | __ ___  | |  \\/  __ _  _ __ ___    ___ ");
  mvprintw(5, 10, " `--. \\| '_ \\  / _` || |/ // _ \\ | | __  / _` || '_ ` _ \\  / _ \\");
  mvprintw(6, 10, "/\\__/ /| | | || (_| ||   <|  __/ | |_\\ \\| (_| || | | | | ||  __/");
  mvprintw(7, 10, "\\____/ |_| |_| \\__,_||_|\\_\\\\___|  \\____/ \\__,_||_| |_| |_| \\___|");
  attroff(COLOR_PAIR(2)); // hapus warna hijau
}

// Prosedur untuk menampilkan menu utama permainan
// game_data: parameter input/output passing by reference, menunjuk ke objek GameData yang menyimpan data permainan
void show_menu(GameData *game_data)
{
  int choice; // Variabel untuk menyimpan pilihan pengguna
  do
  {
    erase(); // Bersihkan layar

    show_title();

    // tampilkan hi-score saat ini
    sprintf(buffer, "Hi-Score: %d | %s", game_data->hi_score.score, game_data->hi_score.player_name);
    mvprintw(9, 54, buffer);

    attron(COLOR_PAIR(3)); // beri warna kuning
    mvprintw(9, 10, "=== Menu ===");
    mvprintw(11, 10, "1. Main");
    sprintf(buffer, "2. Atur Level (Level: %d)", game_data->settings.level); // menampilkan level saat ini
    mvprintw(12, 10, buffer);
    mvprintw(13, 10, "3. Keluar");
    mvprintw(15, 10, "Pilih opsi (1-3): ");

    choice = getch(); // Ambil input dari pengguna

    switch (choice)
    {
    case '1':
      return; // Kembali ke permainan
    case '2':
      // Panggil fungsi untuk mengatur level
      set_game_level(game_data);
      break;
    case '3':
      quit_game(); // Keluar dari permainan
      break;
    }
  } while (1);
  attroff(COLOR_PAIR(3)); // hapus warna kuning
}

// Prosedur untuk mengatur level permainan
// game_data: parameter input/output passing by reference, menunjuk ke objek GameData yang menyimpan data permainan
void set_game_level(GameData *game_data)
{
  int level_choice; // Variabel untuk menyimpan pilihan pengguna
  do
  {
    erase(); // Bersihkan layar

    show_title();

    attron(COLOR_PAIR(3));
    mvprintw(9, 10, "=== Atur Level ===");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(2));
    mvprintw(11, 10, "1. Level 1");
    mvprintw(12, 10, "2. Level 2 (Default)");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(3));
    mvprintw(13, 10, "3. Level 3");
    mvprintw(14, 10, "4. Level 4");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(1));
    mvprintw(15, 10, "5. Level 5");
    attroff(COLOR_PAIR(1));
    mvprintw(16, 10, "6. Kembali");
    mvprintw(18, 10, "Pilih opsi (1-6): ");
    refresh();

    level_choice = getch(); // Ambil input dari pengguna

    switch (level_choice)
    {
    case '1':
      update_settings(&game_data->settings, 1, SPEED_1); // Level 1
      return;
    case '2':
      update_settings(&game_data->settings, 2, SPEED_2); // Level 2 (default)
      return;
    case '3':
      update_settings(&game_data->settings, 3, SPEED_3); // Level 3
      return;
    case '4':
      update_settings(&game_data->settings, 4, SPEED_4); // Level 4
      return;
    case '5':
      update_settings(&game_data->settings, 5, SPEED_5); // Level 5
      return;
    case '6':
      return;
    }
  } while (1);
}

// Prosedur untuk merender tampilan permainan
// game: parameter input, menunjuk ke objek Game yang akan dirender
// Menggambar elemen-elemen permainan seperti ular, makanan, skor, dan batas layar.
void render_ui(Game *game)
{
  erase(); // Bersihkan layar

  // Buat border
  attron(COLOR_PAIR(3));                                      // Menggunakan warna border (kuning)
  draw_border(0, 0, game->screen_width, game->screen_height); // Gambar border
  attroff(COLOR_PAIR(3));                                     // Menonaktifkan kembali warna border (kuning)

  // Gambar makanan
  attron(COLOR_PAIR(1)); // Menggunakan warna makanan (merah)
  // Gambar makanan berdasarkan posisi dengan karakter '@'
  mvaddch(game->game_food.position.y + 1,
          game->game_food.position.x * 2 + 1,
          '@');
  attroff(COLOR_PAIR(1)); // Menonaktifkan kembali warna makanan (merah)

  // Gambar badan/segmen ular
  attron(COLOR_PAIR(2));                            // Menggunakan warna ular (hijau)
  for (int i = 0; i < game->game_snake.length; i++) // Gambar segmen ular
  {
    // Gambar segmen ular berdasarkan posisi dengan karakter 'o'
    mvaddch(game->game_snake.segments[i].y + 1,
            game->game_snake.segments[i].x * 2 + 1,
            'o');
  }

  // Gambar kepala ular berdasarkan posisi dan karakter berdasarkan arah pergerakan ular `get_snake_head_symbol`
  mvaddch(game->game_snake.head.y + 1,
          game->game_snake.head.x * 2 + 1,
          get_snake_head_symbol(&game->game_snake));
  attroff(COLOR_PAIR(2)); // Menonaktifkan kembali warna ular (hijau)

  // Tampilkan skor
  sprintf(buffer, " Score: %d ", game->current_score.score);
  mvaddstr(0, game->screen_width - (strlen(buffer) / 2), buffer); // tampilkan skor di tengah atas

  // Tampilkan hi-score
  sprintf(buffer, " Hi-Score: %d | %s ", game->hi_score.score, game->hi_score.player_name);
  mvaddstr(game->screen_height + 1, 2, buffer); // tampilkan hi-score di kiri bawah

  // Tampilkan level saat ini
  sprintf(buffer, " Level: %d ", game->settings.level);
  mvaddstr(game->screen_height + 1, game->screen_width * 2 - 10, buffer); // tampilkan level di kanan bawah
}

// Prosedur untuk menggambar batas layar
// y: posisi y dari batas
// x: posisi x dari batas
// width: lebar batas
// height: tinggi batas
// Menggambar batas permainan di layar.
void draw_border(int y, int x, int width, int height)
{
  // Sudut kiri atas
  mvaddch(y, x, ACS_ULCORNER);

  // Sudut kanan atas
  mvaddch(y, x + width * 2 + 1, ACS_URCORNER);

  // Border atas
  for (int i = 1; i < width * 2 + 1; i++)
  {
    mvaddch(y, x + i, ACS_HLINE);
  }

  // Border samping kiri dan kanan
  for (int i = 1; i < height + 1; i++)
  {
    mvaddch(y + i, x, ACS_VLINE);
    mvaddch(y + i, x + width * 2 + 1, ACS_VLINE);
  }

  // Sudut kiri bawah
  mvaddch(y + height + 1, x, ACS_LLCORNER);

  // Sudut kanan bawah
  mvaddch(y + height + 1, x + width * 2 + 1, ACS_LRCORNER);

  // Border bawah
  for (int i = 1; i < width * 2 + 1; i++)
  {
    mvaddch(y + height + 1, x + i, ACS_HLINE);
  }
}

// Prosedur untuk menampilkan tampilan game over atau paused
// game: parameter input, menunjuk ke objek Game yang akan ditampilkan
// Menampilkan pesan game over atau kemenangan, serta instruksi untuk memulai ulang permainan.
void show_game_over_ui(Game *game)
{
  // Tampilkan pesan game over
  attron(COLOR_PAIR(3));

  if (game->game_snake.length >= MAX_SNAKE_LENGTH)
  {
    // Pesan kemenangan di tengah layar
    mvaddstr(game->screen_height / 2,
             game->screen_width - 10,
             "  Selamat! Anda Menang!  ");
    mvaddstr(game->screen_height / 2 + 1,
             game->screen_width - 11,
             "Tekan SPACE untuk main ulang");
    mvaddstr(game->screen_height / 2 + 2,
             game->screen_width - 14,
             "Tekan ENTER untuk kembali ke menu");
    mvaddstr(game->screen_height / 2 + 3,
             game->screen_width - 8,
             "Tekan ESC untuk keluar");
  }
  else
  {
    if (game->is_pause) // tampilkan pesan berbeda jika pause
    {
      mvaddstr(game->screen_height / 2,
               game->screen_width - 10,
               "         Paused         ");
      mvaddstr(game->screen_height / 2 + 1,
               game->screen_width - 16,
               "Tekan SPACE untuk melanjutkan (resume)");
    }
    else // Pesan game over
    {
      mvaddstr(game->screen_height / 2,
               game->screen_width - 10,
               "        Game Over        ");
      mvaddstr(game->screen_height / 2 + 1,
               game->screen_width - 10,
               "Tekan SPACE untuk restart");
    }

    // tampilkan instruksi untuk pergi ke menu atau keluar
    mvaddstr(game->screen_height / 2 + 2,
             game->screen_width - 14,
             "Tekan ENTER untuk kembali ke menu");
    mvaddstr(game->screen_height / 2 + 3,
             game->screen_width - 8,
             "Tekan ESC untuk keluar");
  }
}

// Prosedur untuk menampilkan dan mengambil input nama player
// game: parameter input/output passing by reference, menunjuk ke objek Game yang akan diperbarui berdasarkan input
void get_player_name(Game *game)
{
  char player_name[50];                            // Buffer untuk menyimpan nama pemain
                                                   //
  attron(COLOR_PAIR(2));                           // Menggunakan warna hijau
  mvaddstr(game->screen_height / 2 - 1,            // Tampilkan prompt
           game->screen_width - 10,                //
           "  Skor Tertinggi Baru!  ");            //
  mvaddstr(game->screen_height / 2,                // Tampilkan prompt
           game->screen_width - 10,                //
           "  Masukkan nama anda : ");             //
                                                   //
  echo();                                          // Aktifkan echo untuk menampilkan input
  mvgetnstr(game->screen_height / 2 + 1,           // Ambil input nama pemain
            game->screen_width - 8,                //
            player_name, sizeof(player_name) - 1); //
  attroff(COLOR_PAIR(2));                          // Nonaktifkan warna hijau
  noecho();                                        // Nonaktifkan echo setelah input

  // Simpan nama pemain ke score
  strcpy(game->current_score.player_name, player_name);
  erase(); // bersihkan layar
}

// Prosedur untuk menangani input dari pengguna selama dalam permainan
// game: parameter input/output passing by reference, menunjuk ke objek Game yang akan diperbarui berdasarkan input
// game_data: parameter input/output passing by reference, menunjuk ke objek GameData yang menyimpan data permainan
void ui_handle_input(Game *game, GameData *game_data)
{
  int ch = getch(); // Mendapatkan input

  switch (ch)
  {
  case KEY_LEFT:
    game_handle_input(game, vector2_create(-1, 0)); // Arahkan ular ke kiri
    break;
  case KEY_RIGHT:
    game_handle_input(game, vector2_create(1, 0)); // Arahkan ular ke kanan
    break;
  case KEY_UP:
    game_handle_input(game, vector2_create(0, -1)); // Arahkan ular ke atas
    break;
  case KEY_DOWN:
    game_handle_input(game, vector2_create(0, 1)); // Arahkan ular ke bawah
    break;
  case ' ':                // spasi
    if (!game->is_running) // restart game ketika game over
      game_restart(game, game_data);
    else if (game->is_pause) // resume game ketika pause
      game->is_pause = false;
    break;
  case '\n': // enter untuk ke menu
    if (!game->is_running || game->is_pause)
    {
      show_menu(game_data);
      game_restart(game, game_data); // restart game setelah dari menu (jika tidak quit)
    }
    break;
  case 27:                                   // ESC key
    if (!game->is_running || game->is_pause) // quit ketika game sedang tidak berjalan (game over atau pause)
      quit_game();
    else // pause ketika game sedang berjalan
      game->is_pause = true;
  }
}

// Prosedur untuk keluar dari permainan
// Menghentikan antarmuka pengguna dan membersihkan layar sebelum keluar dari program.
void quit_game()
{
  endwin(); // Mengakhiri mode curses, mengembalikan terminal ke mode normal

  printf("\e[1;1H\e[2J"); // Mengatur kursor ke posisi (1,1) dan membersihkan layar terminal
  printf("\e[?25h");      // Menampilkan kursor kembali setelah keluar dari mode curses

  exit(0); // Keluar dari program dengan status sukses
}