#ifndef input_handling_H
#define input_handling_H

#include "constants.h"

/* mengalokasikan node baru untuk list */
address createNode(char);

/* menginput karakter ke list */
void inputCharacter(char, List *, int *);

/* membuat baris baru */
void newLine(List *, int *, int *);

/* menghapus 1 karakter terakhir dari list */
void deleteCharacter(List *, int *);

#endif

