#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void function1(void);
static void function2(void);

int main(int argc , char * argv[])
{

    if(atexit(function1)!=0)
        printf("atexit function1 fail\n");
    printf("message 0\n");

    if(atexit(function2)!=0)
        printf("atexit function2 fail \n");
    if(atexit(function1)!=0)
        printf("atexit function1 fail \n");
    printf("message 1 \n");
    exit(0);
}
static void function1(void){
    printf("function1 called \n");
}
static void function2 (void){
    printf("function2 called \n");
}