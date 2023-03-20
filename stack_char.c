#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int len;
    char* arr;
    int space;
}
stack;
void push(struct stack* vect,char k){
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
void pop (struct stack* vect){
    char* arr;
    arr = (char*) malloc((vect->space) * sizeof(char));
    for (int i = 0; i < vect->len-2; i++){
        arr[i] = vect->arr[i];
    }
    arr[vect->len-1]= '\0';
    vect->len--;
    free(vect->arr);
    vect->arr = arr;
}
int main(){
    struct stack vect;
    push(&vect,'h');
    push(&vect,'a');
    push(&vect,'a');
    pop(&vect);
    push(&vect,'n');
    push(&vect,'p');
    pop(&vect);
    push(&vect,'i');
    for (int i = 0; i < vect.len;i++){
        printf("%c",vect.arr[i]);
    }
}