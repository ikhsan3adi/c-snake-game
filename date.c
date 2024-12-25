// Nama Program : date.c
// Deskripsi    : Implementasi fungsi date untuk membuat tanggal dan waktu
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#include "date.h"
#include <time.h>
#include <stdio.h>

char *month_names[12] = {"Jan", "Feb", "Mar",
                         "Apr", "Mei", "Jun",
                         "Jul", "Aug", "Sep",
                         "Okt", "Nov", "Des"};

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

bool is_valid(DateTime date)
{
  if ((date.year < 1900) || (date.year > 30000) || (date.month < 1) ||
      (date.month > 12) || (date.day < 1) || (date.day > last_day_of_month(date)))
    return false;
  else
    return true;
}

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

bool is_leap(DateTime date)
{
  if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))
    return true; // Tahun kabisat
  else
    return false; // Bukan tahun kabisat
}

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

char *get_short_month_name(DateTime date)
{
  // Kembalikan nama bulan sesuai dengan index date.month - 1
  return month_names[date.month - 1];
}

void date_to_string(char *date_str, DateTime date)
{
  sprintf(date_str,
          "%02d %s %04d %02d:%02d:%02d", // format tanggal dan waktu "DD MMM YYYY HH:MM:SS"
          date.day,
          get_short_month_name(date), // nama bulan singkat
          date.year,
          date.hour,
          date.minute,
          date.second);
}
