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
//	printf("||=======================================================================||\n");	
//	printf("||                              TEKS EDITOR                              ||\n");
//	printf("||                              INPUT FILE                               ||\n");
//	printf("||                      Tekan CTRL+S untuk menyimpan                     ||\n");
//	printf("||=======================================================================||\n");
	
	readInput(fp);
}

/* membaca inputan */
void readInput(FILE *fp) {
	char c;
	int row = 0, column = 0;
	bool loop = true;
	List text[MAX_ROW], clipboard;
	address pointer = NULL;
	
	while (loop) {
		if (text[row].number_of_column == MAX_COLUMN) {
			newLine(&text[row], &row, &column, &pointer, &text[row + 1]);
		}
		
		if (row == MAX_ROW) {
			printf("\n");
			printf("\t!> Batas maksimal baris tercapai.");
			break;
		}
		
		c = getch();
		switch (c) {
			case KEY_LEFT:
				moveLeft(&pointer, &column, row);
				break;
			case KEY_RIGHT:
				moveRight(&pointer, &column, row, text[row]);
				break;
			case KEY_BACKSPACE:
				deleteCharacter(&text[row], &column, &pointer);
				printText(text, row, column);
				break;
			case KEY_ENTER:
				newLine(text, &row, &column, &pointer, &text[row + 1]);
				printText(text, row, column);
				break;
			case KEY_SAVE:
				row++;
				loop = false;
				break;
			case KEY_COPY:
				clipboard = copy(text[row]);
				break;
			case KEY_PASTE:
				paste(&text[row], clipboard, row, &column, &pointer);
				clearClipboard(&clipboard);
				printText(text, row, column);
				break;
			default:
				inputCharacter(c, &text[row], &column, &pointer);
				printText(text, row, column);
		}
	};
	
	saveFile(fp, text, row);
}

/* menyimpan ke file */
void saveFile(FILE *fp, List text[], int row) {
	int i;
	address node;
	
	for (i = 0; i < row; i++) {
		node = text[i].first;
		while (node != NULL) {
			fputc(node->character, fp);
//			printf("%c", node->character);
			node = node->next;
		}
	}
	
	system("cls");
	printf("\n");
	printf("\t============================\n");
	printf("\t|  File berhasil disimpan. |\n");
	printf("\t============================\n");
}

