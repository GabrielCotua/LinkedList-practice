#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int x;
    struct Node* next;
} Node;


void insert_end(Node** root, int value);
void deallocate(Node** root);

int main(void){
    Node* root = NULL;
    /** 
    Node* root = malloc(sizeof(Node));
    if (root == NULL) {
        printf("Memory allocation failed\n");
        exit(2);
    }
    root->x = 15;
    root->next = NULL;
    */

    insert_end(&root,20);
    insert_end(&root,200);

    for (Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d\n", curr->x);
    }


    return 0;
}

void insert_end(Node** root, int value) {
    Node* new_node = malloc(sizeof(Node));
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
}

void deallocate(Node** root) {
    
}