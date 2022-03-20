//clear_screen=\E[H\E[J
//cursor_address=\E[%i%p1%d;%p2%dH
//set_a_background=\E[4%p1%dm
//set_a_foreground=\E[3%p1%dm
//cursor_invisible=\E[?25l\E[?1c
//cursor_visible=\E[?25h\E[?8c

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

enum colors
{
  BLACK, RED, GREEN, ORANGE, INDIGO, PURPLE, BLUE, GRAY, WHITE
};

int mt_clrscr(void)
{
    printf("\033[H\E[J");
    return 0;
}

int mt_gotoXY (int x, int y)
{
    printf("\033[%d;%dH", y, x);
    return 0;
}

int mt_getscreensize (int * rows, int * cols)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    if (w.ws_row<= 0 || w.ws_col <= 0) return -1;
    
    *rows = w.ws_row;
    *cols = w.ws_col;
    return 0;
}

int mt_setfgcolor (int color)
{
    printf("\033[3%dm", color);
    return 0;
}

int mt_setbgcolor (int color)
{
    printf("\033[4%dm", color);
    return 0;
}
