#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include "instructions.h"
void shuffle(uint64_t *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            uint64_t t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}
unsigned long long int rdtsc()
{
    unsigned int lo, hi;

    __asm__ volatile (".byte 0x0f, 0x31" : "=a" (lo), "=d" (hi));
    return (long long)(((unsigned long long)hi)<<32LL) | (unsigned long long) lo;
}
int main( )
{
    srand(time(0));
//    srand(4);
    uint64_t * array = (uint64_t *) malloc(MAXELEMENTSARR* sizeof(uint64_t));
    for(int i=0;i<MAXELEMENTSARR;i++){
        array[i] = (uint64_t) i;
    }

    shuffle(array,MAXELEMENTSARR);
//    for(int i=0;i<MAXELEMENTSARR;i++){
//        printf("%d ",(int) array[i]);
//    }
    printf("\n");
    uint64_t ans1=0;
    uint64_t ans2=0;
    long long start = rdtsc();
    asmblock(ans1,ans2,array)
    long long stop = rdtsc();
    long long timeTaken = stop -start;
    printf("ans1 %d\n",(int) ans1);
    printf("ans2 %d\n",(int) ans2);
    printf("time taken is %llu\n ",timeTaken/WINDOWSIZE);
    free(array);
    return 0;
}
