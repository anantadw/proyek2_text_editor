#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void TampilanAwal(){
	printf("\n\n\n\n\n\n");
	printf("\t\t\t||=======================================================================||\n");	
	printf("\t\t\t||                              TEKS EDITOR                              ||\n");
	printf("\t\t\t||                                 MENU                                  ||\n");
	printf("\t\t\t||=======================================================================||\n");
	printf("\t\t\t|| 1. Create File                                                        ||\n");
	printf("\t\t\t|| 2. Read File                                                          ||\n");
	printf("\t\t\t|| 3. Edit File                                                          ||\n");
	printf("\t\t\t|| 4. Delete File                                                        ||\n");       
	printf("\t\t\t|| 5. Exit Program                                                       ||\n");
	printf("\t\t\t||=======================================================================||\n\n");	
}

void Create(){
    FILE *fp;   /* file pointer*/
    char fName[35];
    int c;
 
	printf("\n\n\n\n\n\n");
	printf("\t\t\t||=======================================================================||\n");	
	printf("\t\t\t||                              TEKS EDITOR                              ||\n");
	printf("\t\t\t||                                 CREATE                                ||\n");
	printf("\t\t\t||=======================================================================||\n");
	printf("\t\t\t  Enter File Name	: ");
    scanf("%s",fName);
 
    /*creating (open) a file, in “w”: write mode*/
    fp=fopen(fName,"w");
    WriteFile();
}

void Read(){
	FILE *fp;
	char in, fName[35], pilih;
	
	printf("\n\n\n\n\n\n");
	printf("\t\t\t||=======================================================================||\n");	
	printf("\t\t\t||                              TEKS EDITOR                              ||\n");
	printf("\t\t\t||                                  OPEN                                 ||\n");
	printf("\t\t\t||=======================================================================||\n");
	printf("\t\t\t  Enter File Name	: ");
	scanf("%s", fName);
	fp = fopen(fName, "r");

	if(fp==NULL){
		printf("\n\tFile not found!");
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

void Delete() {
	char fName[35];
	int status;
	
	printf("\t\t\t  Enter File Name	: ");
	scanf("%s", fName);
	
	
	status = remove(fName);
    if(status==0)
        printf("\nFile Deleted Successfully!");
    else
        printf("\nError Occurred!");
}


void WriteFile(){
	fp = fopen(fName, "w");
	
	printf("\n\t\t\t\t\t\tWRITE MODE");
	printf("\n\t\t\t\t\t\tFor Save File Press Ctrl+S\n");
	
	while(1){
		in = getchar();
		fputc(in, fp);
		if(in == '/'){
			fclose(fp);
			break;
		}
		fclose(fp);
	}
	getch();
	return 0;
	printf ("Press any key to continue. . .");
//	goto menu;	
}

void AddFile(){
	fp = fopen(fName, "w");
	
	printf("\t\t\tADD MODE\n");
	printf("\t\t\tFor Save File Press Ctrl+S");
	
	while((in = getchar())!=EOF){
		putc(in, fp);
	}
	
	fclose(fp);
	}

