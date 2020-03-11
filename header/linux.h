#ifndef LINUX_H_
#define LINUX_H_
 
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
 
int linux_kbhit(void)
{
    struct termios oldt, newt;
    int ch;
 
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
 
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
 
    ch = getchar();
 
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
 
    return ch;
}

int linux_getch(void){
    // int ch;
    // struct termios buf, save;
    // tcgetattr(0,&save);
    // buf = save;
    // buf.c_lflag &= ~(ICANON|ECHO);
    // buf.c_cc[VMIN] = 1;
    // buf.c_cc[VTIME] = 0;
    // tcsetattr(0, TCSAFLUSH, &buf);
    // ch = getchar();
    // tcsetattr(0, TCSAFLUSH, &save);
    // return ch;

    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;

}

void gotoxy(int x, int y) {
     printf("\033[%d;%df",y,x);
     fflush(stdout);
}

 
#endif
