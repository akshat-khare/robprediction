//
// Created by codebat on 07/09/19.
// a and d
//

#ifndef LAB1C_INSTRUCTIONS_H
#define LAB1C_INSTRUCTIONS_H
// #define loadInitialIndex "mov $0, %%rax\n\t"  \
//                         "shl $3, %%rax\n\t" \
//                         "mov $5000, %%rsi\n\t"  \
//                         "shl $3, %%rsi\n\t" \
//                         "mov $6000, %%rdi\n\t"  \
//                         "shl $3, %%rdi\n\t" \
//                         "mov $7000, %%r8\n\t"  \
//                         "shl $3, %%r8\n\t" \
//                         "mov $8000, %%r9\n\t"  \
//                         "shl $3, %%r9\n\t" \
//                         "mov $9000, %%r10\n\t"  \
//                         "shl $3, %%r10\n\t" \
//                         "mov $4000, %%r11\n\t"  \
//                         "shl $3, %%r11\n\t" \
//                         "mov $3000, %%rbx\n\t"  \
//                         "shl $3, %%rbx\n\t" \
//                         "mov $2000, %%r12\n\t"  \
//                         "shl $3, %%r12\n\t" \
//                         "mov $1000, %%r13\n\t"  \
//                         "shl $3, %%r13\n\t" \
//                         "mov $1000000, %%r14\n\t"  \
//                         "shl $3, %%r14\n\t" \
//                         "mov $2000000, %%r15\n\t"  \
//                         "shl $3, %%r15\n\t" \
//                         "mov $100000, %%rdx\n\t" \
//                         "shl $3, %%rdx\n\t"
#define loadInitialIndex "mov $0, %%rax\n\t"  \
                        "shl $3, %%rax\n\t" \
                        "mov $4, %%rsi\n\t" \
                        "mov $6, %%rdi\n\t" \
                        "mov $100000, %%rdx\n\t" \
                        "shl $3, %%rdx\n\t"
#define loadArrayFromEntry1 "mov %2, %%rcx\n\t"
#define outputLastIndex "mov %%rax, %0\n\t" \
                        "mov %%rdx, %1\n\t"
// #define nop1 "nop\n\t"
#define nop1 "add %%rsi, %%rdi\n\t"
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
#define nop5 \
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
#define movonlyrsi "mov (%%rcx, %%rsi, 8), %%rsi\n\t"
#define movonlyrdi "mov (%%rcx, %%rdi, 8), %%rdi\n\t"
#define movonlyr8 "mov (%%rcx, %%r8, 8), %%r8\n\t"
#define movonlyr9 "mov (%%rcx, %%r9, 8), %%r9\n\t"
#define movonlyr10 "mov (%%rcx, %%r10, 8), %%r10\n\t"
#define movonlyr11 "mov (%%rcx, %%r11, 8), %%r11\n\t"
#define movonlyrbx "mov (%%rcx, %%rbx, 8), %%rbx\n\t"
#define movonlyr12 "mov (%%rcx, %%r12, 8), %%r12\n\t"
#define movonlyr13 "mov (%%rcx, %%r13, 8), %%r13\n\t"
#define movonlyr14 "mov (%%rcx, %%r14, 8), %%r14\n\t"
#define movonlyr15 "mov (%%rcx, %%r15, 8), %%r15\n\t"
#define movonlyd "mov (%%rcx, %%rdx,8), %%rdx\n\t"
#define nopi \
        nop100 nop10 nop10 nop10 nop5 nop1 nop1
// #define window1 movonlya movonlyrsi movonlyrdi movonlyr8 movonlyr9 movonlyr10 movonlyr11 movonlyrbx movonlyr12 movonlyr13 movonlyr14 movonlyr15 nopi movonlyd
#define window1 movonlya nopi movonlyd
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
