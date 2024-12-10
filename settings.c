// Nama Program : settings.c
// Deskripsi    : Implementasi pengaturan permainan,
//                bertujuan untuk memperbarui dan mengelola pengaturan permainan seperti level dan kecepatan.
// Pembuat      : Ikhsan Satriadi / 241511080
//                Rizky Satria Gunawan / 241511089

#include <stdio.h>
#include "settings.h"

// Prosedur untuk memperbarui pengaturan permainan (kecepatan permainan)
// settings: parameter output passing by reference, tipe Settings, alamat dari objek yang akan diperbarui
// level: parameter input passing by value, tipe integer, level permainan
// new_speed: parameter input passing by value, tipe integer, kecepatan permainan baru
void update_settings(Settings *settings, int level, int new_speed)
{
  // update level dan speed
  settings->level = level;
  settings->speed = new_speed;
}