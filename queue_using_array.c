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

    
}




int main() {
    // Write C code here
    printf("Try programiz.pro");

    return 0;
}
