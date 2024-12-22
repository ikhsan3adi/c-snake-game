// Nama Program : settings.c
// Deskripsi    : Implementasi pengaturan permainan,
//                bertujuan untuk memperbarui dan mengelola pengaturan permainan seperti level dan kecepatan.
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#include "settings.h"

void update_settings(Settings *settings, int level, int speed)
{
  // update level dan speed
  settings->level = level;
  settings->speed = speed;
}