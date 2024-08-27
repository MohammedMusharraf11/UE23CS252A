#include <stdio.h>
#define STACK_SIZE 6
struct Stack {
    int top;
    int s[STACK_SIZE];
};

void push(struct  Stack * stack, int data){
    if(stack->top==STACK_SIZE-1){
        printf("The Stack is full");
        return;
    }
    stack->top++;
    stack->s[stack->top] = data;
    return;
}

int pop(struct Stack *stack) {
    if(stack->top==-1){
        printf("Stack is Empty");
        return -1;
    }
    else{
        return stack->s[stack->top--];
    }
}

void display(struct Stack * stack){
    if(stack->top==-1){
        printf("Stack is Empty");
    }
    for(int i = stack->top;i>=0;i--){
        printf("%d\n",stack->s[i]);
    }
}

int main() {
    // Write C code here            
                            //top gives us the INDEX
                            //top+1 gives us the POSITION
    struct Stack stack;
    stack.top = -1;
    push(&stack,10);
    push(&stack,20);
    push(&stack,30);
    display(&stack);
    pop(&stack);
    printf("Displaying after poping\n");
    display(&stack);


    return 0;
}
