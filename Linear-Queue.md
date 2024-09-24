# Important Notes for Linear Queue

**Queue follows FIFO**

## Array-Based Queue Implementation

1. **Fixed Size Limitation**:
   - A linear queue has a fixed size, and when the rear reaches the end, no more elements can be inserted, even if there are empty spaces at the front. This can lead to inefficiency.

2. **Queue Overflow**:
   - The queue is considered **full** when the rear reaches `SIZE - 1`. You should always check for this condition before inserting an element.

3. **Queue Underflow**:
   - The queue is **empty** when both front (`f`) and rear (`r`) are `-1`. Always check for this condition before attempting to delete an element.

4. **Front and Rear Pointers**:
   - `f` (front) points to the position of the first element in the queue.
   - `r` (rear) points to the position of the last element in the queue.
   - After an element is deleted, `f` is incremented to point to the next element.
   - If `f == r`, the queue contains only one element.

5. **Inserting an Element**:
   - Always check if the queue is full before inserting.
   - If the queue is empty (i.e., `f == -1` and `r == -1`), set `f = 0` and `r = 0` before inserting the first element.
   - For subsequent inserts, increment `r` and insert the element.

6. **Deleting an Element**:
   - Always check if the queue is empty before deleting.
   - After deleting an element, increment the front pointer (`f++`). If `f` surpasses `r`, reset both `f` and `r` to `-1` to mark the queue as empty.

7. **Inefficiency**:
   - **Linear queues** do not reuse the freed-up spaces once elements are deleted. If many deletions happen from the front, the queue will seem full even if there are empty slots at the beginning.
   - Consider using a **circular queue** for better memory management.

8. **Display Operation**:
   - Always print elements from `f` to `r`, inclusive.
   - Ensure you handle the case when the queue is empty.

## Linked List Queue Implementation

1. **Dynamic Size**:
   - A linked list queue can grow and shrink dynamically as elements are added or removed, unlike an array-based queue which has a fixed size.

2. **Memory Management**:
   - Memory is allocated as needed for each node, so there is no wasted space, and the queue can accommodate more elements than the initial capacity without overflow.

3. **Node Structure**:
   - Each element in the queue is stored in a node, which contains the data and a pointer to the next node. This structure allows for efficient insertion and deletion operations.

4. **Insertion**:
   - New elements can be added at the rear of the queue by updating the pointers of the last node. If the queue is empty, the new node becomes both the front and rear of the queue.

5. **Deletion**:
   - The front node is removed when an element is dequeued. The front pointer is updated to point to the next node. If the queue becomes empty after deletion, both front and rear pointers are set to `NULL`.

6. **No Wasted Space**:
   - Since memory is allocated for each node individually, there is no limit on the number of elements that can be stored in the queue, except for the total available system memory.

7. **Implementation Complexity**:
   - The implementation of a linked list queue is more complex than an array-based queue due to the need to manage pointers and dynamically allocate memory.

8. **Error Handling**:
   - The queue must handle cases where deletion is attempted on an empty queue, which can be managed through proper checks in the deletion function.

## Inserting Array Based:
```c
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
        return 0;
    }
}
```

## Deleting Array Based:
```c
int delete(int *q, int *f, int *r) {
    if (*f == -1) {  // Queue is empty
        printf("Queue is Empty");
        return -1;
    } else {
        int x = q[*f];  // Store the value to be deleted
        if (*f == *r) { // If the queue has only one element
            *f = *r = -1;  // Reset both front and rear pointers
        } else {
            (*f)++;  // Move front to the next element
        }
        return x;  // Return the deleted element
    }
}
```

## Displaying Array Based:
```c
void display(int *q, int *r, int *f) {
    if (*f == -1) {
        printf("The Queue is Empty!!\n");  // Added new line for better formatting
    } else {
        int i = *f;
        while (i <= *r) {  // Corrected condition to include elements from front to rear
            printf("%d\t", q[i]);
            i++;
        }
        printf("\n");  // Print new line after displaying all elements for better formatting
    }
}
```

## Inserting LL Based:
```c
// Insert an element at the rear of the queue
void insert(int x, struct Node** front, struct Node** rear) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (*rear == NULL) {  // Queue is empty
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}
```

## Deleting LL Based:
```c
// Delete an element from the front of the queue
int delete(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is Empty\n");
        return -1;
    }

    struct Node* temp = *front;
    int x = temp->data;
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);
    return x;
}
```

## Displaying LL Based:
```c
// Display all elements of the queue
void display(struct Node* front) {
    if (front == NULL) {
        printf("The Queue is Empty!!\n");
        return;
    }

    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
```

# MAIN Function:
```c
int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;

    insert(10, &front, &rear);
    insert(20, &front, &rear);
    insert(30, &front, &rear);

    display(front);  // --> remember!!

    printf("Deleted: %d\n", delete(&front, &rear));  // Deletes 10
    display(front);  // Displays: 20 30

    return 0;
}
```
