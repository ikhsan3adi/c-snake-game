// Nama Program : settings.h
// Deskripsi    : Header file untuk pengaturan permainan,
//                mendefinisikan struktur Settings dan fungsi-fungsi terkait untuk
//                memperbarui dan mengelola pengaturan permainan seperti level dan kecepatan.
// Pembuat      : Ikhsan Satriadi (241511080)
//                Rizky Satria Gunawan (241511089)

#ifndef SETTINGS_H
#define SETTINGS_H

// frame delay berdasarkan level (dalam microsecond)
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

/**
 * Prosedur untuk memperbarui pengaturan permainan
 * @param settings menunjuk ke objek Settings yang akan diperbarui
 * @param level level permainan baru
 * @param speed kecepatan permainan baru
 */
void update_settings(Settings *settings, int level, int speed);

#endif // SETTINGS_H