#include "input_handling.h"

/* menginput karakter ke array */
void inputCharacter(char teks[][MAX_COLUMN + 2], int &row, int &column, char c) {
	teks[row][column] = c;
	printf("%c", c);
	column += 1;
}

/* membuat baris baru */
void newLine(char teks[][MAX_COLUMN + 2], int &row, int &column, int &cursor_x, int &cursor_y) {
	teks[row][column] = '\n';
	row += 1;
	column = 0;
	
	cursor_x = 0;
	cursor_y += 1;
	gotoXY(cursor_x, cursor_y);
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

/* menyalin isi baris pada posisi kursor */
void copyLine(char teks[][MAX_COLUMN + 2], int row, char clipboard[MAX_COLUMN + 2]) {
	strcpy(clipboard, teks[row]);
}

/* menempel isi yang disalin */
void paste(char teks[][MAX_COLUMN + 2], int row, int &column, char clipboard[MAX_COLUMN + 2], int &cursor_x, int cursor_y) {
	if (!clipboard[0] == '\0') {
		strcpy(teks[row], "");
		strcpy(teks[row], clipboard);
		printf("%s", teks[row]);
		strcpy(clipboard, "");
		
		column = getLastColumn(teks[row]);
		cursor_x = column;
		gotoXY(cursor_x, cursor_y);
	} else {
		return;
	}
}

/* menggerakan cursor ke koordinat tertentu */
int gotoXY(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* menghitung banyaknya kolom pada suatu baris */
int getLastColumn(char teks[MAX_COLUMN + 2]) {
	int last_column;
	
	last_column = strlen(teks);
	
	return last_column;
}
