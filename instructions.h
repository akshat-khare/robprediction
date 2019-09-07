//
// Created by codebat on 07/09/19.
//

#ifndef LAB1C_INSTRUCTIONS_H
#define LAB1C_INSTRUCTIONS_H
#define loadInitialIndex "mov $0, %%rax\n\t"  "shl $3, %%rax\n\t"
#define loadArrayFromEntry1 "mov %1, %%rcx\n\t"
#define outputLastIndex "mov %%rax, %0"
#define nop1 "nop\n\t"
#define MAXELEMENTSARR 100000000
//#define MAXELEMENTSARR 20
#define WINDOWSIZE 10000
#define nop10 \
        nop1 \
        nop1 \
        nop1 \
        nop1 \
        nop1 \
        nop1 \
        nop1 \
        nop1 \
        nop1 \
        nop1
#define nop50 \
        nop10 \
        nop10 \
        nop10 \
        nop10 \
        nop10
#define nop100 \
        nop10 \
        nop10 \
        nop10 \
        nop10 \
        nop10 \
        nop10 \
        nop10 \
        nop10 \
        nop10 \
        nop10
#define movonly "mov (%%rcx, %%rax,8), %%rax\n\t"
#define nopi \
        nop100 nop100 nop100
#define window1 movonly nopi
#define window10 \
        window1 \
        window1 \
        window1 \
        window1 \
        window1 \
        window1 \
        window1 \
        window1 \
        window1 \
        window1
#define window100 \
        window10 \
        window10 \
        window10 \
        window10 \
        window10 \
        window10 \
        window10 \
        window10 \
        window10 \
        window10
#define window1000 \
        window100 \
        window100 \
        window100 \
        window100 \
        window100 \
        window100 \
        window100 \
        window100 \
        window100 \
        window100
#define window10000 \
        window1000 \
        window1000 \
        window1000 \
        window1000 \
        window1000 \
        window1000 \
        window1000 \
        window1000 \
        window1000 \
        window1000
#define window window10000
#define asmblock(outputVar, arr) \
__asm__ volatile (loadInitialIndex\
                  loadArrayFromEntry1\
                  window\
                  outputLastIndex\
: "=r" (ans)\
: "m" (array));
#endif //LAB1C_INSTRUCTIONS_H
