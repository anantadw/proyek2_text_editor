#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	int PilihMenu;
	
	menu:
	TampilanAwal();
	printf("\tPilih (angka) :   ");
	scanf("%d",&PilihMenu);
	
	if (PilihMenu == 1){
		system("cls");
		Create();
		system("cls");
		goto menu;
	}
//	else if (PilihMenu == 2){
//		Read();
//		system("cls");
//		goto menu;
//	}
	else if (PilihMenu == 2) {
		system("cls");
		Edit();
		system("cls");
		goto menu;
	} 
	else if (PilihMenu == 3){
		system("cls");
		Delete();
		system("cls");
		goto menu;
	}else if (PilihMenu == 4) {
		CopyFile();
		system("cls");
		goto menu;
	}else if (PilihMenu == 5){
		RenameFile();
		system("cls");
		goto menu;
	}else {
		exit (0);
	}
}
