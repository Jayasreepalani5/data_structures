#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Element %d not found in the list. Cannot delete.\n", data);
    } else {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    return head;
}
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    printf("Linked List: ");
    display(head);
    head = deleteNode(head, 30);
    printf("Linked List after deletion: ");
    display(head);
    return 0;
}
