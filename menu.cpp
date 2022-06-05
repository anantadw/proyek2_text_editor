#include "menu.h"
#include <errno.h>

void printTopBar() {
	int x;
	
	printf("\xc9");
	for(x = 1; x <= 72; x++){
		printf("\xcd");
	}
	printf("\xbb");
}

void printMidBar() {
	int x;
	
	printf("\xcc");
	for(x = 1; x <= 72; x++){
		printf("\xcd");
	}
	printf("\xb9");
}

void printMidInput() {
	printMidBar();
	printf("\n\xba                                                                        \xba\n");
	printf("\xba  ?> Nama file (tanpa spasi dan ekstensi)                               \xba\n");
	printf("\xba     Masukkan '0' untuk kembali :                                       \xba\n");
	printf("\xba                                                                        \xba\n");
	printf("\xba                                                                        \xba\n");
	printf("\xba                                                                        \xba\n");
}

void printBottomBar() {
	int x;
	
	printf("\xc8");
	for(x = 1; x <= 72; x++){
		printf("\xcd");
	}
	printf("\xbc\n");
}

void printMessage(int color, char message[], int line) {
	gotoXY(3, line);
	setColor(color);
	printf("%s", message);
	setColor(WHITE);
}

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/* menampilkan pilihan menu */
void printMenu(int set[]) {
	system("cls");
	
	printTopBar();
	printf("\n\xba                          TypeApp TEXT EDITOR                           \xba\n");
	printf("\xba                                 MENU                                   \xba\n");
	printMidBar();
	printf("\n\xba                                                                        \xba\n");
	printf("\xba  "); setColor(set[0]); printf("1. Buat file"); setColor(7); gotoXY(73, 5); printf("\xba\n");
	printf("\xba  "); setColor(set[1]); printf("2. Buka file"); setColor(7); gotoXY(73, 6); printf("\xba\n");
	printf("\xba  "); setColor(set[2]); printf("3. Hapus file"); setColor(7); gotoXY(73, 7); printf("\xba\n");
	printf("\xba  "); setColor(set[3]); printf("4. Ubah nama file"); setColor(7); gotoXY(73, 8); printf("\xba\n");
	printf("\xba  "); setColor(set[4]); printf("5. Duplikasi file"); setColor(7); gotoXY(73, 9); printf("\xba\n");
	printf("\xba  "); setColor(set[5]); printf("6. Tentang program"); setColor(7); gotoXY(73, 10); printf("\xba\n");
	printf("\xba  "); setColor(set[6]); printf("7. Keluar program"); setColor(7); gotoXY(73, 11); printf("\xba\n");
	printf("\xba                                                                        \xba\n");
	printMidBar();
	printf("\n\xba  ?> Pilih menu :                                                       \xba\n");
	printBottomBar();
}

/* membuat file baru */
void createFile() {
    FILE *fp;
    List text[MAX_ROW];
	address pointer = NULL;
    char file_name[20], directory[] = "files/";
    bool exist = false;
 
	system("cls");
	
	printTopBar();
	printf("\n\xba                          TypeApp TEXT EDITOR                           \xba\n");
	printf("\xba                               BUAT FILE                                \xba\n");
	printMidInput();
	printBottomBar();
	
	gotoXY(35, 6);
    scanf("%s", file_name);
    
    if (strlen(file_name) > 20) {
    	printMessage(RED, "!> Nama file maksimal 20 karakter");
	}
    
    strcat(directory, file_name);
    strcat(directory, ".txt");
    
   if (strcmp(directory, "0") == 0) {
    	return;
	} else {
		exist = checkFileExists(directory);
	    if (exist) {
	    	printMessage(RED, "!> File sudah ada");
		} else {
			if ((fp = fopen(directory, "w")) != NULL) {
				printMessage(GREEN, "!> File berhasil dibuat");
				getch();
				
				system("cls");
				readInput(fp, text, &pointer, 0, 0);
			} else {
				printMessage(RED, "!> File gagal dibuat");
			}
			
			fclose(fp);
		}
	}
    
	printf("\n");
	getch();
}

/* membuka file yang dipilih */
void openFile() {
	FILE *fp;
	List text[MAX_ROW];
	address pointer = NULL;
	char file_name[20], directory[] = "files/", c;
	bool exist;
	int row = 0, column = 0;
	
	system("cls");
	
	printTopBar();
	printf("\n\xba                          TypeApp TEXT EDITOR                           \xba\n");
	printf("\xba                               BUKA FILE                                \xba\n");
	printMidInput();
	printBottomBar();
	
	gotoXY(35, 6);
    scanf("%s", file_name);
    
    if (strlen(file_name) > 20) {
    	printMessage(RED, "!> Nama file maksimal 20 karakter");
	}
    
    strcat(directory, file_name);
    strcat(directory, ".txt");
	
	if (strcmp(directory, "0") == 0) {
    	return;
	} else {
		exist = checkFileExists(directory);
	    if (exist) {
	    	if ((fp = fopen(directory, "r+")) != NULL) {
				while ((c = fgetc(fp)) != EOF) {
					inputCharacter(c, &text[row], &column, &pointer);
					if (c == '\n') {
						row++;
						column = 0;
					}
				}
				rewind(fp);
				
				system("cls");
				printText(text, row, column, row);
				readInput(fp, text, &pointer, row, column);
			} else {
				printMessage(RED, "!> File gagal dibuka");
			}
			
			fclose(fp);
		} else {
			printMessage(RED, "!> File tidak ditemukan");
		}
	}
	
	getch();
}

/* menghapus file yang dipilih */
void deleteFile() {
	char file_name[20], directory[] = "files/", confirm;
	int status;
	bool exist;
	
	system("cls");
	
	printTopBar();
	printf("\n\xba                          TypeApp TEXT EDITOR                           \xba\n");
	printf("\xba                               HAPUS FILE                               \xba\n");
	printMidInput();
	printBottomBar();
	
    gotoXY(35, 6);
    scanf("%s", file_name);
    
    if (strlen(file_name) > 20) {
    	printMessage(RED, "!> Nama file maksimal 20 karakter");
	}
    
    strcat(directory, file_name);
    strcat(directory, ".txt");
    
    if (strcmp(directory, "0") == 0) {
    	return;
	} else {
		exist = checkFileExists(directory);
	    if (exist) {
	    	printMessage(GREEN, "!> File ditemukan. Yakin ingin hapus? <Y/T> : ");
	    	confirm = getche();
	    	if (toupper(confirm) == 'Y') {
				status = remove(directory);
			    if (status == 0) {
			        printMessage(GREEN, "!> File berhasil dihapus", 8);
				} else {
			        printMessage(RED, "!> File gagal dihapus", 8);
				}		
			}
		} else {
			printMessage(RED, "!> File tidak ditemukan");
		}
	}
    
	printf("\n");
	getch();
}

/* mengubah nama file tertentu */
void renameFile() {
	char file_name_old[20], file_name_new[20], directory[] = "files/", directory2[] = "files/";
	bool exist;
	
	system("cls");
	
	printTopBar();
	printf("\n\xba                          TypeApp TEXT EDITOR                           \xba\n");
	printf("\xba                             UBAH NAMA FILE                             \xba\n");
	printMidInput();
	printBottomBar();
	
    gotoXY(35, 6);
    scanf("%s", file_name_old);
    
    if (strlen(file_name_old) > 20) {
    	printMessage(RED, "!> Nama file maksimal 20 karakter");
	}
    
    strcat(directory, file_name_old);
    strcat(directory, ".txt");
    
    if (strcmp(directory, "0") == 0) {
    	return;
	} else {
		exist = checkFileExists(directory);
	    if (exist) {
	    	printMessage(GREEN, "!> File ditemukan. Nama file baru : ");
	    	scanf("%s", file_name_new);
	    	
	    	strcat(directory2, file_name_new);
    		strcat(directory2, ".txt");
	    	
	    	if (rename(directory, directory2) == 0) {
	    		printMessage(GREEN, "!> Nama file berhasil diubah", 8);
			} else {
				printMessage(RED, "!> Nama file gagal diubah", 8);
				printf("%s", strerror(errno));
			}
		} else {
			printMessage(RED, "!> File tidak ditemukan");
		}
	}
    
	printf("\n");
	getch();
}

void copyFile(){
	FILE *fp, *fp1;
	char file_name_old[20], file_name_new[20], directory[] = "files/", directory2[] = "files/", c;
	bool exist;
	
	system("cls");
	
	printTopBar();
	printf("\n\xba                          TypeApp TEXT EDITOR                           \xba\n");
	printf("\xba                             DUPLIKASI FILE                             \xba\n");
	printMidInput();
	printBottomBar();
	
	gotoXY(35, 6);
    scanf("%s", file_name_old);
    
    if (strlen(file_name_old) > 20) {
    	printMessage(RED, "!> Nama file maksimal 20 karakter");
	}
    
    strcat(directory, file_name_old);
    strcat(directory, ".txt");
    
    if (strcmp(directory, "0") == 0) {
    	return;
	} else {
		exist = checkFileExists(directory);
	    if (exist) {
	    	printMessage(GREEN, "!> File ditemukan. Nama file baru : ");
	    	scanf("%s", file_name_new);
	    	
	    	strcat(directory2, file_name_new);
    		strcat(directory2, ".txt");
	    	
	    	fp = fopen(directory, "r");
	    	fp1 = fopen(directory2, "w");
	    	
	    	while (!feof(fp)) {
	    		c = getc(fp);
	    		putc(c, fp1);
			}
			
			fclose(fp);
			fclose(fp1);
			printMessage(GREEN, "!> File berhasil diduplikasi", 8);
		} else {
			printMessage(RED, "!> File tidak ditemukan");
		}
	}
    
	printf("\n");
	getch();
}

/* menampilakn deskripsi program */
void aboutProgram() {
	char about[300], shortcut[300];
	FILE *fp;
	int i = 4;
	
	system("cls");
	if ((fp = fopen("aboutProgram.txt","r")) == NULL) {
		printf("\t!> File kosong.\n");
	} else {
		printTopBar();
		printf("\n\xba                          TypeApp TEXT EDITOR                           \xba\n");
		printf("\xba                            TENTANG PROGRAM                             \xba\n");
		printMidBar();
		printf("\n");
		while(fgets(about, sizeof(about), fp)) {
			printf("\xba");
			printf("%s", about);
			gotoXY(73, i);
			printf("\xba");
			gotoXY(0, i);
			i++;
		}
		printBottomBar();
	}
	fclose(fp);
	
	printf("\n\n");
	getch();
}
