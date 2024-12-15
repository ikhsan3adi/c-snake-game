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

// Prosedur untuk menampilkan pengaturan level permainan
// game_data: parameter input/output passing by reference, menunjuk ke objek GameData yang menyimpan data permainan
void show_game_level_menu(GameData *game_data);

/**
 * Menampilkan leaderboard yang berisi skor tertinggi.
 *
 * Prosedur ini menampilkan daftar skor tertinggi dari permainan
 * dan menunggu input dari pengguna untuk kembali ke menu.
 *
 * @param game_data Pointer ke objek GameData yang menyimpan informasi
 *                  tentang leaderboard dan skor pemain.
 */
void show_leaderboard(GameData *game_data);

// Prosedur untuk menampilkan nama pembuat dan kelompok
void show_copyright();

// Prosedur untuk merender tampilan permainan
// game: parameter input, menunjuk ke objek Game yang akan dirender
// Menggambar elemen-elemen permainan seperti ular, makanan, skor, dan batas layar.
void render_ui(Game *game);

// Prosedur untuk menampilkan panduan permainan sebelum dimulai
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void show_guides(Game *game);

// Prosedur untuk menggambar batas layar
// y: posisi y dari batas
// x: posisi x dari batas
// width: lebar batas
// height: tinggi batas
// Menggambar batas permainan di layar.
void draw_border(int y, int x, int width, int height);

// Prosedur untuk menampilkan makanan ular ke layar
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void draw_food(Game *game);

// Prosedur untuk menampilkan ular ke layar
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void draw_snake(Game *game);

// Prosedur untuk menampilkan score saat ini
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void show_in_game_score(Game *game);

// Prosedur untuk menampilkan hi-score saat ini
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void show_in_game_hi_score(Game *game);

// Prosedur untuk menampilkan level saat ini yang sedang dimainkan
// game: parameter input, menunjuk ke objek Game untuk mengambil informasi permainan
void show_in_game_level(Game *game);

// Prosedur untuk menampilkan tampilan game over atau paused
// game: parameter input, menunjuk ke objek Game yang akan ditampilkan
// game_data: parameter input/output passing by reference, menunjuk ke objek GameData yang menyimpan data permainan
// Menampilkan pesan game over atau kemenangan, serta instruksi untuk memulai ulang permainan.
void show_game_over_ui(Game *game, GameData *game_data);

// Prosedur untuk menampilkan dan mengambil input nama player yang dapat hi-score baru
// game: parameter input/output passing by reference, menunjuk ke objek Game yang akan diperbarui berdasarkan input
// rank: parameter input, peringkat pemain yang baru, didapatkan dari rank_index + 1
void get_hi_score_player_name(Game *game, int rank);

// Prosedur untuk menangani input dari pengguna selama dalam permainan
// game: parameter input/output passing by reference, menunjuk ke objek Game yang akan diperbarui berdasarkan input
void ui_handle_input(Game *game);

// Prosedur untuk keluar dari permainan
// Menghentikan antarmuka pengguna dan membersihkan layar sebelum keluar dari program.
void quit_game();

#endif // UI_H