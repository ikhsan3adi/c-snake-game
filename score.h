// Nama Program : score.h
// Deskripsi    : Header file untuk pengelolaan skor dalam permainan,
//                mendefinisikan struktur Score dan fungsi-fungsi terkait untuk
//                membuat dan mengelola skor pemain.
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#ifndef SCORE_H
#define SCORE_H

// Struktur untuk menyimpan informasi skor
typedef struct
{
  char player_name[50]; // Nama pemain
  int score;            // Skor
} Score;

// Fungsi untuk membuat objek score
// score: parameter input passing by value, tipe integer
// player_name: parameter input passing by value, tipe string, nama pemain
// Mengembalikan objek Score
Score create_score(int score, char *player_name);

// Prosedur untuk menambah score
// score: parameter output passing by reference, tipe Score*, pointer ke objek Score yang akan ditambah
void add_score(Score *score);

#endif // SCORE_H