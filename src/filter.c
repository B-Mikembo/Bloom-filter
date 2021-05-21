#include "../includes/filter.h"
#include "../includes/bitarray.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

filter *create_filter(int m, int k){
    filter *f = (filter *)malloc(sizeof(filter));
    f->bitArray = create_bitarray(m);
    f->m = m;
    f->k = k;
    return f;
}

void free_filter(filter *f){
    free_bitarray(f->bitArray);
    free(f);
}

void hash(filter *f, char *str, unsigned hashes[]){
    assert(f != NULL);
    /*TODO*/
}

void add_filter(filter *f, char *str){
    assert(f != NULL);

}

int is_member_filter(filter *f, char *str){
    assert(f != NULL);
    
}