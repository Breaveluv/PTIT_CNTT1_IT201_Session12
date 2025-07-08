#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node *insert(Node *head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;

    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}
Node *insertENd(Node *head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }
    Node *last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
    return head;
}
void display(Node *head) {
    Node *current = head;
    if (current == NULL) {
        printf("Danh sach rong");
        return;
    }
    while (current != NULL) {
        printf("%d  ", current->data);
        if (current->next == NULL) {
            printf("<->");
        }
        current = current->next;
    }
    printf("->NULL\n");
}
int main() {
    int value;
    Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    printf("Enter value to be inserted:");
    scanf("%d", &value);
    display(head);
    head = insert(head, value);
    display(head);
    return 0;
}
