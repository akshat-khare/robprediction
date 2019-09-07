//
// Created by codebat on 07/09/19.
// a and d
//

#ifndef LAB1C_INSTRUCTIONS_H
#define LAB1C_INSTRUCTIONS_H
#define loadInitialIndex "mov $0, %%rax\n\t"  \
                        "shl $3, %%rax\n\t" \
                        "mov $100000, %%rdx\n\t" \
                        "shl $3, %%rdx\n\t"
#define loadArrayFromEntry1 "mov %2, %%rcx\n\t"
#define outputLastIndex "mov %%rax, %0\n\t" \
                        "mov %%rdx, %1\n\t"
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
#define movonlya "mov (%%rcx, %%rax,8), %%rax\n\t"
#define movonlyd "mov (%%rcx, %%rdx,8), %%rdx\n\t"
#define nopi \
        nop100 nop100 nop10 nop10 nop10
#define window1 movonlya nopi movonlyd nopi
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
#define asmblock(ans1,ans2,array) \
__asm__ volatile (loadInitialIndex\
                  loadArrayFromEntry1\
                  window\
: "=r" (ans1), "=r" (ans2)\
: "m" (array));
#endif //LAB1C_INSTRUCTIONS_H
