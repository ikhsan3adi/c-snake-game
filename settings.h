#ifndef SETTINGS_H
#define SETTINGS_H

// frame delay berdasarkan level
#define SPEED_1 200000
#define SPEED_2 170000
#define SPEED_3 140000
#define SPEED_4 100000
#define SPEED_5 50000

// struct untuk menyimpan pengaturan permainan
typedef struct
{
  int level; // level 1-5
  int speed; // Kecepatan permainan
} Settings;

// Prosedur untuk memperbarui pengaturan permainan (kecepatan permainan)
// settings: parameter output passing by reference, tipe Settings, alamat dari objek yang akan diperbarui
// level: parameter input passing by value, tipe integer, level permainan
// new_speed: parameter input passing by value, tipe integer, kecepatan permainan baru
void update_settings(Settings *settings, int level, int new_speed);

#endif // SETTINGS_H