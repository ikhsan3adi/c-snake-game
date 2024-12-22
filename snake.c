// Nama Program : snake.c
// Deskripsi    : Implementasi logika pergerakan dan pertumbuhan ular,
//                bertujuan mengendalikan pergerakan, pertumbuhan, dan interaksi ular dengan
//                makanan dan tembok/batas layar
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#include "snake.h"

Snake create_snake(int start_x, int start_y)
{
  // Kamus
  Snake new_snake; // buat objek ular baru

  new_snake.head = vector2_create(start_x, start_y); // buat posisi kepala ular
  new_snake.direction = vector2_create(1, 0);        // arah ular
  new_snake.length = 1;                              // panjang awal
  new_snake.segments[0] = new_snake.head;            // simpan posisi kepala ke dalam segment pertama

  return new_snake;
}

void snake_move(Snake *snake)
{
  // Geser segmen dan update segmen berdasarkan panjang ular
  for (int i = snake->length - 1; i > 0; i--)
  {
    snake->segments[i] = snake->segments[i - 1]; // segmen saat ini diassign dengan nilai segmen sebelumnya
  }

  // Assign posisi kepala ke segmen pertama
  snake->segments[0] = snake->head;

  // Perbarui kepala
  snake->head = vector2_add(snake->head, snake->direction); // geser kepala ke arah yang ditentukan sesuai vektor direction
}

bool snake_collides_with_self(Snake *snake)
{
  for (int i = 1; i < snake->length; i++)
  {
    if (vector2_equals(snake->head, snake->segments[i])) // Jika ada posisi segmen yang sama dengan kepala
      return true;
  }
  return false;
}

void snake_grow(Snake *snake)
{
  if (snake->length < MAX_SNAKE_LENGTH) // Cek apakah ular sudah mencapai panjang maksimum
  {
    snake->length = snake->length + 1; // Tambahkan satu segmen baru
  }
}

char get_snake_head_symbol(Snake *snake)
{
  if (snake->direction.x == 1)
    return '>'; // kanan
  if (snake->direction.x == -1)
    return '<'; // kiri
  if (snake->direction.y == 1)
    return 'v'; // bawah
  if (snake->direction.y == -1)
    return '^'; // atas

  return '>'; // default
}

void snake_change_direction(Snake *snake, Vector2 new_direction)
{
  // Cegah ular bergerak mundur
  if ((new_direction.x == -(snake->direction.x) && new_direction.x != 0) ||
      (new_direction.y == -(snake->direction.y) && new_direction.y != 0))
  {
    return;
  }

  // Ubah arah gerakan ular
  snake->direction = new_direction;
}
