#include <stdio.h>
#include <stdlib.h>
#include "inc/compress.h"

int main() {
    int type;
    char source[]="C:\\Users\\Rosana\\Documents\\rosana.txt", dest[]="C:\\Users\\Rosana\\Documents\\destino.txt";
    printf("Digite 1 para Compressão ou 2 para Descompressão:\n");
    scanf("%d", &type);
    getchar();
    if(type == 1)
    {
        //printf("Onde está o arquivo de origem?\n");
        //scanf("%s", source);
        //printf("Onde o arquivo vai ser salvo?\n");
        //scanf("%s", dest);

        FILE *archive = fopen(source, "rb");
        FILE *new_archive = fopen(dest, "wb");
        start_compression(archive, new_archive);
        // todo  criar função compress
    }
    else if(type == 2)
    {
        //printf("Onde está o arquivo de origem?\n");
        //scanf("%s", source);
        printf("Onde o arquivo vai ser salvo?\n");
        scanf("%s", dest);
        FILE *archive = fopen(source, "rb");
        FILE *new_archive = fopen(dest, "wb");
        //start_decompress(archive, new_archive);
        // todo  criar função decompress
    }
    return 0;
}