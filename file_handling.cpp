#include "file_handling.h"

/* mencek apakah file sudah ada */
bool checkFileExists(char file_name[30]) {
	FILE *fp;
	
    if (fp = fopen(file_name, "r")) {
        fclose(fp);
        return true;
    }

    return false;
}

/* menginput ke file */
void inputFile(FILE *fp) {
	system("cls");
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                              INPUT FILE                               ||\n");
	printf("||                      Tekan CTRL+S untuk menyimpan                     ||\n");
	printf("||=======================================================================||\n");
	
	readInput(fp);
}

/* membaca inputan */
void readInput(FILE *fp) {
	char c, teks[MAX_ROW][MAX_COLUMN + 2] = {}, clipboard[MAX_COLUMN + 2] = {};
	int row = 0, column = 0, i;
	bool loop = true;
	
	while (loop) {
		if (column == MAX_COLUMN) {
			newLine(teks, row, column);
		}
		
		if (row == MAX_ROW) {
			printf("\n");
			printf("\t!> Batas maksimal baris tercapai.");
			break;
		}
		
		c = getch();
		switch (c) {
			case KEY_BACKSPACE:
				deleteCharacter(teks, row, column);
				break;
			case KEY_ENTER:
				newLine(teks, row, column);
				break;
			case KEY_SAVE:
				loop = false;
				break;
			case KEY_COPY:
				copyLine(teks, row, clipboard);
				break;
			case KEY_PASTE:
				paste(teks, row, column, clipboard);
				break;
//			case KEY_UP:
//				cursorUp(row, column);
//				break;
//			case KEY_DOWN:
//				cursorDown(row, column);
//				break;
			default:
				inputCharacter(teks, row, column, c);
		}
	};
	
	saveFile(fp, teks);
}

/* menyimpan ke file */
void saveFile(FILE *fp, char teks[][MAX_COLUMN + 2]) {
	int i;
	
	for (i = 0; i < MAX_ROW; i++) {
		fputs(teks[i], fp);
	}
	
	printf("\n\t!> File disimpan.\n");
}
