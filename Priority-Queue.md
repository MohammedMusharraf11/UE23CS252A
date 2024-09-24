## Implementation of Asecdinng Priority Queue using Arrays 
```c
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an element in the priority queue
struct element {
    int pty;   // Priority
    int data;  // Data value
};

typedef struct element element_t;

// Function prototypes
void pqinsert(element_t *, int, int, int *);
element_t pqdelete(element_t *, int *);
void qdisplay(element_t *, int);
void init(element_t *, int *);

int main() {
    int ch, pty, x;
    element_t pq[100];
    int count = 0;

    while (1) {
        printf("\n1..Insert");
        printf("\n2..Remove");
        printf("\n3..Display");
        printf("\n4..EXIT");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter the priority: ");
                scanf("%d", &pty);
                printf("Enter the value: ");
                scanf("%d", &x);
                pqinsert(pq, x, pty, &count);
                break;
            case 2:
                element_t deletedElement = pqdelete(pq, &count);
                if (deletedElement.data != -1) {
                    printf("Deleted element: data=%d, priority=%d\n", deletedElement.data, deletedElement.pty);
                }
                break;
            case 3:
                qdisplay(pq, count);
                break;
            case 4:
                exit(0);
        }
    }
}

// Function to insert an element into the priority queue
void pqinsert(element_t *pq, int x, int pty, int *count) {
    if (*count >= 100) { // Check for queue overflow
        printf("\nQueue is full. Cannot insert.\n");
        return;
    }

    element_t temp;
    temp.data = x;
    temp.pty = pty;

    int j = *count - 1;

    // Shift elements to maintain priority order
    while (j >= 0 && pq[j].pty > temp.pty) {
        pq[j + 1] = pq[j];
        j--;
    }
    
    pq[j + 1] = temp; // Insert the new element
    (*count)++;
}

// Function to delete an element from the priority queue
element_t pqdelete(element_t *pq, int *count) {
    element_t temp;
    
    // If the queue is empty
    if (*count == 0) {
        printf("\nEmpty Queue..\n");
        temp.data = -1; // Indicate no data
        temp.pty = -1;  // Indicate no priority
        return temp;
    } else {
        temp = pq[0]; // Get the first element (highest priority)
        for (int i = 1; i < *count; i++) { // Shift elements
            pq[i - 1] = pq[i];
        }
    }
    
    (*count)--; // Decrease the count of elements
    return temp;
}

// Function to display elements in the priority queue
void qdisplay(element_t *pq, int count) {
    if (count == 0) {
        printf("\nEmpty Queue...\n");
    } else {
        printf("\nElements in the priority queue:\n");
        for (int i = 0; i < count; i++) {
            printf("Value: %d, Priority: %d\n", pq[i].data, pq[i].pty);
        }
    }
}
```
