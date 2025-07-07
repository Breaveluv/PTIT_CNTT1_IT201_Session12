#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *insert(Node *head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}
Node *deleteByValue( Node *head,int value) {
    Node *current = head;
    while (current != NULL) {
        Node *nextNode = current->next;
        if (current->data == value) {
            if (current==head) {
                head = current->next;
            }
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
        }
        current = nextNode;
    }
    return head;

}
void display(Node *head) {
    Node *current = head;
    if (current == NULL) {
        printf("NULL\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->next != NULL) {
            printf("<->");
        }
        current = current->next;
    }
    printf("->NULL\n");
}
int main() {
    Node *head = NULL;
    int valueDelete;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 10);
    head = insert(head, 20);
    display(head);
    printf("Enter value to be deleted:");
    scanf("%d", &valueDelete);
    head = deleteByValue(head, valueDelete);
    display(head);


    return 0;
}