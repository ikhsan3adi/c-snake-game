// Nama Program : ui.c
// Deskripsi    : Implementasi tampilan dan interaksi pengguna dalam permainan snake,
//                bertujuan mengimplementasikan rendering grafis dan penanganan input pemain
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curses.h>
#include "ui.h"

// Kamus data
char buffer[100]; // Buffer untuk menyimpan text sementara, variabel global

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

  // cek apakah terminal mendukung warna
  if (!has_colors())
  {
    endwin();                                            // Mengakhiri mode curses jika terminal tidak mendukung warna
    fprintf(stderr, "Terminal tidak mendukung warna\n"); // Menampilkan pesan kesalahan
    exit(1);                                             // Keluar dari program dengan status kesalahan
  }

  // Inisialisasi warna
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);    // warna merah, background hitam = 1
  init_pair(2, COLOR_GREEN, COLOR_BLACK);  // warna hijau, background hitam = 2
  init_pair(3, COLOR_YELLOW, COLOR_BLACK); // warna kuning, background hitam = 3
  init_pair(4, COLOR_CYAN, COLOR_BLACK);   // warna biru muda, background hitam = 4
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
  do
  {
    erase(); // Bersihkan layar

    show_title(); // Tampilkan judul

    // tampilkan hi-score saat ini
    mvprintw(9, 54, "Hi-Score: %d | %s", game_data->hi_score.score, game_data->hi_score.player_name);

    attron(COLOR_PAIR(3)); // beri warna kuning
    mvprintw(9, 10, "=== Menu ===");
    mvprintw(11, 10, "1. Main");
    mvprintw(12, 10, "2. Atur Level (Level: %d)", game_data->settings.level); // menampilkan level saat ini
    mvprintw(13, 10, "3. Leaderboard");
    mvprintw(14, 10, "4. Keluar");
    mvprintw(16, 10, "Pilih opsi (1-3): ");
    attroff(COLOR_PAIR(3)); // hapus warna kuning

    show_copyright(); // Tampilkan copyright

    switch (getch()) // Ambil input dari pengguna
    {
    case '1':
      return; // Kembali ke permainan
    case '2':
      // Panggil prosedur untuk mengatur level
      show_game_level_menu(game_data);
      break;
    case '3':
      // Panggil prosedur untuk melihat leaderboard
      // show_leaderboard();
      break;
    case '4':      // 4 untuk keluar
    case 27:       // ESC untuk keluar
      quit_game(); // Keluar dari permainan
      break;
    }
  } while (true);
}

// Prosedur untuk menampilkan pengaturan level permainan
// game_data: parameter input/output passing by reference, menunjuk ke objek GameData yang menyimpan data permainan
void show_game_level_menu(GameData *game_data)
{
  do
  {
    erase(); // Bersihkan layar

    show_title(); // Tampilkan judul

    attron(COLOR_PAIR(3)); // beri warna kuning
    mvprintw(9, 10, "=== Atur Level ===");
    attroff(COLOR_PAIR(3)); // hapus warna kuning
    attron(COLOR_PAIR(2));  // beri warna hijau
    mvprintw(11, 10, "1. Level 1");
    mvprintw(12, 10, "2. Level 2 (Default)");
    attroff(COLOR_PAIR(2)); // hapus warna hijau
    attron(COLOR_PAIR(3));  // beri warna kuning
    mvprintw(13, 10, "3. Level 3");
    mvprintw(14, 10, "4. Level 4");
    attroff(COLOR_PAIR(3)); // hapus warna kuning
    attron(COLOR_PAIR(1));  // beri warna merah
    mvprintw(15, 10, "5. Level 5");
    attroff(COLOR_PAIR(1)); // hapus warna merah
    mvprintw(16, 10, "6. Kembali");
    mvprintw(18, 10, "Pilih opsi (1-6): ");

    show_copyright(); // Tampilkan copyright

    // update level dan speed game berdasarkan pilihan pengguna
    switch (getch()) // Ambil input dari pengguna
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
    case '6': // kembali
      return;
    }
  } while (true);
}

// Prosedur untuk menampilkan nama pembuat dan kelompok
// Tampilkan kelompok, nama dan nim pembuat
void show_copyright()
{
  attron(COLOR_PAIR(4)); // beri warna biru
  mvprintw(25, 10, "By Kelompok 9:");
  mvprintw(26, 10, "Ikhsan Satriadi");
  mvprintw(26, 35, "241511080");
  mvprintw(27, 10, "Rizky Satria Gunawan");
  mvprintw(27, 35, "241511089");
  attroff(COLOR_PAIR(4)); // hapus warna biru
}

// Prosedur untuk merender tampilan permainan
// game: parameter input, menunjuk ke objek Game yang akan dirender
// Menggambar elemen-elemen permainan seperti ular, makanan, skor, dan batas layar.
void render_ui(Game *game)
{
  erase(); // Bersihkan layar

  // buat border
  draw_border(0, 0, game->screen_width, game->screen_height);

  // tampilkan makanan
  draw_food(game);

  // tampilkan ular
  draw_snake(game);

  // tampilkan skor saat ini
  show_in_game_score(game);

  // tampilkan hi-score(skor tertinggi) saat ini
  show_in_game_hi_score(game);

  // tampilkan level saat ini
  show_in_game_level(game);
}

// Prosedur untuk menampilkan panduan permainan sebelum dimulai
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void show_guides(Game *game)
{
  erase(); // Bersihkan layar

  // Buat border
  attron(COLOR_PAIR(3)); // Menggunakan warna border (kuning)
  draw_border(0, 0, game->screen_width, game->screen_height);
  attroff(COLOR_PAIR(3)); // Menonaktifkan kembali warna border (kuning)

  sprintf(buffer, " Petunjuk ");
  mvaddstr(game->screen_height / 2 - 1,
           game->screen_width - strlen(buffer) / 3 - 1,
           buffer);
  sprintf(buffer, " Arahkan ular dengan arrow keys atau WASD ");
  mvaddstr(game->screen_height / 2,
           game->screen_width - strlen(buffer) / 3 - 5,
           buffer);
  sprintf(buffer, " Tekan ESC/SPACE untuk pause ");
  mvaddstr(game->screen_height / 2 + 1,
           game->screen_width - strlen(buffer) / 3 - 4,
           buffer);
  sprintf(buffer, " ENTER/SPACE: OK ");
  mvaddstr(game->screen_height / 2 + 2,
           game->screen_width - strlen(buffer) / 3 - 3,
           buffer);

  do
  {
    switch (getch()) // Menunggu input dari user
    {
    case ' ':
    case '\n':
    case '\r': // jika user menekan ENTER/SPACE, keluar dari prosedur dan lanjutkan ke permainan
      return;
    }
  } while (true);
}

// Prosedur untuk menggambar batas layar
// y: posisi y dari batas
// x: posisi x dari batas
// width: lebar batas
// height: tinggi batas
// Menggambar batas permainan di layar.
void draw_border(int y, int x, int width, int height)
{
  attron(COLOR_PAIR(3)); // Menggunakan warna kuning

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
  attroff(COLOR_PAIR(3)); // Menonaktifkan warna kuning
}

// Prosedur untuk menampilkan makanan ular ke layar
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void draw_food(Game *game)
{
  attron(COLOR_PAIR(1)); // Menggunakan warna makanan (merah)
  // Gambar makanan berdasarkan posisi dengan karakter '@'
  mvaddch(game->game_food.position.y + 1,
          game->game_food.position.x * 2 + 1,
          '@');
  attroff(COLOR_PAIR(1)); // Menonaktifkan kembali warna makanan (merah)
}

// Prosedur untuk menampilkan ular ke layar
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void draw_snake(Game *game)
{
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
}

// Prosedur untuk menampilkan score saat ini
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void show_in_game_score(Game *game)
{
  // Tampilkan skor
  sprintf(buffer, " Score: %d ", game->current_score.score);
  mvaddstr(0, 2, buffer); // tampilkan skor di tengah atas
}

// Prosedur untuk menampilkan hi-score saat ini
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void show_in_game_hi_score(Game *game)
{
  // Tampilkan hi-score
  sprintf(buffer, " Hi-Score: %d | %s ", game->hi_score.score, game->hi_score.player_name);
  mvaddstr(0, game->screen_width * 2 - strlen(buffer), buffer); // tampilkan hi-score di kiri bawah
}

// Prosedur untuk menampilkan level saat ini yang sedang dimainkan
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void show_in_game_level(Game *game)
{
  // Tampilkan level saat ini
  sprintf(buffer, " Level: %d ", game->settings.level);
  mvaddstr(game->screen_height + 1, 2, buffer); // tampilkan level di kanan atas
}

// Prosedur untuk menampilkan tampilan game over atau paused
// game: parameter input, menunjuk ke objek Game yang akan ditampilkan
// game_data: parameter input/output passing by reference, menunjuk ke objek GameData yang menyimpan data permainan
// Menampilkan pesan game over atau kemenangan, serta instruksi untuk memulai ulang permainan.
void show_game_over_ui(Game *game, GameData *game_data)
{
  // Jika menang, tampilkan pesan kemenangan
  if (game->is_winning)
  {
    attron(COLOR_PAIR(4)); // Aktifkan warna biru

    // Pesan kemenangan di tengah layar
    mvaddstr(game->screen_height / 2 - 1,
             game->screen_width - 10,
             "  Selamat! Anda Menang!  ");
    attroff(COLOR_PAIR(4)); // Nonaktifkan warna biru

    attron(COLOR_PAIR(3)); // Aktifkan warna kuning
    mvaddstr(game->screen_height / 2,
             game->screen_width - 12,
             " Tekan SPACE untuk main lagi ");
  }
  else if (game->is_pause) // tampilkan pesan berbeda jika pause
  {
    attron(COLOR_PAIR(3)); // Aktifkan warna kuning
    mvaddstr(game->screen_height / 2 - 1,
             game->screen_width - 10,
             "         Paused         ");
    mvaddstr(game->screen_height / 2,
             game->screen_width - 17,
             " Tekan SPACE untuk melanjutkan (resume) ");
  }
  else // Pesan game over
  {
    attron(COLOR_PAIR(1)); // Aktifkan warna merah
    mvaddstr(game->screen_height / 2 - 1,
             game->screen_width - 10,
             "        Game Over        ");
    attroff(COLOR_PAIR(1)); // Nonaktifkan warna merah
    attron(COLOR_PAIR(3));  // Aktifkan warna kuning
    mvaddstr(game->screen_height / 2,
             game->screen_width - 11,
             " Tekan SPACE untuk restart ");
  }

  attron(COLOR_PAIR(3)); // Aktifkan warna kuning
  mvaddstr(game->screen_height / 2 + 1,
           game->screen_width - 15,
           " Tekan ENTER untuk kembali ke menu ");
  mvaddstr(game->screen_height / 2 + 2,
           game->screen_width - 9,
           " Tekan ESC untuk keluar ");
  attroff(COLOR_PAIR(3)); // Nonaktifkan warna kuning

  do
  {
    switch (getch()) // Mendapatkan input
    {
    case ' ':                // spasi
      if (!game->is_running) // restart game ketika game over
        game_restart(game, game_data);
      else if (game->is_pause) // resume game ketika pause
        game->is_pause = false;
      return;
    case '\n': // enter untuk ke menu
    case '\r':
      show_menu(game_data);
      game_restart(game, game_data); // restart game setelah dari menu (jika tidak quit)
      return;
    case 27:       // ESC key
      quit_game(); // quit game
      return;
    }
  } while (true);
}

// Prosedur untuk menampilkan dan mengambil input nama player yang dapat hi-score baru
// game: parameter input/output passing by reference, menunjuk ke objek Game yang akan diperbarui berdasarkan input
void get_hi_score_player_name(Game *game)
{
  attron(COLOR_PAIR(2)); // Menggunakan warna hijau

  // Tampilkan prompt
  mvaddstr(game->screen_height / 2 - 1,
           game->screen_width - 10,
           "  Skor Tertinggi Baru!  ");
  mvaddstr(game->screen_height / 2,
           game->screen_width - 10,
           "  Masukkan nama anda : ");

  echo();                                // Aktifkan echo untuk menampilkan input
  mvgetnstr(game->screen_height / 2 + 1, // Ambil input nama pemain
            game->screen_width - 8,      //
            buffer, sizeof(buffer) - 1); //
  noecho();                              // Nonaktifkan echo setelah input

  attroff(COLOR_PAIR(2)); // Nonaktifkan warna hijau

  // Simpan nama pemain ke player name current score
  strcpy(game->current_score.player_name, buffer);
  erase(); // bersihkan layar
}

// Prosedur untuk menangani input dari pengguna selama dalam permainan
// game: parameter input/output passing by reference, menunjuk ke objek Game yang akan diperbarui berdasarkan input
void ui_handle_input(Game *game)
{
  switch (getch()) // Mendapatkan input
  {
  case 'a':
  case 'A':
  case KEY_LEFT:
    game_handle_input(game, vector2_create(-1, 0)); // Arahkan ular ke kiri
    break;
  case 'd':
  case 'D':
  case KEY_RIGHT:
    game_handle_input(game, vector2_create(1, 0)); // Arahkan ular ke kanan
    break;
  case 'w':
  case 'W':
  case KEY_UP:
    game_handle_input(game, vector2_create(0, -1)); // Arahkan ular ke atas
    break;
  case 's':
  case 'S':
  case KEY_DOWN:
    game_handle_input(game, vector2_create(0, 1)); // Arahkan ular ke bawah
    break;
  case ' ':                // spasi
  case 27:                 // ESC key
    game->is_pause = true; // pause ketika game sedang berjalan
  }
}

// Prosedur untuk keluar dari permainan
// Menghentikan antarmuka pengguna dan membersihkan layar sebelum keluar dari program.
void quit_game()
{
  endwin(); // Mengakhiri mode curses, mengembalikan terminal ke mode normal

  exit(0); // Keluar dari program dengan status sukses
}