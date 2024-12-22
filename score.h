// Nama Program : score.h
// Deskripsi    : Header file untuk pengelolaan skor dalam permainan,
//                mendefinisikan struktur Score dan fungsi-fungsi terkait untuk
//                membuat dan mengelola skor pemain.
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#ifndef SCORE_H
#define SCORE_H

#include "date.h"

// Struktur untuk menyimpan informasi skor
typedef struct
{
  char player_name[50]; // Nama pemain
  int score;            // Skor
  int level;            // Tingkat permainan
  DateTime date;        // Tanggal skor dicapai
} Score;

/**
 * Fungsi untuk membuat objek score
 * @param score parameter input passing by value, tipe integer
 * @param player_name parameter input passing by value, tipe string, nama pemain
 * @param level parameter input passing by value, tipe integer, tingkat permainan
 * @param date parameter input passing by value, tipe DateTime, tanggal skor dicapai
 * @return Mengembalikan objek Score
 */
Score create_score(int score, char *player_name, int level, DateTime date);

/**
 * Prosedur untuk menambahkan skor
 * @param score menunjuk ke objek Score yang akan ditambahkan skornya
 */
void add_score(Score *score);

#endif // SCORE_H