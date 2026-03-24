#include <dos.h>

void pixel(int x, int y, unsigned char color){
	union REGS in, out;

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

	setvideomode(4);

	pixel(10, 10, 1);
    pixel(20, 20, 2);
    pixel(30, 30, 3);

	mipausa();

	setvideomode(3);

	return 0;
}
