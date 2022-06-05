#ifndef menu_H
#define menu_H

#include "file_handling.h"

void printTopBar();

void printMidBar();

void printMidInput();

void printBottomBar();

void printMessage(int, char[], int = 7);

void setColor(int);

/* menampilkan pilihan menu */
void printMenu(int []);

/* membuat file baru */
void createFile();

/* membuka file yang dipilih */
void openFile();

/* menghapus file yang dipilih */
void deleteFile();

/* mengubah nama file tertentu */
void renameFile();

/* menduplikasi file tertentu */
void copyFile();

/* menampilkan deskripsi program */
void aboutProgram();

#endif
