#ifndef constants_H
#define constants_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <string.h>

#define MAX_COLUMN 6
#define MAX_ROW 3

#define KEY_COPY 3 /* ctrl + c */
#define KEY_PASTE 22 /* ctrl + v */
#define KEY_BACKSPACE 8
#define KEY_ENTER 13
#define KEY_SAVE 19 /* ctrl + s */
#define KEY_UP 72
#define KEY_DOWN 80
#define MOVE_CURSOR_UP "\x1b[A"
#define MOVE_CURSOR_DOWN "\x1b[B"

#endif
