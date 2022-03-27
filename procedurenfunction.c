#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

void TampilanAwal(){
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                                 MENU                                  ||\n");
	printf("||=======================================================================||\n");
	printf("|| 1. Create File                                                        ||\n");
	printf("|| 2. Read File                                                          ||\n");
	printf("|| 3. Edit File                                                          ||\n");
	printf("|| 4. Delete File                                                        ||\n");       
	printf("|| 5. Exit Program                                                       ||\n");
	printf("||=======================================================================||\n");
	printf("                       © Copyright ● Restful JSon                          \n\n");
	
}

void Create(){
  	printf("\n");
	printf("||||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
	printf("||                                 CREATE                                ||\n");
	printf("||=======================================================================||\n");
	printf(" Enter File Name	: ");
    scanf("%s",fName);
 
    /*creating (open) a file, in “w”: write mode*/    
	printf("\n\t\t\t\t\t\tEnter the text and press Ctrl+S to save.\n");
	fp = fopen(fName, "w");
	while(1){
		in=getch();
	if(in==19){
		goto end;
	}
	if(in==13){
		in='\n';
		printf("\n");
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
	return 0;
	printf ("Press any key to continue. . .");
}

void Read(){
	printf("\n\n\n");
	printf("||=======================================================================||\n");	
	printf("||                              TEKS EDITOR                              ||\n");
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
	
	printf("\n\t\t\t\t\t\t\t\t\tType the text and press Ctrl+S to append.\n");
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
	int status;
	
	printf("\n\n\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");	
	printf("\t\t\t\t\t\t||                              TEKS EDITOR                              ||\n");
	printf("\t\t\t\t\t\t||                                DELETE                                 ||\n");
	printf("\t\t\t\t\t\t||=======================================================================||\n");
	printf("\t\t\t\t\t\t  Enter File Name	: ");
	scanf("%s", fName);
	
	status = remove(fName);
    if(status==0){
        printf("\n\t\t\t\t\t\tFile Deleted Successfully!!!");
        printf("\n\n\t\t\t\t\t\tPress any key to continue. . .");
        getch();
	}
    else{
        printf("\n\t\t\t\t\t\tError Occurred!!!");
	}
}

void Backspace(){
	char fName[35], ch;
    int i = 0;
	while(ch != '\n')    // terminates if user hit enter
	{
    ch = getchar();
    // if this is a backspace character, 
    // lower the index and delete the last char
    if(ch == 0x08){
       fName[--i] = 0x00;
    }else{
       // other chars will increment the index and fill the current char buffer
       fName[i++] = ch;
    }
	}
}

void Copy(){
	bool isCtrl;
	int in;
	
	while(1){
		if (in == 19){
			isCtrl = true;
		}
		if ((in == 67) && (isCtrl = true)){
			printf("Ctrl + C");
			fputc(in, fp);
		}
	}
	
}




