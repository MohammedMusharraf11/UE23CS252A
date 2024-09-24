# Important Notes for Linear Queue

**Queue follows FIFO**

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

## Inserting
`int insert(int x, int *q, int *r, int *f) {
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
}`

## Deleting
`int delete(int *q, int *f, int *r) {
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
}`

## Displaying
`void display(int *q, int *r, int *f) {
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
}`
