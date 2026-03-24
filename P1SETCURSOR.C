#include <dos.h>

void mi_pausa(){
   union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs);
}

void setcursortype(int tipo){
    union REGS in, out;
    in.h.ah = 1;

    switch(tipo){
        case 0: // invisible
            in.h.ch = 0x20;
            in.h.cl = 0;
            break;
        case 1: // normal
            in.h.ch = 6;
            in.h.cl = 7;
            break;
        case 2: // grueso
            in.h.ch = 0;
            in.h.cl = 7;
            break;
    }

    int86(0x10, &in, &out);
}

int main(){
    setcursortype(0);
    mi_pausa();
    setcursortype(2);
    mi_pausa();
    setcursortype(1);
    mi_pausa();

    return 0;
}   