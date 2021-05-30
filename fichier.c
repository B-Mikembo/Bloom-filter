#include "fichier.h"

void read_data(FILE *file){
    char c;
    while((c=fgetc(file))!=EOF){
        printf("%c",c);
    }
    printf("\n");
    close_file(file);
}

void close_file(FILE *file){
    fclose(file);
}