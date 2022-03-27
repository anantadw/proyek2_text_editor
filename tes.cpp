#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_COLUMN 10
#define MAX_ROW 3

int main() {
	char teks[MAX_ROW][MAX_COLUMN + 2];
	int row = 0, column = 0, c;
	
	while (true) {
		c = getche();
		
		if (c == 0x08) {
	    	teks[row][--column] = 0x00;
	    	printf("\b \b");
	    } else{
	    	teks[row][column++] = c;
	    }
		
		if (column == MAX_COLUMN) {
			printf("\n");
			teks[row++][column] = '\n';
			column = 0;
		}
		
		if (row == MAX_ROW) {
			break;
		}
	};
	
	printf("\n");
	printf(teks[0]);
	printf(teks[1]);
	printf(teks[2]);
	
	return 0;
}
