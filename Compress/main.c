#include <stdio.h>
#include <stdlib.h>
#include "inc/compress.h"
#include "inc/decompress.h"

int main() {
    int type;
    char source[]="D:\\novo.jpg", dest[]="D:\\out.huff";
    char source1[]="D:\\out.huff", dest1[]="D:\\saida.jpg";


    printf("Digite 1 para Compressão ou 2 para Descompressão:\n");
    scanf("%d", &type);
    //getchar();
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
        printf("Onde o arquivo vai ser salvo?\n");
        FILE *archive = fopen(source1, "rb");
        FILE *new_archive = fopen(dest1, "wb");
        start_decompression(archive, new_archive);
        // todo  criar função decompress
    }
    return 0;
}