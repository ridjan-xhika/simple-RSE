#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 1000

int check_args(int argc, char *argv[]);
int help();
FILE *open_file(char *filename);
void read_file(FILE *file, char *buffer, int size);
void rewrite_file(char *filepath, char *buffer, int size);

