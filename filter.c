#include "filter.h"


filter *create_filter(int m, int k){
    filter *f = (filter *)malloc(sizeof(filter));
    f->bitArray = create_bitarray(m);
    f->poids = (int*)malloc(sizeof(int)*k);
    int i;
    for(i = 0; i < k; i++){
        f->poids[i] = rand() % (255-2+1)+2;
    }
    f->m = m;
    f->k = k;
    return f;
}

void free_filter(filter *f){
    free_bitarray(f->bitArray);
    free(f->poids);
    free(f);
}

void hash(filter *f, char *str, unsigned hashes[]){
    assert(f != NULL);
    int i,j;
    int length = strlen(str);
    for(i=0; i< f->k; i++){
        hashes[i] = 0;
        for(j = 0; str[j] != '\0'; j++){
            hashes[i] = str[j]*(pow(f->poids[i], length-j+1));
        }
    }
}

void add_filter(filter *f, char *str){
    assert(f != NULL && str != NULL);
    unsigned *hashes = (unsigned*)malloc(sizeof(unsigned)*f->k);
    int i;
    hash(f, str, hashes);
    for(i = 0; i < f->k; i++){
        set_bitarray(f->bitArray, hashes[i]% f->m);
    }
}

int is_member_filter(filter *f, char *str){
    assert(f != NULL && str != NULL);
    unsigned *test = (unsigned*)malloc(sizeof(unsigned)*f->k);
    int i;
    hash(f, str, test);
    for(i = 0; i < f->k; i++){
        if(get_bitarray(f->bitArray, test[i] % f->m) != 1){
            return 0;
        } 
    }
    return 1;
}