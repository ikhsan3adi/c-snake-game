// Nama Program : snake.c
// Deskripsi    : Implementasi logika pergerakan dan pertumbuhan ular,
//                bertujuan mengendalikan pergerakan, pertumbuhan, dan interaksi ular dengan
//                makanan dan tembok/batas layar
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#include "snake.h"

// Fungsi untuk membuat ular baru
// start_x: posisi awal x dari kepala ular
// start_y: posisi awal y dari kepala ular
// Mengembalikan objek ular baru bertipe Snake
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

// Prosedur untuk menggerakkan ular
// snake: parameter input/output passing by reference, menunjuk ke objek ular yang akan diperbarui
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

// Fungsi untuk memeriksa apakah ular bertabrakan dengan dirinya sendiri
// snake: parameter input passing by reference, menunjuk ke objek ular yang akan diperiksa
// Mengembalikan true jika ular bertabrakan dengan dirinya sendiri, false jika tidak
bool snake_collides_with_self(Snake *snake)
{
  for (int i = 1; i < snake->length; i++)
  {
    if (vector2_equals(snake->head, snake->segments[i])) // Jika ada posisi segmen yang sama dengan kepala
      return true;
  }
  return false;
}

// Prosedur untuk menumbuhkan ular
// snake: parameter output passing by reference, menunjuk ke objek ular yang akan diperbarui
void snake_grow(Snake *snake)
{
  if (snake->length < MAX_SNAKE_LENGTH) // Cek apakah ular sudah mencapai panjang maksimum
  {
    snake->length = snake->length + 1; // Tambahkan satu segmen baru
  }
}

// Fungsi untuk mendapatkan simbol yang merepresentasikan kepala ular berdasarkan arah gerakan
// snake: parameter input passing, menunjuk ke objek ular yang akan diperiksa
// Mengembalikan karakter yang merepresentasikan kepala ular ('>', '<', 'v', '^')
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

// Prosedur untuk mengubah arah gerakan ular
// snake: parameter input/output passing by reference, menunjuk ke objek ular yang akan diperbarui
// new_direction: arah baru untuk ular, bertipe Vector2
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
