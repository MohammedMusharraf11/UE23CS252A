#include <stdio.h>
#define STACK_SIZE 5

int top;
int s[STACK_SIZE];

void push(int item) {
    if (top == STACK_SIZE - 1) {
        printf("Stack is Full\n");
        return;
    }
    top++;
    s[top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return s[top--];
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("The stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", s[i]);
    }
}

int main() {
    top = -1; // Initialize top to -1 (empty stack)
    
    push(10);
    push(20);
    push(30);
    
    display();
    
    printf("Displaying after popping:\n");
    pop(); // Pop the top element
    display();

    return 0;
}
