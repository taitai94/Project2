#ifdef _WIN32
#else
#include "conio-linux.h"

void initTermios(int echo)
{
	tcgetattr(0, &old); /* grab old terminal i/o settings */
	newp = old; /* make new settings same as old settings */
	newp.c_lflag &= ~ICANON; /* disable buffered i/o */
	newp.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
	tcsetattr(0, TCSANOW, &newp); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
	tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getche(int echo)
{
	char ch;
	initTermios(echo);
	ch = getchar();
	resetTermios();
	return ch;
}

/* Read 1 character without echo */
char getch(void)
{
	return getche(0);
}

/* Read 1 character with echo */
char getche(void)
{
	return getche(1);
}

#endif