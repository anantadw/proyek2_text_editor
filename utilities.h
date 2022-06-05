#ifndef utilities_H
#define input_handling_H

#include "constants.h"

/* memindahkan cursor ke suatu koordinat x y */
void gotoXY(int, int);

/* memberikan warna pada teks */
void setColor(int);

/* menampilkan frame menu bagian atas */
void printTopBar();

/* menampilkan frame menu bagian tengah */
void printMidBar();

/* menampilkan frame menu bagian tengah besera inputan */
void printMidInput();

/* menampilkan frame menu bagian bawah */
void printBottomBar();

/* menampilkan pesan dengan warna */
void printMessage(int, char[], int = 7);

/* mengalokasikan node baru untuk list */
address createNode(char);

/* menghitung jumlah node bada list/baris */
int countColumn(List);

/* menampilan isi list */
void printText(List [], int, int, int);

#endif
