#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	int PilihMenu;
	
	menu:
	TampilanAwal();
	printf("\t\t\t\t Pilih (angka) :   ");
	scanf("%d",&PilihMenu);
	system("cls");
	
	if (PilihMenu == 1){
		Create();
		system("cls");
		goto menu;
	}
	else if (PilihMenu == 2){
		Read();
		system("cls");
		goto menu;
	}
	else if (PilihMenu == 3) {
//		Edit();
	} 
	else if (PilihMenu == 4){
		Delete();
	}else if (PilihMenu == 5) {
		exit(1);
	}
	else exit (0);
}
