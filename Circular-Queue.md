## Inserting:
```c
int insert(int x, int *q, int *f, int *r) {
    // Check for queue full
    if ((*r + 1) % SIZE == *f) { // --> In linear  *r == SIZE - 1;
        printf("Queue is Full\n");
        return -1;
    }
    // Check if queue is empty
    if (*f == -1) {
        *f = 0;  // Set front to 0
    }
    // Increment rear using modulo
    *r = (*r + 1) % SIZE; // --> In linear  *r = *r + 1;
    q[*r] = x;  // Insert the element at the rear
    return 0;
}
```
## Deleting:
```c
int delete(int *q, int *f, int *r) {
    // Check if queue is empty
    if (*f == -1) {
        printf("Queue is Empty\n");
        return -1;
    }
    int x = q[*f];  // Store the value to be deleted
    // If only one element is in queue
    if (*f == *r) {
        *f = *r = -1;  // Reset both front and rear pointers
    } else {
        *f = (*f + 1) % SIZE;  // Move front using modulo
    }
    return x;  // Return the deleted element
}
```

## Displaying:

Display function reamins same only increment of i is changed from `i++;` to `i =  (i+1) % SIZE;`
