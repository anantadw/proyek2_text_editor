#ifndef file_handling_H
#define file_handling_H

#include "input_handling.h"

/* mencek apakah file sudah ada */
bool checkFileExists(char [30]);

/* menginput ke file */
void inputFile(FILE *);

/* membaca inputan */
void readInput(FILE *);

/* menyimpan ke file */
void saveFile(FILE *, char [][MAX_COLUMN + 2]);

#endif
