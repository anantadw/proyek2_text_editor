#ifndef file_handling_H
#define file_handling_H

#include "input_handling.h"

/* mencek apakah file sudah ada */
bool checkFileExists(char [30]);

/* menginput ke file */
void inputFile(FILE *);

/* membaca inputan */
void readInput(FILE *);

void editFile(FILE *, List [], int, int, address *);

/* menyimpan ke file */
void saveFile(FILE *, List [], int);

#endif
