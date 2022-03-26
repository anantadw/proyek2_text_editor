#include "menu.h"

int main() {
	char choice;
	
	while (true) {
		printMenu();
		printf("\t?> Pilih menu: ");
		choice = getche();
		
		switch (choice) {
			case '1':
				createFile();
				break;
			case '2':
				openFile();
				break;
			case '3':
				deleteFile();
				break;
			case '4':
				renameFile();
				break;
			case '5':
				aboutProgram();
				break;
			case '6':
				printf("\n");
				exit(1);
				break;
			default:
				printf("\t!> Tidak ada di pilihan.\n");
		}	
	}
	
	return 0;
}
