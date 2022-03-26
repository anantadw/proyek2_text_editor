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
	system("cls");
	
	if (PilihMenu == 1){
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
		Edit();
		system("cls");
		goto menu;
	} 
	else if (PilihMenu == 3){
		Delete();
		system("cls");
		goto menu;
	}else if (PilihMenu == 4) {
		exit(1);
	}
}

