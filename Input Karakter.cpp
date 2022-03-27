#include "input_handling.h"

/* menginput karakter ke array */
void inputCharacter(char teks[][MAX_COLUMN + 2], int &row, int &column, char c) {
	teks[row][column] = c;
	printf("%c", c);
	column += 1;
}
