#pragma once
#ifdef _WIN32
#else
// found on http://stackoverflow.com/a/7469410/1579481

#include <termios.h>
#include <stdio.h>

static struct termios old, newp;

/* Initialize new terminal i/o settings */
extern void initTermios(int echo);


/* Restore old terminal i/o settings */
extern void resetTermios(void);


/* Read 1 character - echo defines echo mode */
extern char getche(int echo);


/* Read 1 character without echo */
extern char getch(void);

/* Read 1 character with echo */
extern char getche(void);

#endif