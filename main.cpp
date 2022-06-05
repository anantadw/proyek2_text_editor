#include "menu.h"

int main()
{
	int set[] = {GREEN, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE};
	int counter = 1;
	char key;

	while (true)
	{
		printMenu(set);
		gotoXY(19, 14);
		printf("%d", counter);
		
		key = getch();
		if (key == ARROW_UP && counter > 1)
		{
			counter--;
		}
		else if (key == ARROW_DOWN && counter < 7)
		{
			counter++;
		}
		else if (key == KEY_ENTER)
		{
			switch (counter)
			{
				case 1:
					createFile();
					break;
				case 2:
					openFile();
					break;
				case 3:
					deleteFile();
					break;
				case 4:
					renameFile();
					break;
				case 5:
					copyFile();
					break;
				case 6:
					aboutProgram();
					break;
				case 7:
					gotoXY(0, 16);
					exit(1);
					break;
			}
		}	
		
		set[0]= WHITE;
		set[1]= WHITE;
		set[2]= WHITE;
		set[3]= WHITE;
		set[4]= WHITE;
		set[5]= WHITE;
		set[6]= WHITE;
		
		set[counter - 1] = GREEN;
	}
	
	return 0;
}
