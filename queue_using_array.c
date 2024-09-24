// Online C compiler to run C program online
#include <stdio.h>

int insert(int x, int *q, int *r, int *f) {
    if (*r == SIZE - 1) {  // Queue is full
        printf("Queue is Full");
        return -1;
    } else {
        if (*f == -1) {  // If inserting the first element
            *f = 0;
        }
        *r = *r + 1;    // Increment rear
        q[*r] = x;      // Insert the element at the rear
        // q[++(*r)] =x;
        return 0;
    }
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
