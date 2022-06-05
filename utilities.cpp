#include "utilities.h"

/* memindahkan cursor ke suatu koordinat x y */
void gotoXY(int x, int y)
{
	COORD c;
	
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/* memberikan warna pada teks */
void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/* menampilkan frame menu bagian atas */
void printTopBar()
{
	int x;
	
	printf("\xc9");
	for(x = 1; x <= 72; x++){
		printf("\xcd");
	}
	printf("\xbb");
}

/* menampilkan frame menu bagian tengah */
void printMidBar()
{
	int x;
	
	printf("\xcc");
	for(x = 1; x <= 72; x++){
		printf("\xcd");
	}
	printf("\xb9");
}

/* menampilkan frame menu bagian tengah besera inputan */
void printMidInput()
{
	printMidBar();
	printf("\n\xba                                                                        \xba\n");
	printf("\xba  ?> Nama file (tanpa spasi dan ekstensi)                               \xba\n");
	printf("\xba     Masukkan '0' untuk kembali :                                       \xba\n");
	printf("\xba                                                                        \xba\n");
	printf("\xba                                                                        \xba\n");
	printf("\xba                                                                        \xba\n");
}

/* menampilkan frame menu bagian bawah */
void printBottomBar()
{
	int x;
	
	printf("\xc8");
	for(x = 1; x <= 72; x++){
		printf("\xcd");
	}
	printf("\xbc\n");
}

/* menampilkan pesan dengan warna */
void printMessage(int color, char message[], int line)
{
	gotoXY(3, line);
	setColor(color);
	printf("%s", message);
	setColor(WHITE);
}

/* mengalokasikan node baru untuk list */
address createNode(char c)
{
	address new_node;
	
	new_node = (address) malloc(sizeof(node));
    if (new_node != NULL)
	{
        new_node->character = c;
        new_node->previous = NULL;
        new_node->next = NULL;
    }

    return new_node;
}

/* menghitung jumlah node bada list/baris */
int countColumn(List text)
{
	address node;
	int count = 0;
	
	node = text.first;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	
	return count;
}

/* menampilan isi list */
void printText(List text[], int row, int column, int cursor_row)
{
	int i;
	address node;
	
	system("cls");
	
	for (i = 0; i <= row; i++)
	{
		node = text[i].first;
		while (node != NULL)
		{
			printf("%c", node->character);
			node = node->next;
		}
	}
	
	gotoXY(column, cursor_row);
}
