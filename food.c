// Nama Program : food.c
// Deskripsi    : Implementasi logika generasi dan interaksi makanan dengan ular,
//                bertujuan menghasilkan makanan secara acak dan mengelola interaksi dengan ular
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#include <stdlib.h>
#include "food.h"

Food create_food(int screen_width, int screen_height, Snake *snake)
{
  // Kamus
  Vector2 food_pos = food_generate_position(screen_width, screen_height, snake); // Buat posisi untuk makanan
  Food new_food = {food_pos};                                                    // Buat objek makanan dengan posisi `food_pos`

  return new_food;
}

Vector2 food_generate_position(int screen_width, int screen_height, Snake *snake)
{
  // Kamus
  Vector2 new_position; // Deklarasi variabel untuk menyimpan posisi makanan
  bool valid_position;  // variabel untuk menyimpan status validitas posisi

  do
  {
    // Hasilkan posisi acak dengan menghindari batas layar
    new_position = vector2_create(
        1 + rand() % (screen_width - 2),
        1 + rand() % (screen_height - 2));

    // Periksa apakah posisi bertabrakan dengan kepala ular
    valid_position = !vector2_equals(new_position, snake->head);

    // Periksa apakah posisi bertabrakan dengan segmen ular
    for (int i = 0; i < snake->length && valid_position; i++)
    {
      if (vector2_equals(new_position, snake->segments[i]))
      {
        valid_position = false;
        break;
      }
    }
  } while (!valid_position);

  return new_position;
}