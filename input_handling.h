#ifndef input_handling_H
#define input_handling_H

#include "utilities.h"

/* menginput karakter ke list */
void inputCharacter(char, List *, int *, address *);

/* membuat baris baru */
void newLine(List [], int *, int *, int *, address *);

/* menghapus 1 karakter terakhir dari list */
void deleteCharacter(List *, int *, address *, int *, int *, List *);

/* menyalin isi dari suatu baris */
List copy(List);

/* untuk menyimpan hasil salinan suatu baris */
void paste(List *, List, int *, address *);

/* membersihkan data yang ada di clipboard */
void clearClipboard(List *clipboard);

/* menggerakan cursor ke kiri */
void moveLeft(address *, int *, int);

/* menggerakan cursor ke kanan */
void moveRight(address *, int *, int, List);

/* menggerakan cursor ke atas */
void moveUp(address *, int *, int *, List *);

/* menggerakan cursor ke bawah */
void moveDown(address *, int *, int *, List *);

#endif
