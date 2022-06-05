#include "menu.h"

/* menampilkan pilihan menu */
void printMenu() {
	system("cls");
	printf("||=======================================================================||\n");
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                                 MENU                                  ||\n");
	printf("||=======================================================================||\n");
	printf("|| 1. Buat file                                                          ||\n");
	printf("|| 2. Buka file                                                          ||\n");
	printf("|| 3. Hapus file                                                         ||\n");
	printf("|| 4. Ubah nama file                                                     ||\n");
	printf("|| 5. Duplikasi file                                                     ||\n");
	printf("|| 6. Tentang program                                                    ||\n");
	printf("|| 7. Keluar program                                                     ||\n");
	printf("||=======================================================================||\n\n");
}

/* membuat file baru */
void createFile() {
    FILE *fp;
    char file_name[30];
    bool exist = false;
 
	system("cls");
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                               BUAT FILE                               ||\n");
	printf("||=======================================================================||\n");
	printf("\n\t?> Nama file (dengan ekstensi)\n");
	printf("\t   Masukkan '0' untuk kembali : ");
    scanf("%s", file_name);
       
	if (strcmp(file_name, "0") == 0) {
    	return;
	} else {
		exist = checkFileExists(file_name);
	    if (exist) {
	    	printf("\t!> File sudah ada.\n");
		} else {
			if ((fp = fopen(file_name, "w")) != NULL) {
				printf("\t!> File berhasil dibuat.\n\n");
				system("pause");
				inputFile(fp);
			} else {
				printf("\t!> File gagal dibuat.\n");
			}
			
			fclose(fp);
		}
	}
    
	printf("\n");
	system("pause");
}

/* membuka file yang dipilih */
void openFile() {
	FILE *fp;
	char file_name[30], c;
	bool exist;
	List text[MAX_ROW];
	address pointer = NULL;
	int row = 0, column = 0;
	
	system("cls");
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                               BUKA FILE                               ||\n");
	printf("||=======================================================================||\n");
	printf("\n\t?> Nama file (dengan ekstensi)\n");
	printf("\t   Masukkan '0' untuk kembali : ");
	scanf("%s", file_name);
	
	if (strcmp(file_name, "0") == 0) {
    	return;
	} else {
		exist = checkFileExists(file_name);
	    if (exist) {
	    	if ((fp = fopen(file_name, "r+")) != NULL) {
				while ((c = fgetc(fp)) != EOF) {
					inputCharacter(c, &text[row], &column, &pointer);
					if (c == '\n') {
						row++;
						column = 0;
					}
				}
				rewind(fp);
				system("cls");
				editFile(fp, text, row, column, &pointer);
			} else {
				printf("\t!> File gagal dibuka.\n");
			}
			
			fclose(fp);
		} else {
			printf("\t!> File tidak ditemukan.\n");
		}
	}
	
	system("pause");
}

/* menghapus file yang dipilih */
void deleteFile() {
	char file_name[30], confirm;
	int status;
	bool exist;
	
	system("cls");
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                               HAPUS FILE                              ||\n");
	printf("||=======================================================================||\n");
	printf("\n\t?> Nama file (dengan ekstensi)\n");
	printf("\t   Masukkan '0' untuk kembali : ");
    scanf("%s", file_name);
    
    if (strcmp(file_name, "0") == 0) {
    	return;
	} else {
		exist = checkFileExists(file_name);
	    if (exist) {
	    	printf("\t!> File ditemukan.\n");
	    	printf("\t?> Yakin ingin menghapus? <Y/T> : ");
	    	confirm = getche();
	    	if (toupper(confirm) == 'Y') {
				status = remove(file_name);
			    if (status == 0) {
			        printf("\n\t!> File berhasil dihapus.\n");
				} else {
			        printf("\n\t!> File gagal dihapus.\n");
				}		
			}
		} else {
			printf("\t!> File tidak ditemukan.\n");
		}
	}
    
	printf("\n");
	system("pause");
}

/* mengubah nama file tertentu */
void renameFile() {
	char file_name_old[30], file_name_new[30];
	bool exist;
	
	system("cls");
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                            UBAH NAMA FILE                             ||\n");
	printf("||=======================================================================||\n");
	printf("\n\t?> Nama file lama (dengan ekstensi)\n");
	printf("\t   Masukkan '0' untuk kembali : ");
    scanf("%s", file_name_old);
    
    if (strcmp(file_name_old, "0") == 0) {
    	return;
	} else {
		exist = checkFileExists(file_name_old);
	    if (exist) {
	    	printf("\t!> File ditemukan.\n");
	    	printf("\t?> Nama file baru (dengan ekstensi): ");
	    	scanf("%s", file_name_new);
	    	
	    	if (rename(file_name_old, file_name_new) == 0) {
	    		printf("\t!> Nama file berhasil diubah.\n");
			} else {
				printf("\t!> Nama file gagal diubah.\n");
			}
		} else {
			printf("\t!> File tidak ditemukan\n");
		}
	}
    
	printf("\n");
	system("pause");
}

void copyFile(){
	FILE *fp, *fp1;
	char file_name_old[30], file_name_new[30];
	char exist;
	
	system("cls");
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                             DUPLIKASI FILE                            ||\n");
	printf("||=======================================================================||\n");
	printf("\n\t?> Nama file lama (dengan ekstensi)\n");
	printf("\t   Masukkan '0' untuk kembali : ");
    scanf("%s", file_name_old);
    
    if (strcmp(file_name_old, "0") == 0) {
    	return;
	} else {
		exist = checkFileExists(file_name_old);
	    if (exist) {
	    	printf("\t!> File ditemukan.\n");
	    	printf("\t?> Nama file baru (dengan ekstensi): ");
	    	scanf("%s", file_name_new);
	    	
	    	fp = fopen(file_name_old, "r");
	    	fp1 = fopen(file_name_new, "w");
	    	
	    	while (!feof(fp)){
	    		exist = getc(fp);
				putc(exist, fp1);	
			}
			fclose(fp1);
			printf("\t!> File berhasil diduplikasi.\n");
			
		} else {
			printf("\t!> File tidak ditemukan\n");
		}
	}
    
	printf("\n");
	system("pause");
}

/* menampilakn deskripsi program */
void aboutProgram() {
	char about[300];
	FILE *fp;
	
	system("cls");
	if ((fp = fopen("aboutProgram.txt","r")) == NULL) {
		printf("\t!> File kosong.\n");
	} else {
		while(fgets(about, sizeof(about), fp)) {
			printf("%s", about);
		}
	}
	fclose(fp);
	
	printf("\n\n");
	system("pause");
}
