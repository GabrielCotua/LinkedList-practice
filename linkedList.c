#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int x;
    struct Node* next;
} Node;

// Node** means that it is the address of the pointer aka, the pointer of the pointer
void insert_end(Node** root, int value); // Function to insert a new node at the end of the list 
void deallocate(Node** root); // Wll be done

int main(void){
    Node* root = NULL; // initialize the root pointer of the linked list
    // it is NULL becuase will indicate that is the last one to iterate trough 

    insert_end(&root,20); // insert 20 at the end of the list
    insert_end(&root,200); // insert 200 at the end of the list

    for (Node* curr = root; curr != NULL; curr = curr->next) { // we are iterating through the list, interesting that instead of int i, we have to change the
                                                               // adress of curr to the next one {curr = curr->next}
        printf("%d\n", curr->x); // print the value of the current node
    }


    return 0;
}

void insert_end(Node** root, int value) {
    Node* new_node = malloc(sizeof(Node)); //dinamically allocate memory for a new node
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node-> next = NULL;
    new_node->x = value;

    if (*root == NULL) {
        *root = new_node;
        return;
    }

    Node* curr = *root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    free(new_node); // free the memory allocated for the new node
}

void deallocate(Node** root) {
    
}