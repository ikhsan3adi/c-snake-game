// Nama Program : score.c
// Deskripsi    : Implementasi logika pengelolaan skor dalam permainan,
//                bertujuan untuk membuat, menambah, dan menyimpan skor pemain.
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#include <string.h>
#include "score.h"

Score create_score(int score, char *player_name, int level, DateTime date)
{
  // Kamus
  Score new_score; // Deklarasi objek Score baru

  // Assign nilai atribut objek Score
  strcpy(new_score.player_name, player_name); // salin player_name ke new_score.player_name
  new_score.score = score;
  new_score.level = level;
  new_score.date = date;

  return new_score;
}

void add_score(Score *score)
{
  score->score++; // increment skor
}
