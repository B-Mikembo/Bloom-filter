#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include "filter.h"

#define TAILLE_CHAINE 1000

int main(int argc, char const *argv[])
{
    
    FILE *file = fopen(argv[1], "r");
    int k = 3 + rand() % 10;
    filter *f = create_filter(1000, k);
    char *line = (char *) malloc(sizeof(char) * TAILLE_CHAINE);
    while(fgets(line, TAILLE_CHAINE, file) != NULL){
        printf("Vérification du mot de passe dans le filtre....\n");
        if(is_member_filter(f, line)){
            printf("Peut-être\n");
        }
        else{
            printf("Non\n");
            add_filter(f,line);
            printf("Ajout du mot de passe => %s\n", line);
        }
    }
    printf("\n");
    fclose(file);
    free(line);
    return 0;
}
