#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "config.h"
#include "utility.h"

void dbg()
{
    printf("\n============== DEBUG ================\n");
}

FILE* secureOpen(char *pathFile, char *mode)
{
    FILE* fp = NULL;
    fp = fopen(pathFile, mode);
    if(fp == NULL) exit(EXIT_FAILURE);

    return fp;
}

char *smalloc(int num, int size)
{
    char *array;
    array = malloc(num*size);

    if(array == NULL) return 0;

    return array;
}

int sclose()
{
    printf("Closed\n");
    return 1;
}
