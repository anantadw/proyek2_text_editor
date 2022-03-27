//// C program to check mouse status
//#include <conio.h>
//#include <dos.h>
//#include <graphics.h>
//#include <stdio.h>
//union REGS in, out;
//
//// Function to implement the functionality
//// of detecting Mouse
//void detectMouse()
//{
//	in.x.ax = 0;
//
//	// Invoke interrupt (in86 method
//	// description mentioned above)
//	int86(0X33, &in, &out);
//
//	if (out.x.ax == 0)
//		printf("\nMouse Failed To Initialize");
//	else
//		printf("\nMouse was Successfully Initialized");
//}
//
//// Driver Code
//int main()
//{
//	clrscr();
//
//	int gdriver = DETECT, gmode;
//
//	// Method to enable graphics
//	initgraph(&gdriver, &gmode, "c:\tc\bgi");
//
//	// Function Call
//	detectMouse();
//	getch();
//
//	// Close graphics mode
//	closegraph();
//
//	return 0;
//}
//
//// backspace Keyboard
//
//if(col!=2)
//{	 // col=col-2;
//	printf("\b");
//	  col--;
//}
//else if(col==2 && row!=2)
//{		  printf("\b");
//	col=76;
//	row--;
//}
//else if(col==2 && row==2)
//{
//		printf("\b");
//	col=2;
//	row=2;
//
//}
//gotoxy(col,row);
//ch=' ';
//break;
//
//// deleted
//
//if(row==0 || col==0);
//	else
//	{
//	printf("\b");
//	}
//	continue;
//
//
#include <iostream>

using namespace std;

int main() 
{
    char c='x';
    int position = 0; //starts from the left most position
    int temp =0;
    cout << "*" << endl;
    cout << "Enter: l (Move Left) or r (Move Right) or x (exit): " << endl;
    cin >> c;

while (c != 'x')
{
    if((c == 'r')||(c=='l'))
    {
        if(c == 'r')
        {
        position++;
        }
        else if(c == 'l')
        {
        if(position==0) 
            position=0;
        else
            position--;
        }
        temp=position;
        while(temp--!=0)
        {
        cout << " "; //print space
        }
        cout << "*" <<endl;
    }   
    else
    {
        cout << "Wrong character entered\n" << endl;
    }
    cout << "Enter: l (Move Left) or r (Move Right) or x (exit): "<< endl;
    cin >> c;
}
return 0;
