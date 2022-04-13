#include "conio.h"

// -----

void clrscr(void)
{
	// Clears the console

	printf("\x1b[2J");

} // clrscr ()

// -----

void gotoxy(int x, int y)
{
	// Moves the cursor to line y, column x

	printf("\x1b[%d;%df", y, x);

} // gotoxy ()

// ----- end of file conio.h

