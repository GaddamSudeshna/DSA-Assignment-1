#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int len;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* list, int index) {
    if (index < 0 || index >= list->len) return -1;
    Node* temp = list->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* list, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = list->head;
    list->head = node;
    if (list->len == 0) {
        list->tail = node;
    }
    list->len++;
}

void myLinkedListAddAtTail(MyLinkedList* list, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    if (list->len == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->len++;
}

void myLinkedListAddAtIndex(MyLinkedList* list, int index, int val) {
    if (index < 0 || index > list->len) return;
    if (index == 0) {
        myLinkedListAddAtHead(list, val);
    } else if (index == list->len) {
        myLinkedListAddAtTail(list, val);
    } else {
        Node* temp = list->head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* node = (Node*)malloc(sizeof(Node));
        node->val = val;
        node->next = temp->next;
        temp->next = node;
        list->len++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* list, int index) {
    if (index < 0 || index >= list->len) return;

    if (index == 0) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        if (list->len == 1) list->tail = NULL;
    } else {
        Node* temp = list->head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if (index == list->len - 1) list->tail = temp;
        free(toDelete);
    }
    list->len--;
}

void myLinkedListFree(MyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
