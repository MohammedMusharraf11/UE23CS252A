#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    
    struct Node * prev; //Pointer to point previous element
    int data;   // To store data
    struct Node * next; //Pointer to point next element

}NODE;

// Function to Create Node
NODE *createnode(int new_data){
    NODE * newnode = (NODE *)malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("Memory Allocation Failed!!");
        exit(1);
    }
    newnode->prev = NULL;
    newnode->data = new_data;
    newnode->next = NULL;
    return newnode;
}


// Function to Insert at the Front

NODE * insertfront(NODE * head,int data){
    NODE * temp = createnode(data);
    
    if(head!=NULL){     //Check if the list is Empty!!
        head->prev = temp;
        temp->next = head;
    }
    head = temp;
    
    return head;
}





// Function to Insert element at the rear-end

NODE * insertend(NODE * head, int data){
    NODE * temp = createnode(data);
    
    if(head==NULL){
        head = temp;
        
    }
    
    else{
        NODE * current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;
    }
    return head;
}
    
    
void display(NODE * head){
    NODE * current = head;
    while(current!=NULL){
        printf("%d\n",current->data);
        current = current->next;
    }
}

NODE * insertpos(NODE * head , int data , int pos){
    NODE * temp = createnode(data);
    NODE * current = head;
    
    if(head==NULL){
        printf("List is Empty!!");
    }
    for(int i=1;i<pos-1;i++){
        current = current->next;
    }
    
    temp->next = current->next;
    temp->prev = current;
    current->next->prev = temp;
    current->next = temp;
    
    return head;
}


int main() {
    
    NODE * head = createnode(10);
    head =insertfront(head,20);
    head =insertfront(head,30);
    head =insertfront(head,40);
    head =insertfront(head,50);
    head = insertpos(head,25,4);
    
    display(head);
    
    

    return 0;
}