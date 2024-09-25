## Insertion:
Insertion Head
```c
NODE * inserthead(NODE *head, int data){
    NODE * newNode = createNode(data);
    newNode->next = head;
    if(head!=NULL){
        head->prev = newNode;
    }
    return newNode;
    
}
```

Insertion at Tail:
```c
NODE * insertTail(NODE *head, int data) {
    NODE *newNode = createNode(data);
    
    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        return newNode;
    }
    
    // Traverse to the last node
    NODE *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Update the last node's next pointer and the new node's prev pointer
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}
```

Insertion at Position:
```c
NODE * insertPos(NODE * head, int data, int pos) {
    NODE * newNode = createNode(data);
    
    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        return newNode;
    }
    
    if (pos == 1) {
        // Inserting at the head position
        newNode->next = head;
        head->prev = newNode;
        return newNode; // New node becomes the new head
    }

    NODE * temp = head;
    int count = 1; // Start counting from 1 since position is 1-based
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // Now, temp is the node just before the insertion point (pos - 1)
    if (temp == NULL) {
        // If position is out of bounds, return the original list without insertion
        printf("Position is out of bounds\n");
        return head;
    }

    // Insert the new node between temp and temp->next
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        // If we are not inserting at the last position
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
    
    return head;
}
```
