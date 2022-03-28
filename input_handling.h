#ifndef input_handling_H
#define input_handling_H

#include "constants.h"

/* menginput karakter ke array */
void inputCharacter(char [][MAX_COLUMN + 2], int &, int &, char);

/* membuat baris baru */
void newLine(char [][MAX_COLUMN + 2], int &, int &, int&, int&);

/* menghapus 1 karakter terakhir dari array */
void deleteCharacter(char [][MAX_COLUMN + 2], int &, int &, int &);

/* menyalin isi baris pada posisi kursor */
void copyLine(char [][MAX_COLUMN + 2], int, char [MAX_COLUMN + 2]);

/* menempel isi yang disalin */
void paste(char [][MAX_COLUMN + 2], int, int &, char [MAX_COLUMN + 2], int &, int);

/* menggerakan cursor ke koordinat tertentu */
int gotoXY(int, int);

/* menghitung banyaknya kolom pada suatu baris */
int getLastColumn(char [MAX_COLUMN + 2]);

#endif
