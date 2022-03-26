#include "input_handling.h"

/* menginput karakter ke array */
void inputCharacter(char teks[][MAX_COLUMN + 2], int &row, int &column, char c) {
	teks[row][column] = c;
	printf("%c", c);
	column += 1;
}

/* membuat baris baru */
void newLine(char teks[][MAX_COLUMN + 2], int &row, int &column) {
	teks[row][column] = '\n';
	row += 1;
	column = 0;
	printf("\n");
}

/* menghapus 1 karakter terakhir dari array */
void deleteCharacter(char teks[][MAX_COLUMN + 2], int &row, int &column) {
	teks[row][column] = 0x00;
	column -= 1;
	printf("\b");
	if (column < 0) {
		column = 0;
	}
}

void cursorUp(int &row, int &column) {
	if (row == 0) {
		return;
	}
	row -= 1;
	column = 0;
	printf(MOVE_CURSOR_UP);
	printf("\r");
}

void cursorDown(int &row, int &column) {
	row += 1;
	column = 0;
	printf(MOVE_CURSOR_DOWN);
	printf("\r");
}

/* menyalin isi baris pada posisi kursor */
void copyLine(char teks[][MAX_COLUMN + 2], int row, char clipboard[MAX_COLUMN + 2]) {
	strcpy(clipboard, teks[row]);
}

/* menempel isi yang disalin */
void paste(char teks[][MAX_COLUMN + 2], int &row, int &column, char clipboard[MAX_COLUMN + 2]) {
	if (!clipboard[0] == '\0') {
		row += 1;
		column = 0;
		strcpy(teks[row], clipboard);
		printf("%s", clipboard);
		clipboard = {};
	}
}
