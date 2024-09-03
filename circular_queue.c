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
