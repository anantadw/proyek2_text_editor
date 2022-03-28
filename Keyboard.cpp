#include "input_handling.h"

/* menginput karakter ke array */
void inputCharacter(char teks[][MAX_COLUMN + 2], int &row, int &column, char c) {
	teks[row][column] = c;
	printf("%c", c);
	column += 1;
}

/* menghapus 1 karakter terakhir dari array */
void deleteCharacter(char teks[][MAX_COLUMN + 2], int &row, int &column, int &cursor_x) {
	teks[row][column] = 0x00;
	column -= 1;
	printf("\b \b");
	if (column < 0) {
		column = 0;
	}
	cursor_x -= 1;
	if (cursor_x < 0) {
		cursor_x = 0;
	}
}
