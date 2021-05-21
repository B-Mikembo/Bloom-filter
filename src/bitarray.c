#include "../includes/bitarray.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


bitarray *create_bitarray(int m){
    bitarray *new_bitarray = (bitarray *)malloc(sizeof(bitarray));
    new_bitarray->bitarray = (unsigned char *)malloc(sizeof(unsigned char) * m);
    new_bitarray->m = m;
    return new_bitarray;
}

void free_bitarray(bitarray *a){
    free(a->bitarray);
    free(a);
}

void set_bitarray(bitarray *a, int pos){
    assert(a != NULL && a->bitarray != NULL && pos < a->m);
    a->bitarray[pos] = 1;
}

void reset_bitarray(bitarray *a, int pos){
    assert(a != NULL && a->bitarray != NULL && pos < a->m);
    a->bitarray[pos] = 0;
}

int get_bitarray(bitarray *a, int pos){
    assert(a != NULL && a->bitarray != NULL && pos < a->m);
    return a->bitarray[pos];
}

void clear_bitarray(bitarray *a){
    assert(a != NULL && a->bitarray != NULL && pos < a->m);
    int i;
    for(i = 0; i < a->m; i++){
        a->bitarray[i] = 0;
    }
}