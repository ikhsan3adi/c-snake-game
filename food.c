#include "food.h"

Food create_food(int screen_width, int screen_height, Snake *snake)
{
  // Buat posisi untuk makanan
  Vector2 food_pos = food_generate_position(screen_width, screen_height, snake);

  // Buat objek makanan
  Food new_food = {food_pos};

  return new_food;
}

Vector2 food_generate_position(int screen_width, int screen_height, Snake *snake)
{
  Vector2 new_position;
  bool valid_position;

  do
  {
    // Hasilkan posisi acak dengan menghindari batas layar
    new_position = vector2_create(
        1 + rand() % (screen_width - 2),
        1 + rand() % (screen_height - 2));

    // Periksa apakah posisi bertabrakan dengan kepala ular atau segmen ular
    valid_position = !vector2_equals(new_position, snake->head);

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