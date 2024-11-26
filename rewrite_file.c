#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rewrite_file(char *filepath, char *buffer, int size)
{
    FILE *file = fopen(filepath, "w");

    int i = 0;
    while (i < size)
    {
        fputc(buffer[i], file);
        i++;
    }
}