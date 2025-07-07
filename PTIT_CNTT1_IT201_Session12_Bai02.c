#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

}Node;
Node *insert(Node *head, int data) {
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

void printListReverse(Node *head) {

    Node* current = head;
    while (current != NULL) {
        printf("data :%d \n  ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    Node *head = NULL;
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    head=insert(head,5);

    printListReverse(head);
    return 0;
}