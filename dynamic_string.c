#include <stdio.h>
#include <stdlib.h>
struct string
{
    int len;
    char* arr;
    int space;
}
string;
void append(struct string* vect,char k){
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
int main(){
    int n;
    scanf("%d", &n);
    struct string vect;
    for (int i = 0; i < n; i++){
        char k;
        scanf("%c", &k);
        append(&vect,k);
    }
    for (int i = 0; i < n; i++){
        printf("%c",vect.arr[i]);
    }
}
