<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
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
=======
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "filter.h"
#include "visualtree.h"

#define TAILLE_CHAINE 1000

int main(int argc, char const *argv[])
{
    node* t = NULL;
    
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
            t = insert_avl(t, line);
            printf("Ajout du mot de passe => %s\n", line);
        }
    }

    write_tree(t);
    printf("\n");

    fclose(file);
    free(line);
    free_tree(t);
    return 0;
}
>>>>>>> 0b8d74ca08fd3851d39e67a95ee9861030d00b2e
