#include "file_handling.h"

/* mencek apakah file sudah ada */
bool checkFileExists(char file_name[20])
{
	FILE *fp;
	bool result = false;
	
	fp = fopen(file_name, "r");
    if (fp)
	{
        fclose(fp);
        result = true;
    }

    return result;
}

/* membaca inputan */
void readInput(FILE *fp, List text[], address *pointer, int row, int column)
{
	char c;
	int cursor_row = row;
	bool loop = true;
	List clipboard;
	
	while (loop)
	{
		if (text[row].number_of_column == MAX_COLUMN)
		{
			newLine(text, &row, &cursor_row, &column, pointer);
		}
		
		if (row == MAX_ROW)
		{
			printf("\n");
			printf("\t!> Batas maksimal baris tercapai.");
			break;
		}
		
		c = getch();
		switch (c)
		{
			case KEY_ESCAPE:
				break;
			case KEY_UP:
				if (cursor_row > 0)
				{
					moveUp(pointer, &cursor_row, &column, &text[cursor_row - 1]);
				}
				break;
			case KEY_DOWN:
				if (cursor_row < row)
				{
					moveDown(pointer, &cursor_row, &column, &text[cursor_row + 1]);
				}
				break;
			case KEY_LEFT:
				moveLeft(pointer, &column, cursor_row);
				break;
			case KEY_RIGHT:
				moveRight(pointer, &column, cursor_row, text[cursor_row]);
				break;
			case KEY_BACKSPACE:
				deleteCharacter(&text[cursor_row], &column, pointer, &row, &cursor_row, &text[cursor_row - 1]);
				printText(text, row, column, cursor_row);
				break;
			case KEY_ENTER:
				newLine(text, &row, &cursor_row, &column, pointer);
				printText(text, row, column, cursor_row);
				break;
			case KEY_SAVE:
				row++;
				loop = false;
				break;
			case KEY_COPY:
				clipboard = copy(text[cursor_row]);
				break;
			case KEY_PASTE:
				paste(&text[cursor_row], clipboard, &column, pointer);
				clearClipboard(&clipboard);
				printText(text, row, column, cursor_row);
				break;
			default:
				inputCharacter(c, &text[cursor_row], &column, pointer);
				printText(text, row, column, cursor_row);
		}
	};
	
	saveFile(fp, text, row);
}

/* menyimpan ke file */
void saveFile(FILE *fp, List text[], int row)
{
	int i, x;
	address node;
	
	for (i = 0; i < row; i++)
	{
		node = text[i].first;
		while (node != NULL)
		{
			fputc(node->character, fp);
			node = node->next;
		}
	}
	
	system("cls");
	printf("\xc9");
	for(x = 1; x <= 30; x++)
	{
		printf("\xcd");
	}
	printf("\xbb\n");
	printf("\xba     File berhasil disimpan   \xba\n");
	printf("\xc8");
	for(x = 1; x <= 30; x++)
	{
		printf("\xcd");
	}
	printf("\xbc\n");
}
