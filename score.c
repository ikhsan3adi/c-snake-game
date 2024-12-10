#include <stdio.h>
#include <string.h>
#include "score.h"

// Fungsi untuk membuat objek score
// score: parameter input passing by value, tipe integer
// player_name: parameter input passing by value, tipe string, nama pemain
// Mengembalikan objek Score
Score create_score(int score, char *player_name)
{
  Score new_score;
  strcpy(new_score.player_name, player_name);
  new_score.score = score;

  return new_score;
}

// Prosedur untuk menambah score
// score: parameter output passing by reference, tipe Score*, pointer ke objek Score yang akan ditambah
void add_score(Score *score)
{
  score->score++;
}
