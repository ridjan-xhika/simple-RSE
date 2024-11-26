#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *open_file(char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: file not found\n");
        exit(1);
    }
    return file;
}