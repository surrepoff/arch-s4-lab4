#include "mySimpleComputer.h"
#include "myTerm.h"
#include <iostream>
#include <cstring>

using namespace std;


void frame(int x1, int y1, int x2, int y2)
{
    mt_gotoXY(x1,y1);
    printf("┌");
    for (int i = x1 + 1; i < x2; i++) printf("─");
    printf("┐");
    
    mt_gotoXY(x1,y2);
    printf("└");
    for (int i = x1 + 1; i < x2; i++) printf("─");
    printf("┘");

    for (int i = y1 + 1; i < y2; i++) {mt_gotoXY(x1,i);printf("│");}

    for (int i = y1 + 1; i < y2; i++) {mt_gotoXY(x2,i);printf("│");}  
}

void print_window() {
    int rows,cols;
    mt_getscreensize(&rows,&cols);

    mt_setbgcolor(GRAY);
    mt_setfgcolor(BLACK);
    mt_clrscr();
    
    frame(1, 1, 63, 12);
    mt_gotoXY(30,1);
    printf("Memory");
    
    mt_gotoXY(2,2);
    
    int index = 0;
    int value;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mt_gotoXY(3 + 6 * j, 2 + i);
            sc_memoryGet(index, &value);
            index++;
            printf("+%.2X%.2X ", (value >> 8), (value & 0x7F));
        }
    }
    
    frame(64, 1, 85, 3);

    mt_gotoXY(69, 1);
    printf("accumulator");

    mt_gotoXY(72, 2);
    printf("+9999");

    frame(64, 4, 85, 6);

    mt_gotoXY(66, 4);
    printf("instructionCounter");

    mt_gotoXY(72, 5);
    printf("+0000");

    frame(64, 7, 85, 9);
    
    mt_gotoXY(71, 7);
    printf("Operation");

    mt_gotoXY(71, 8);
    printf("+00 : 00");

    frame(64, 10, 85, 12);
    
    mt_gotoXY(73, 10);
    printf("Flags");

    mt_gotoXY(72, 11);
    printf("O E V M");
    
    frame(1, 13, 47, 23);
    
    frame(48, 13, 85, 23);

    mt_gotoXY(49, 13);
    printf("Keys:");

    mt_gotoXY(49, 14);
    printf("l  - load");
    
    mt_gotoXY(49, 15);
    printf("s  - save");

    mt_gotoXY(49, 16);
    printf("r  - run");

    mt_gotoXY(49, 17);
    printf("t  - step");

    mt_gotoXY(49, 18);
    printf("r  - reset");

    mt_gotoXY(49, 19);
    printf("F5 - accumulator");

    mt_gotoXY(49, 20);
    printf("F6 - instructionCounter");
}

int main() {
    mt_clrscr();

    int rows,cols;
    mt_getscreensize(&rows,&cols);

    sc_memoryInit();

    print_window();
    mt_gotoXY(0,rows);
    return 0;
}
