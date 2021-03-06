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
            hashes[i] += f->poids[i]*hashes[i] + str[j];
            /*hashes[i] += str[j]*(pow(f->poids[i], length-j+1));*/
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
    free(hashes);
}

int is_member_filter(filter *f, char *str){
    clock_t start, end;
    start = clock();
    assert(f != NULL && str != NULL);
    unsigned *test = (unsigned*)malloc(sizeof(unsigned)*f->k);
    int i;
    hash(f, str, test);
    for(i = 0; i < f->k; i++){
        if(get_bitarray(f->bitArray, test[i] % f->m) != 1){
            free(test);
            return 0;
        } 
    }
    free(test);
    end = clock();
    unsigned long total = (end - start) / CLOCKS_PER_SEC;
    printf("Finished Bloom filter in %ld s\n", total);
    return 1;
}