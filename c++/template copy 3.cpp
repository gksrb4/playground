#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <malloc.h>
#include <cstring>
#include <windows.h>

pthread_t ntid;
char *global_str;

void cleanup(void *arg)
{
    printf("--- Cleanup Handler --- \n");
    printf("global_str : %s\n", global_str);
    free(global_str);
    printf("free allocated memory\n");
    printf("--- Cleanup Handler END --- \n");
}

void* thr_fn(void *arg)
{
    int res;
    int i;

    global_str = malloc(sizeof(char)*100);

    pthread_cleanup_push(cleanup, NULL);

    strcpy(global_str, "GLOBAL");
    for(i=0; i<3; i++){
        switch(i){
            case 0: strcat(global_str, " memory"); break;
            case 1: strcat(global_str, " allocated"); break;
            case 2: strcat(global_str, " !"); break;
        }   
        printf("thr_fn thread : Allocate step %d: %s\n", i, global_str);
        Sleep(1);
    }   
    pthread_cleanup_pop(1);
    pthread_exit(0);

    return ;
}

int main()
{
    int err;
    int tret;

    if (pthread_create(&ntid, NULL, thr_fn, (void*)1) < 0)
        perror("thread create error:");

    pthread_join(ntid, (void**)&tret);
    printf("main thread : global_str : %s\n", global_str);

    return 0;
}