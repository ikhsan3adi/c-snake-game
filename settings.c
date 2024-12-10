#include <stdio.h>
#include "settings.h"

// Prosedur untuk memperbarui pengaturan permainan (kecepatan permainan)
// settings: parameter output passing by reference, tipe Settings, alamat dari objek yang akan diperbarui
// level: parameter input passing by value, tipe integer, level permainan
// new_speed: parameter input passing by value, tipe integer, kecepatan permainan baru
void update_settings(Settings *settings, int level, int new_speed)
{
  settings->level = level;
  settings->speed = new_speed;
}