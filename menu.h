#ifndef menu_H
#define menu_H

#include "file_handling.h"

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

/* menduplikasi suatu file */
void copyFile();

/* menampilkan deskripsi program */
void aboutProgram();

#endif
