#ifndef CHIP8_H
#define CHIP8_H

#include <string>
#include <vector>

#define SYS_MEM       0x1000
#define NUM_REGISTERS 0x10
#define STACK_SIZE    0x10

typedef unsigned char BYTE ;
typedef unsigned short int WORD ;

const int ROMSIZE = 0xFFF ;

class Chip8
{
    public:
        Chip8();
        ~Chip8();
        int Load(FILE *fp);
        void ExecOp();
        void KeyPress();
        void KeyRelease();

    private:
        WORD NextOp();
        void Beep();
};

#endif
