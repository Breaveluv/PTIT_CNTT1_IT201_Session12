#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *insertAtEnd(Node *head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
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
void display(Node *head) {
    Node *current = head;
    while (current == NULL) {
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
    Node *head = NULL;
    int n;
    int value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Gia tri cho phan tu %d ; \n",i+1);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }
    printf("Danh sach tao duoc la ");
    display(head);
    return 0;
}
