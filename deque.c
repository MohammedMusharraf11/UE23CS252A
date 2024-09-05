// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

// Function to check if the deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Function to check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element at the front of the deque
void insertFront(int key) {
    if (isFull()) {
        printf("Overflow! Unable to insert new elements\n");
        return;
    }
    
    // If deque is initially empty
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    // Circular increment to insert at the front when front is at 0
    else if (front == 0) {
        front = MAX - 1;
    }
    // Decrease front by 1
    else {
        front--;
    }
    
    deque[front] = key;
    printf("Inserted %d at the front\n", key);
}

void deleteFront(){
    if(isEmpty()){
        printf("UnderFlow\n");
        return;
    }
    
    int removed = deque[front];
    if(front==rear){
        front = -1;
        rear = -1;
    } else if(front==MAX - 1){
        front = 0;
    } else{
        front++;
    }
    printf("The deleted Element: %d",removed);
    
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    
    printf("Elements in the deque are:\n");
    
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        
        if (i == rear)
            break;
        
        i = (i + 1) % MAX; // Circular increment
    }
    printf("\n");
}
int main() {
    // Sample test case to insert elements at the front
    insertFront(10);
    insertFront(20);
    deleteFront();
    insertFront(30);
    display(deque);

    return 0;
}
