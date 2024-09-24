#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
typedef struct Node {
    int data;               // Data stored in the node
    struct Node* next;      // Pointer to the next node
} Node;

// Function prototypes
Node* createNode(int data);
void push(Node** top, int data);
int pop(Node** top);
void display(Node* top);

int main() {
    Node* top = NULL; // Initialize the top of the stack

    // Example usage
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    
    printf("Current Stack: ");
    display(top);

    printf("Popped Item: %d\n", pop(&top));
    printf("Current Stack after Pop: ");
    display(top);

    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an item onto the stack
void push(Node** top, int data) {
    Node* newNode = createNode(data); // Create a new node
    newNode->next = *top;              // Link new node to the previous top
    *top = newNode;                    // Update the top to the new node
}

// Function to pop an item from the stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("The stack is empty\n");
        return -1; // Indicate that the stack is empty
    } else {
        Node* temp = *top;      // Temporary node to hold the top
        int poppedData = temp->data; // Store the data to return
        *top = (*top)->next;    // Update top to the next node
        free(temp);             // Free the old top node
        return poppedData;      // Return the popped data
    }
}

// Function to display the stack
void display(Node* top) {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        Node* current = top;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
