// Online C compiler to run C program online
#include <stdio.h>

void InsertQ(int item, int *rear,int *q){
    if(rear==QUE_SIZE-1){
        printf("Stack is Overflow");
        return;
    }
    *rear = *rear + 1;
    q[*rear] = item;
    // q[++(*rear)] = item;
}

int deleteQ(int *front, int *rear, int *q){
    if(*front>*rear) return -1;
    return gq[(*front)++];
}

void display(int front,int rear ,int * q){
    if(*front>*rear){
        printf("The Queue is Empty");
        return;
    }
    
}




int main() {
    // Write C code here
    printf("Try programiz.pro");

    return 0;
}
