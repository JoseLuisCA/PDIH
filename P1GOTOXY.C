#include <dos.h>

void gotoxy(int x, int y){
    union REGS in, out;
    in.h.ah = 2;
    in.h.dh = y;
    in.h.dl = x;
    in.h.bh = 0;
    int86(0x10, &in, &out);
}

int main(){
    gotoxy(10,5);
    return 0;
}