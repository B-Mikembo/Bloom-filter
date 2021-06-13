#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "filter.h"
#include "visualtree.h"

#define TAILLE_CHAINE 1000

int main(int argc, char const *argv[])
{
    node* t = NULL;
    
    FILE *file = fopen(argv[3], "r");

    /*int k = 3 + rand() % 10;*/
    filter *f = create_filter(atoi(argv[1]), atoi(argv[2]));

    char *line = (char *) malloc(sizeof(char) * TAILLE_CHAINE);

    double words = 0;
    double falsepos = 0;

    while(fgets(line, TAILLE_CHAINE, file) != NULL){
        printf("Vérification du mot de passe dans le filtre....\n");
        words++;
        if(is_member_filter(f, line)){
            printf("Peut-être\n");
            if(find_avl(t, line) == NULL){
                printf("Non\n");
                add_filter(f,line);
                t = insert_avl(t, line);
                printf("Ajout du mot de passe => %s\n", line);
                falsepos++;
            }
        }
        else{
            printf("Non\n");
            add_filter(f,line);
            t = insert_avl(t, line);
            printf("Ajout du mot de passe => %s\n", line);
        }
    }

    printf("%d mots ont été ajouté, il y a %d faux postitifs. Le ration est de %f", (int) words, (int) falsepos, falsepos/words);

    write_tree(t);
    printf("\n");

    fclose(file);
    free(line);
    free_tree(t);
    free_filter(f);
    return 0;
}
