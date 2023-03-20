#include <stdio.h>
#include <stdlib.h>
struct list
{
    int len;
    int* arr;
    int space;
}
list;

void append(struct list* vect,int k){
    if (vect->space == 0){
            vect->arr = (int*)malloc((1)*sizeof(int));
            vect->space ++;
        }
    if (vect->space != vect->len){
        vect->arr[vect->len] = k;
        vect->len++;
    }
    else {
        int* arr;
        arr = (int*) malloc((vect->space*2) * sizeof(int));
        for (int i = 0; i < vect->len; i++){
            arr[i] = vect->arr[i];
        }
        arr[vect->len] = k;
        vect->len++;
        vect->space = vect->space*2;
        free(vect->arr);
        vect->arr = arr;
    }
}
