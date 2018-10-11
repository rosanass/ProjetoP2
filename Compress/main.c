#include <stdio.h>
#include <stdlib.h>
#include "inc/compress.h"
#include "inc/decompress.h"

int main() {
    int type;
    char source[]="C:\\Users\\Rosana\\Documents\\", dest[]="C:\\Users\\Rosana\\Documents\\";
    char source1[]="C:\\Users\\Rosana\\Documents\\", dest1[]="C:\\Users\\Rosana\\Documents\\";


    printf("Digite 1 para Compressão ou 2 para Descompressão:\n");
    scanf("%d", &type);
    if(type == 1)
    {
        FILE *archive = fopen(source, "rb");
        FILE *new_archive = fopen(dest, "wb");
        start_compression(archive, new_archive);
        fclose(archive);
        fclose(new_archive);
    }
    else if(type == 2)
    {
        FILE *archive = fopen(source1, "rb");
        FILE *new_archive = fopen(dest1, "wb");
        start_decompression(archive, new_archive);
    }
    return 0;
}