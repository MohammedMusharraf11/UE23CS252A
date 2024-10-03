#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *rt, *lt;
};

typedef struct Node NODE;
NODE * getSuccessor(NODE * root){
    root = root->rt;
    while(root!=NULL && root->lt!=NULL){
        root = root->lt;
    }
    return root;
}

NODE * delNode(NODE * root, int x) {
    if (root == NULL) {
        return root;
    }
    
    // If the value to be deleted is smaller than root's value
    if (root->data > x) {
        root->lt = delNode(root->lt, x);
    } 
    // If the value to be deleted is greater than root's value
    else if (root->data < x) {
        root->rt = delNode(root->rt, x);
    } 
    // If the value to be deleted is the root's value
    else {
        // Case 1: Node has no child or one child
        if (root->lt == NULL) {
            NODE *temp = root->rt;
            free(root);
            return temp;
        } else if (root->rt == NULL) {
            NODE *temp = root->lt;
            free(root);
            return temp;
        }
        
        // Case 2: Node has two children
        // Get the inorder successor (smallest in the right subtree)
        NODE *successor = getSuccessor(root);
        
        // Copy the successor's value to the root
        root->data = successor->data;
        
        // Delete the successor
        root->rt = delNode(root->rt, successor->data);
    }
    
    return root;
}

void inorder(NODE *root){
    if(root!=NULL){
        inorder(root->lt);
        printf("%d\n",root->data);
        inorder(root->rt);
    }
}


NODE * createNode(int data){
    NODE * newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->rt = NULL;
    newNode->lt = NULL;
    return newNode;
}


NODE * insert(NODE * root, int data){
    if(root==NULL){
        return createNode(data);
    }
    else if (root->data==data){
        return root;
    }
    else{
        if(root->data < data){
            root->rt = insert(root->rt,data);
        }else{
            root->lt = insert(root->lt,data);
        }
    }
    return root;
}
int main() {
    NODE *root = NULL;  // Initialize the root node to NULL
    
    // Insert nodes into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    // Print the inorder traversal before deletion
    printf("Inorder traversal of the given tree:\n");
    inorder(root);
    
    // Delete node with value 20 (leaf node)
    root = delNode(root, 20);
    printf("\nInorder traversal after deletion of 20:\n");
    inorder(root);
    
    // Delete node with value 30 (node with one child)
    root = delNode(root, 30);
    printf("\nInorder traversal after deletion of 30:\n");
    inorder(root);
    
    // Delete node with value 50 (node with two children)
    root = delNode(root, 50);
    printf("\nInorder traversal after deletion of 50:\n");
    inorder(root);
    
    return 0;
}


