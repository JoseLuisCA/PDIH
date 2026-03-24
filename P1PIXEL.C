#include <dos.h>

void pixel(int x, int y, unsigned char color){
	union REGS in, out;

	/* BIOS 10h, AH=0Ch: escribir pixel en modo grafico. */
	in.h.ah = 0x0C;
	in.h.al = color;
	in.h.bh = 0;
	in.x.cx = x;
	in.x.dx = y;
	int86(0x10, &in, &out);
}

static void setvideomode(unsigned char mode){
	union REGS in, out;
	in.h.ah = 0;
	in.h.al = mode;
	int86(0x10, &in, &out);
}

static void mipausa(){
	union REGS in, out;
	in.h.ah = 1;
	int86(0x21, &in, &out);
}

int main(){
	int i;

	/* Modo 4: grafico CGA 320x200 con 4 colores. */
	setvideomode(4);

	for(i = 0; i < 100; i++){
		pixel(20 + i, 20 + i, 1);
		pixel(120 + i, 20 + i, 2);
		pixel(220 + i, 20 + i, 3);
	}

	mipausa();

	setvideomode(3);

	return 0;
}
