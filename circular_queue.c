#include <stdio.h>

#define QUEUE_SIZE 10

void InsertQ(int item, int *front, int *rear, int *queue) {
    if ((*rear + 1) % QUEUE_SIZE == *front) {
        printf("Queue is Overflow\n");
        return;
    }
    *rear = (*rear + 1) % QUEUE_SIZE;
    queue[*rear] = item;
    if (*front == -1) {
        *front = 0;  // Set front to 0 if it was initially -1 (queue was empty)
    }
}

int deleteQ(int *front, int *rear, int *queue) {
    if (*front == -1) {
        printf("Queue is Underflow\n");
        return -1; // Returning -1 indicates underflow
    }
    int item = queue[*front];
    if (*front == *rear) {
        // Queue becomes empty after this deletion
        *front = -1;
        *rear = -1;
    } else {
        *front = (*front + 1) % QUEUE_SIZE;
    }
    return item;
}

void display(int front, int rear, int *queue) {
    if (front == -1) {
        printf("The Queue is Empty\n");
        return;
    }
    
    printf("Queue contents: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % QUEUE_SIZE;
    }
    printf("\n");
}

int main() {
    int queue[QUEUE_SIZE];
    int front = -1, rear = -1;

    // Example usage
    InsertQ(10, &front, &rear, queue);
    InsertQ(20, &front, &rear, queue);
    InsertQ(30, &front, &rear, queue);

    display(front, rear, queue);

    printf("Deleted element: %d\n", deleteQ(&front, &rear, queue));
    
    display(front, rear, queue);
    
    InsertQ(60, &front, &rear, queue);
    
    display(front, rear, queue);
    
    printf("Deleted element: %d\n", deleteQ(&front, &rear, queue));

    return 0;
}


#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int start = -1;
int end = -1;
int qSize = 0;

void push(int item) {
    if(qSize == MAX_SIZE) {  // Queue is full
        printf("The Queue is Full\n");
        return;
    }
    if(qSize == 0) {  // First element
        start = 0;
        end = 0;
    } else {
        end = (end + 1) % MAX_SIZE;  // Circular increment
    }
    queue[end] = item;
    qSize++;
}

int pop() {
    if(qSize == 0) {  // Queue is empty
        printf("Queue is Empty!!\n");
        return -1;  // Return an invalid value or error code
    }
    
    int del = queue[start];
    
    if(qSize == 1) {  // After removing the last element, reset the queue
        start = -1;
        end = -1;
    } else {
        start = (start + 1) % MAX_SIZE;  // Circular increment
    }
    qSize--;
    return del;
}

int main() {
    printf("Popped element: %d\n", pop());
    push(10);
    push(20);
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());  
    return 0;
}

