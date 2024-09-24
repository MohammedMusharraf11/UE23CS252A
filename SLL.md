## Insertion:
Insertion at front:
```c
NODE* insertfront(NODE* head, int data) {
    // Create a new node
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data; // Set the data value of the new node
    newNode->next = head; // Link the new node to the current head of the list

    // The new node becomes the head of the list
    return newNode;
}
```
Insertion at Tail:
```c
NODE * insertTail(NODE * head, int data){
    NODE * newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    if(head==NULL){
        return newNode;
    }
    else{
        NODE * temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
```

Insertion at Position:
```c
NODE * insertpos(NODE * head, int data, int pos){
    NODE * newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    if(head==NULL){
        return newNode;
    }
    if(pos ==1){
        newNode->next = head;
        return newNode;
    }
    else{
        int count = 0;
        NODE * temp = head;
        while(temp!=NULL){
            count++;
            if(count == pos-1){
                newNode->next = temp->next;
                temp->next = newNode;
                // return head;
                break;
            }
            temp = temp->next;
        }
            return head;
    }
}
```

## Deletion

Delete Head:
```c
NODE * deletehead(NODE * head) {
    if (head == NULL) {
        return NULL;  // If the list is empty, nothing to delete
    }

    NODE * temp = head;   // Store the current head
    head = head->next;    // Move the head to the next node
    free(temp);           // Free the memory of the old head node
    return head;          // Return the new head
}
```

Delete Tail:
```c
NODE * delTail(NODE *head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    NODE * temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    //  10 -> 20 -> 30 -> 40 -> NULL
    // Now temp will be at 30 and 40 is TAIL
    free(temp->next);
    temp->next = NULL;
    return head;
}
```
Delete at Postion:
```c
NODE * delpos(NODE * head, int pos) {
    if (head == NULL) {
        return NULL; // If the list is empty, nothing to delete
    }
    
    // Handle deletion of the head node
    if (pos == 1) {
        NODE * temp = head; // Save the current head to free later
        head = head->next;  // Move head to the next node
        free(temp);         // Free the original head node
        return head;        // Return the new head
    }

    NODE * temp = head;
    NODE * prev = NULL;
    int count = 1; // Start count at 1 (1-based index)

    while (temp != NULL && count < pos) {
        prev = temp;     // Move prev to the current node
        temp = temp->next; // Move temp to the next node
        count++;
    }

    // If we found the position, delete the node
    if (temp != NULL) {
        prev->next = temp->next; // Link the previous node to the next of the node to be deleted
        free(temp);               // Free the memory of the node to be deleted
    }

    return head; // Return the head of the modified list
}
```


`````
