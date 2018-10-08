#include <stdio.h>
#include <stdlib.h>
#include "inc/compress.h"
#include "inc/decompress.h"

int main() {
    int type;
    char source[]="D:\\x.jpg", dest[]="D:\\x.huff";
    char source1[]="D:\\out1.txt", dest1[]="D:\\teste1d.txt";

    printf("Digite 1 para Compressão ou 2 para Descompressão:\n");
    scanf("%d", &type);
    //getchar();
    if(type == 1)
    {
        //printf("Onde está o arquivo de origem?\n");
        //scanf("%s", source);
        //printf("Onde o arquivo vai ser salvo?\n");
        //scanf("%s", dest);

        FILE *archive = fopen(source, "rb");
        FILE *new_archive = fopen(dest, "wb");
        start_compression(archive, new_archive);
        fclose(archive);
        fclose(new_archive);
    }
    else if(type == 2)
    {
        //printf("Onde está o arquivo de origem?\n");
        //scanf("%s", source);
        printf("Onde o arquivo vai ser salvo?\n");
        //scanf("%s", dest);
        FILE *archive = fopen(source1, "rb");
        FILE *new_archive = fopen(dest1, "wb");
        start_decompression(archive, new_archive);
        // todo  criar função decompress
    }
    return 0;
}