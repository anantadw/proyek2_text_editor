// C program to check mouse status
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>
union REGS in, out;

// Function to implement the functionality
// of detecting Mouse
void detectMouse()
{
	in.x.ax = 0;

	// Invoke interrupt (in86 method
	// description mentioned above)
	int86(0X33, &in, &out);

	if (out.x.ax == 0)
		printf("\nMouse Failed To Initialize");
	else
		printf("\nMouse was Successfully Initialized");
}

// Driver Code
int main()
{
	clrscr();

	int gdriver = DETECT, gmode;

	// Method to enable graphics
	initgraph(&gdriver, &gmode, "c:\tc\bgi");

	// Function Call
	detectMouse();
	getch();

	// Close graphics mode
	closegraph();

	return 0;
}

