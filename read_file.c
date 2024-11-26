#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(FILE *file, char *buffer, int size)
{
    int i = 0;
    while (i < size)
    {
        buffer[i] = fgetc(file);
        i++;
    }
}