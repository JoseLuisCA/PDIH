#include <dos.h>

static unsigned char color_texto = 7;
static unsigned char color_fondo = 0;

void textcolor(unsigned char color){
    color_texto = color & 0x0F;
}

void textbackground(unsigned char color){
    color_fondo = color & 0x0F;
}

void clrscr(){
    union REGS in, out;
    in.h.ah = 0x06;
    in.h.al = 0;
    in.h.bh = (color_fondo << 4) | color_texto;
    in.h.ch = 0;
    in.h.cl = 0;
    in.h.dh = 24;
    in.h.dl = 79;
    int86(0x10, &in, &out);
}

void cputchar(char c){
    union REGS in, out;

    in.h.ah = 0x09;
    in.h.al = (unsigned char)c;
    in.h.bl = (color_fondo << 4) | color_texto;
    in.h.bh = 0;
    in.x.cx = 1;
    int86(0x10, &in, &out);
}

int main(){
    textbackground(1);
    textcolor(10);
    clrscr();
    cputchar('E');
    return 0;
}
