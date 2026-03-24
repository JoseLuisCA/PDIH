#include <dos.h>

void setvideomode(unsigned char modo){
    union REGS in, out;
    in.h.ah = 0;
    in.h.al = modo;
    int86(0x10, &in, &out);
}

unsigned char getvideomode(){
    union REGS in, out;
    in.h.ah = 0X0F;
    int86(0x10, &in, &out);
    return out.h.al;
}

int main(){
    setvideomode(4);
    printf("Modo de video actual: %d\n", getvideomode());
    return 0;
}
