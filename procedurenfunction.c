#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

#define MAX_COLUMN 8
#define MAX_ROW 3

void TampilanAwal() {
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                                 MENU                                  ||\n");
	printf("||=======================================================================||\n");
	printf("|| 1. Create File                                                        ||\n");
//	printf("|| 2. Read File                                                          ||\n");
	printf("|| 2. Open File                                                          ||\n");
	printf("|| 3. Delete File                                                        ||\n");    
	printf("|| 4. Copy File                                                          ||\n");          
	printf("|| 5. Rename File                                                        ||\n"); 
	printf("|| 6. Exit Program                                                       ||\n");
	printf("||=======================================================================||\n\n");	
}

void Create() {
    FILE *fp;   /* file pointer*/
    char fName[35];
    int c;
 
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                                 CREATE                                ||\n");
	printf("||=======================================================================||\n");
	printf(" Enter File Name	: ");
    scanf("%s",fName);
 
    /*creating (open) a file, in “w”: write mode*/    
	printf("\nType the text and press Ctrl+S to save.\n");
	fp = fopen(fName, "w");
//	while(1){
//		in=getch();
//		if(in==19){
//			goto end;
//		}
//		if(in==13){
//			in='\n';
//			printf("\n\t");
//			fputc(in,fp);
//		}
//		else{
//			printf("%c",in);
//			fputc(in,fp);
//		}
//	}
	ReadInput(fp);
	
	fclose(fp);
}

void Read(){
	FILE *fp;
	char in, fName[35], pilih;
	
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                                  READ                                 ||\n");
	printf("||=======================================================================||\n");
	printf("  Enter File Name	: ");
	scanf("%s", fName);
	fp = fopen(fName, "r");
	
	if((fp = fopen(fName, "r"))==NULL){
		printf("\n\tFile not found!!!");
		goto end1;
	}
	while(!feof(fp)){
		in = getc(fp);
		printf("%c",in);
	}	
	end1:
	fclose(fp);
	printf("\n\n\tPress any key to continue. . .\n");
	getch();
}

void Edit(){
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                                  EDIT                                 ||\n");
	printf("||=======================================================================||\n");
	printf("  Enter File Name	: ");
	scanf("%s", fName);
	
	fp = fopen(fName, "r");
	if(fp==NULL){
		printf("\n\tFile not found!");
		fclose(fp);
	goto end2;
	}
	while(!feof(fp)){
		in = getc(fp);
		printf("%c",in);
	}
	fclose(fp);
	
	printf("\n\t\tType the text and press Ctrl+S to append.\n");
	fp=fopen(fName,"a");
	ReadInput(fp);
	
	end2: 
	fclose(fp);
}
	
void Delete() {
	char fName[35];
	int status;
	
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                                DELETE                                 ||\n");
	printf("||=======================================================================||\n");
	printf("  Enter File Name	: ");
	scanf("%s", fName);
	
	status = remove(fName);
    if(status==0){
        printf("\n\tFile Deleted Successfully!!!");
	}
    else{
        printf("\n\tError Occurred!!!");
	}
	
	system("pause");
}

void CopyFile(){
	printf("\n  Enter File Name : ");
	scanf("%s", fName);
	printf("  Enter the new file name to copy : ");
	scanf("%s",fNew);
	fp = fopen(fName,"r");
	fp1 = fopen(fNew,"w");
	while(!feof(fp))
	{
		in=getc(fp);
		putc(in,fp1);
	}
	fclose(fp1);
}

void RenameFile(){
	int status;
	
	printf("\n  Enter File Name : ");
	scanf("%s", fName);
	printf("  Enter the new file name to rename : ");
	scanf("%s",fNew);
	
	status = rename(fName, fNew);
}

void ReadInput(FILE *fp) {
	char c, teks[MAX_ROW][MAX_COLUMN + 2] = {};
	int row = 0, column = 0, i;
	
	while (1) {
		if (column == MAX_COLUMN) {
			printf("\n");
			teks[row++][column] = '\n';
			column = 0;
		}
		
		if (row == MAX_ROW) {
			break;
		}
		
		c = getch();
		
		if (c == 0x08) {
			if (column < 0) {
				column = 0;
			}
	    	teks[row][column] = 0x00;
	    	column -= 1;
	    	printf("\b");
	    } else if (c == 72) {
	    	printf("\x1b[A");
		} else if (c == 80) {
			printf("\x1b[B");
		} else if (c == 13) {
	    	printf("\n");
	    	teks[row][column++] = '\n';
	    	row += 1;
	    	column = 0;
	    } else if (c == 19) {
	    	printf("\nFile saved.\n");
	    	break;
		} else {
	    	teks[row][column++] = c;
	    	printf("%c", c);
		}
	};
	
	for (i = 0; i < MAX_ROW; i++) {
		fputs(teks[i], fp);
	}
	
	system("pause");
}
