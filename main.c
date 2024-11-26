//this is a simple program to test the RLE compression algorithm
//this proggram is open source and can be used for any purpose
//the author is jokr

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "include.h"

int check_args(int argc, char *argv[]){
    if (argc <= 1){
        printf("Usage: rle <input file> <output file> or rle -h for help\n");
        exit(-1);
    }

    if((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)){
        help();
        return 1;
    }

    if(argc != 3){
        printf("Usage: rle <input file> <output file> or rle -h for help\n");
        exit(-1);
    }

    return 0;
}

int help(){
    printf("Usage: rle <input file> <output file>\n\n");
    
    printf("Run-Length Encoding (RLE) Program\n\n");

    printf("This program compresses or decompresses data using the Run-Length Encoding (RLE) algorithm.\n");
    printf("RLE is a simple form of data compression in which consecutive data elements (runs) are stored as a single data value and count.\n");
    printf("It is particularly effective for data with many repeated elements.\n\n");

    printf("Usage instructions:\n");
    printf("1. <input file>: The file containing the data to be compressed or decompressed.\n");
    printf("   - If the input file is uncompressed text, the program will compress it into RLE format.\n");
    printf("   - If the input file is already in RLE format, the program will decompress it.\n");
    
    printf("2. <output file>: The file where the compressed or decompressed data will be saved.\n");
    printf("   - The program will create this file if it doesn't already exist.\n");
    printf("   - If the file exists, it will be overwritten with the new data.\n\n");

    printf("Example of usage:\n");
    printf("   rle input.txt output.rle\n");
    printf("   - Compresses 'input.txt' and saves the result in 'output.rle'.\n\n");
    
    printf("   rle input.rle decompressed.txt\n");
    printf("   - Decompresses 'input.rle' and saves the result in 'decompressed.txt'.\n\n");
    
    printf("Important Notes:\n");
    printf("1. The program assumes the input file contains only printable characters.\n");
    printf("2. The output file will be in either compressed or decompressed format based on the input data.\n");
    printf("3. Ensure that the correct file type is used for compression or decompression to avoid errors.\n\n");
    
    printf("For further details, please consult the documentation or contact the developer.\n");

    return 0;
}

char *manage_buffer(char *filename){
    FILE *file;
    char *buffer;
    int size;
    struct stat file_stat;
    
    stat(filename, &file_stat);
    size = file_stat.st_size;

    buffer = malloc(size);
    if (buffer == NULL){
        printf("Error: memory allocation failed\n");
        exit(1);
    }

    file = open_file(filename);
    read_file(file, buffer, size);
    buffer[size] = '\0';
    close(file);

    return buffer;
}

int find_malloc_size(char *buffer, int size){
    int malloc_size = 0;

    for(int i = 0; i < size; i++){
        while(buffer[i] == buffer[i+1]){
            i++;
        }
        malloc_size++;
    }
    return malloc_size;
}

char int_to_char(int num){
    char str;
    str = num + '0';
    return str;
}

char *compress(char *buffer){
    char *moded_buffer = malloc(sizeof(char *) * find_malloc_size(buffer, strlen(buffer)));
    int j = 0;
    int i = 0;
    int cnt = 0;

    while(buffer[j] != '\0'){
        moded_buffer[i] = buffer[j];
        i++;
        while(buffer[j] == buffer[j+1]){
            cnt++;
            j++;
        }
        cnt++;
        if (cnt > 1){
        moded_buffer[i] = int_to_char(cnt);
            i++;
        }
        cnt = 0;
        j++;
    }
    return moded_buffer;
}

int main(int argc, char *argv[])
{
    int j = check_args(argc, argv);
    char *buffer = manage_buffer(argv[1]);
    char *moded_buffer = compress(buffer);
    
    rewrite_file(argv[2], moded_buffer, strlen(moded_buffer));

    return 0;
}