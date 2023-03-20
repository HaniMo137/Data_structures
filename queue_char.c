#include <stdio.h>
#include <stdlib.h>
struct queue
{
    char *arr;
    int len;
    int space;
}
queue;
void push(struct queue* vect,char k){
    if (vect->space == 0){
            vect->arr = (char*)malloc((2)*sizeof(char));
            vect->space += 2;
            vect->len++;
        }
    if (vect->space != vect->len){
        vect->arr[vect->len-1] = k;
        vect->arr[vect->len] = '\0';
        vect->len++;
    }
    else {
        char* arr;
        arr = (char*) malloc((vect->space*2) * sizeof(char));
        for (int i = 0; i < vect->len-1; i++){
            arr[i] = vect->arr[i];
        }
        arr[vect->len-1] = k;
        arr[vect->len] = '\0';
        vect->len++;
        free(vect->arr);
        vect->space = vect->space*2;
        vect->arr = arr;
    }
}
void pop (struct queue* vect){
    char* arr;
    arr = (char*) malloc((vect->space) * sizeof(char));
    for (int i = 0; i < vect->len-1; i++){
        arr[i] = vect->arr[i+1];
    }
    vect->len--;
    free(vect->arr);
    vect->arr = arr;
}
char peak(struct queue *vect){
    return vect->arr[0];
}
