#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int *arr;
    int len;
    int space;
}
stack;
void push(struct stack* vect,int k){
    if (vect->space == vect->len){
        if (vect->space == 0){
            vect->arr = (int*)malloc((1)*sizeof(int));
            vect->space ++;
        }
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
        free(vect->arr);
        vect->space = vect->space*2;
        vect->arr = arr;
    }
}
void pop (struct stack* vect){
    int* arr;
    arr = (int*) malloc((vect->space) * sizeof(int));
    for (int i = 0; i < vect->len-1; i++){
        arr[i] = vect->arr[i];
    }
    vect->len--;
    free(vect->arr);
    vect->arr = arr;
}
int main(){
    struct stack vect;
    push(&vect,5);
    push(&vect,3);
    push(&vect,4);
    pop(&vect);
    push(&vect,2);
    for (int i = 0; i < vect.len;i++){
        printf("%d",vect.arr[i]);
    }
}