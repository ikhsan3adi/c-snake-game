// Nama Program : ui.h
// Deskripsi    : Definisi fungsi-fungsi antarmuka pengguna,
//                bertujuan merancang tampilan dan mekanisme interaksi pengguna dengan permainan
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#ifndef UI_H
#define UI_H

#include "game.h"

// Prosedur untuk menginisialisasi antarmuka pengguna (UI)
// Mengatur tampilan, warna, dan pengaturan awal untuk tampilan permainan.
void initialize_ui();

// Prosedur untuk menampilkan judul game dengan ascii art
void show_title();

// Prosedur untuk menampilkan menu utama permainan
// game_data: parameter input/output passing by reference, menunjuk ke objek GameData yang menyimpan data permainan
void show_menu(GameData *game_data);

// Prosedur untuk mengatur level permainan
// game_data: parameter input/output passing by reference, menunjuk ke objek GameData yang menyimpan data permainan
void set_game_level(GameData *game_data);

// Prosedur untuk merender tampilan permainan
// game: parameter input, menunjuk ke objek Game yang akan dirender
// Menggambar elemen-elemen permainan seperti ular, makanan, skor, dan batas layar.
void render_ui(Game *game);

// Prosedur untuk menggambar batas layar
// y: posisi y dari batas
// x: posisi x dari batas
// width: lebar batas
// height: tinggi batas
// Menggambar batas permainan di layar.
void draw_border(int y, int x, int width, int height);

// Prosedur untuk menampilkan tampilan game over
// game: parameter input, menunjuk ke objek Game yang akan ditampilkan
// Menampilkan pesan game over atau kemenangan, serta instruksi untuk memulai ulang permainan.
void show_game_over_ui(Game *game);

// Prosedur untuk menampilkan dan mengambil input nama player
// game: parameter input/output passing by reference, menunjuk ke objek Game yang akan diperbarui berdasarkan input
void get_player_name(Game *game);

// Prosedur untuk menangani input dari pengguna
// game: parameter input/output passing by reference, menunjuk ke objek Game yang akan diperbarui berdasarkan input
// game_data: parameter input/output passing by reference, menunjuk ke objek GameData yang menyimpan data permainan
void ui_handle_input(Game *game, GameData *game_data);

// Prosedur untuk keluar dari permainan
// Menghentikan antarmuka pengguna dan membersihkan layar sebelum keluar dari program.
void quit_game();

#endif // UI_H