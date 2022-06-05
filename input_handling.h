#ifndef input_handling_H
#define input_handling_H

#include "constants.h"

/* mengalokasikan node baru untuk list */
address createNode(char);

/* menginput karakter ke list */
void inputCharacter(char, List *, int *, address *);

/* membuat baris baru */
void newLine(List *, int *, int *, address *, List *);

/* menghapus 1 karakter terakhir dari list */
void deleteCharacter(List *, int *, address *);

/* menyalin isi dari suatu baris */
List copy(List);

/* untuk menyimpan hasil salinan suatu baris */
void paste(List *, List, int, int *, address *);

void gotoXY(int, int);

void moveLeft(address *, int *, int);

void moveRight(address *, int *, int, List);

void moveUp(address *, int *, int *, List *);

void printText(List [], int, int, int);

int countColumn(List);

void clearClipboard(List *clipboard);

#endif
