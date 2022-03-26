#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

void TampilanAwal(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");	
	printf("\t\t\t\t\t\t||                              TEKS EDITOR                              ||\n");
	printf("\t\t\t\t\t\t||                                 MENU                                  ||\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");
	printf("\t\t\t\t\t\t|| 1. Create File                                                        ||\n");
	printf("\t\t\t\t\t\t|| 2. Read File                                                          ||\n");
	printf("\t\t\t\t\t\t|| 3. Edit File                                                          ||\n");
	printf("\t\t\t\t\t\t|| 4. Delete File                                                        ||\n");       
	printf("\t\t\t\t\t\t|| 5. Exit Program                                                       ||\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n\n");	
}

void Create(){
    FILE *fp;   /* file pointer*/
    int c;
 
	printf("\n\n\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");	
	printf("\t\t\t\t\t\t||                              TEKS EDITOR                              ||\n");
	printf("\t\t\t\t\t\t||                                 CREATE                                ||\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");
	printf("\t\t\t\t\t\t Enter File Name	: ");
    scanf("%s",fName);
 
    /*creating (open) a file, in “w”: write mode*/    
	printf("\n\t\tType the text and press Ctrl+S to save.\n");
	fp = fopen(fName, "w");
	while(1){
		in=getch();
	if(in==19){
		goto end;
	}
	if(in==13){
		in='\n';
		printf("\n\t");
		fputc(in,fp);
	}
	else{
		printf("%c",in);
		fputc(in,fp);
	}
	}
	end: 
	fclose(fp);
	getch();
	printf ("Press any key to continue. . .");
}

void Read(){
	FILE *fp;
	char in, fName[35], pilih;
	
	printf("\n\n\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");	
	printf("\t\t\t\t\t\t||                              TEKS EDITOR                              ||\n");
	printf("\t\t\t\t\t\t||                                  READ                                 ||\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");
	printf("\t\t\t\t\t\t  Enter File Name	: ");
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
	printf("\n\n\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");	
	printf("\t\t\t\t\t\t||                              TEKS EDITOR                              ||\n");
	printf("\t\t\t\t\t\t||                                  EDIT                                 ||\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");
	printf("\t\t\t\t\t\t  Enter File Name	: ");
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
	while(1){
		in=getch();
	if(in==19){
		goto end2;
	}
	if(in==13){
		in='\n';
		printf("\n\t");
		fputc(in,fp);
	}
	else{
		printf("%c",in);
		fputc(in,fp);
	}
	}
	end2: 
	fclose(fp);
	getch();
}
	
void Delete() {
	char fName[35];
	int status;
	
	printf("\n\n\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");	
	printf("\t\t\t\t\t\t||                              TEKS EDITOR                              ||\n");
	printf("\t\t\t\t\t\t||                                DELETE                                 ||\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");
	printf("\t\t\t  Enter File Name	: ");
	scanf("%s", fName);
	
	status = remove(fName);
    if(status==0){
        printf("\n\t\t\t\t\t\tFile Deleted Successfully!!!");
        printf("\n\n\t\t\t\t\t\tPress any key to continue. . .");
	}
    else{
        printf("\n\t\t\t\t\t\tError Occurred!!!");
	}
}






