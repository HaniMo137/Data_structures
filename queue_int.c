#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int *arr;
    int len;
    int space;
}
queue;
void push(struct queue* vect,int k){
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
void pop (struct queue* vect){
    int* arr;
    arr = (int*) malloc((vect->space) * sizeof(int));
    for (int i = 0; i < vect->len-1; i++){
        arr[i] = vect->arr[i+1];
    }
    vect->len--;
    free(vect->arr);
    vect->arr = arr;
}
int peak(struct queue *vect){
    return vect->arr[0];
}
int main(){
    struct queue vect;
    push(&vect,5);
    push(&vect,10);
    push(&vect,7);
    printf("%d \n", peak(&vect));
    pop(&vect);
    for (int i = 0; i < vect.len; i++){
        printf("%d ", vect.arr[i]);
    }
}