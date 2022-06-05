#ifndef constants_H
#define constants_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <string.h>
#include <cstring>
#include <windows.h>

#define MAX_COLUMN 40
#define MAX_ROW 10

/* kode ascii untuk key spesial */
#define KEY_COPY 3 /* ctrl + c */
#define KEY_PASTE 22 /* ctrl + v */
#define KEY_BACKSPACE 8
#define KEY_ENTER 13
#define KEY_SAVE 19 /* ctrl + s */
#define KEY_UP 9 /* ctrl + i */
#define KEY_DOWN 11 /* ctrl + k */
#define KEY_LEFT 10 /* ctrl + j */
#define KEY_RIGHT 12 /* ctrl + l */

/* struktur node */
typedef struct node *address;
typedef struct node
{
    char character;
    address previous, next;
} charNode;

/* struktur list */
typedef struct
{
    address first = NULL;
    int number_of_column = 0;
} List;

#endif
