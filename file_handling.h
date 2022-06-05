#ifndef file_handling_H
#define file_handling_H

#include "input_handling.h"

/* mencek apakah file sudah ada */
bool checkFileExists(char [20]);

/* membaca inputan */
void readInput(FILE *, List [], address *, int, int);

/* menyimpan ke file */
void saveFile(FILE *, List [], int);

#endif
