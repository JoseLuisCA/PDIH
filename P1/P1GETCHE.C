#include <dos.h>

void getche(){
	union REGS in, out;

	in.h.ah = 1;
	int86(0x21, &in, &out);
    in.h.ah = 2; 
    in.h.dl = out.h.al;
    int86(0x21, &in, &out);
}

int main(){
	getche();
	return 0;
}
