// Nama Program : date.c
// Deskripsi    : Implementasi fungsi date untuk membuat tanggal dan waktu
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#include "date.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

// Variabel/konstanta global
// Array untuk menyimpan nama bulan singkat
static char *month_names[12] = {"Jan", "Feb", "Mar", "Apr", "Mei", "Jun", "Jul", "Aug", "Sep", "Okt", "Nov", "Des"};

// Fungsi untuk membuat tanggal dan waktu
// Parameter : year, month, day, hour, minutes, second, bertipe integer
// Mengembalikan objek bertipe DateTime
DateTime create_date(int year, int month, int day, int hour, int minute, int second)
{
  // Kamus data
  DateTime date; // deklarasi variabel date

  date.year = year;
  date.month = month;
  date.day = day;
  date.hour = hour;
  date.minute = minute;
  date.second = second;

  if (is_valid(date))
    return date;
  else                                       // jika tanggal tidak valid
    return create_date(1900, 1, 1, 0, 0, 0); // kembalikan tanggal 1 Januari 1900
}

// Memeriksa apakah suatu tanggal valid, yaitu dengan
// memperhatikan rentang tahun dan bulan serta
// memperhatikan batas akhir per bulan
// Parameter : date bertipe DateTime
// Mengembalikan nilai boolean
bool is_valid(DateTime date)
{
  if ((date.year < 1900) || (date.year > 30000) || (date.month < 1) ||
      (date.month > 12) || (date.day < 1) || (date.day > last_day_of_month(date)))
    return false;
  else
    return true;
}

// Memberikan tanggal terakhir dari sebuah bulan
// Parameter : date, bertipe DateTime
// Mengembalikan integer, yaitu tanggal terakhir dari bulan
int last_day_of_month(DateTime date)
{
  if ((date.month == 1) || (date.month == 3) || (date.month == 5) ||
      (date.month == 7) || (date.month == 8) || (date.month == 10) ||
      (date.month == 12))
    return 31;
  else if ((date.month == 4) || (date.month == 6) || (date.month == 9) ||
           (date.month == 11))
    return 30;
  else                              // Jika bulan Februari
    return is_leap(date) ? 29 : 28; // cek apakah tahun kabisat
}

// Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan februari saja
// kabisat adalah tahun yang habis dibagi 4 kecuali jika tahun habis dibagi 100
// jika tahun habis dibagi 400 maka tahun tersebut adalah kabisat
// Parameter : date, bertipe DateTime
// Mengembalikan boolean
bool is_leap(DateTime date)
{
  if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))
    return true; // Tahun kabisat
  else
    return false; // Bukan tahun kabisat
}

// Fungsi untuk mendapatkan tanggal dan waktu saat ini
// Mengembalikan objek bertipe DateTime
DateTime get_current_date()
{
  // Kamus data
  DateTime date;         // deklarasi variabel date
  time_t now;            // deklarasi variabel now bertipe time_t untuk menyimpan waktu saat ini (dalam format Unix)
  struct tm *local_time; // deklarasi variabel local_time untuk menyimpan waktu lokal

  // Dapatkan waktu saat ini
  time(&now);

  // Konversi ke waktu lokal
  local_time = localtime(&now);

  // Ekstrak komponen tanggal
  date = create_date(
      local_time->tm_year + 1900, // Tahun sejak 1900
      local_time->tm_mon + 1,     // Bulan (0-11, ditambah 1 untuk format 1-12)
      local_time->tm_mday,        // Hari dalam bulan (1-31)
      local_time->tm_hour,        // Jam (0-23)
      local_time->tm_min,         // Menit (0-59)
      local_time->tm_sec          // Detik (0-59)
  );

  return date;
}

// Fungsi untuk mendapatkan nama bulan singkat (Jan, Feb, Mar, ..., Des)
// Parameter : date, bertipe DateTime
// Mengembalikan array char
char *get_month_name(DateTime date)
{
  // Kembalikan nama bulan sesuai dengan parameter month
  return month_names[date.month - 1];
}

// Fungsi untuk membuat string tanggal dan waktu
// Parameter : date, bertipe DateTime
// Mengembalikan string
char *date_to_string(DateTime date)
{
  // Kamus data
  char *date_string; // deklarasi variabel bertipe array char

  // Konversi ke string
  date_string = malloc(21 * sizeof(char)); // alokasikan memori untuk menyimpan

  if (date_string == NULL)
    return "-"; // Penanganan kesalahan jika malloc gagal

  sprintf(date_string, "%02d %s %04d %02d:%02d:%02d", // format tanggal dan waktu
          date.day, get_month_name(date), date.year, date.hour, date.minute, date.second);

  return date_string;
}
