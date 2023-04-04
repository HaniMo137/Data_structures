#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Creating the nodes of the graph
typedef struct node
{
    int value;
    struct node *next;
}node;
//add connected element (edge)
void add(node *sui,int k){
    if (sui->next ==  NULL){
        node *hh = (node*)malloc((1)*sizeof(node));
        hh->value = k;
        hh->next = NULL;
        sui->next = hh;
        return;
    }
    add(sui->next, k);
}
//function show to see the elements connected to the node
void show(node *sui){
    if (sui == NULL){
        return;
    }
    printf("%d ",sui->value);
    show(sui->next);
}
//Queue
typedef struct queue
{
    int *arr;
    int len;
    int space;
}
queue;
void push(queue* vect,int k){
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
void pop (queue* vect){
    int* arr;
    arr = (int*) malloc((vect->space) * sizeof(int));
    for (int i = 0; i < vect->len-1; i++){
        arr[i] = vect->arr[i+1];
    }
    vect->len--;
    free(vect->arr);
    vect->arr = arr;
}
//function insert to add the connected elements to the Queue
void insert(queue* vect,node *hh, int* arr){
    if (hh->next == NULL){
        return;
    }
    if (arr[hh->next->value-1] == 0){
        push(vect, hh->next->value);
        arr[hh->next->value-1] = 1;
        }
    insert(vect, hh->next, arr);
}
// checking if the graph is connected or not
bool connected(int* arr, int n){
    for (int i = 0; i < n; i++){
        if (arr[i] == 0){
            return false;
        }
    }
    return true;
}
int main(){
    node *nodes;
    int n,e;
    scanf("%d %d",&n,&e);
    nodes = (node*)malloc((n)*sizeof(node));
    int *arr;
    arr = (int*)malloc((n)*sizeof(int));
    for (int i = 0; i < n; i++){
        nodes[i].value = i+1;
        nodes[i].next = NULL;
    }
    for (int i = 0; i < e; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        add(&nodes[a-1],b);
        add(&nodes[b-1],a);
    }
    queue bfs;
    push(&bfs,1);
    arr[0] = 1;
    while (bfs.len != 0){
        insert(&bfs,&nodes[bfs.arr[0]-1],arr);
        pop(&bfs);
    }
    //checking if the graph is a tree or not
    if ((connected(arr, n))&&(e == n-1)){
        printf("The graph is a tree");
    } 
    else{
        printf("the graph isn't a tree");
    }
}