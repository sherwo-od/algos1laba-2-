#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

struct Node* CreateNode(char ch) {
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    if (NewNode == NULL) {
        printf("ERROR with memory");
        exit(EXIT_FAILURE);
    }
    NewNode->data = ch;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
}

void AppendToList(struct Node** head, char ch) {
    struct Node* NewNode = CreateNode(ch);
    if (*head == NULL) {
        *head = NewNode;
    }
    else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        NewNode->prev = current;
        current->next = NewNode;
    }
}

void Process(struct Node* origin, struct Node** res) {
    struct Node* current = origin;
    while (current) {
        char ch = current->data;
        if (isdigit(ch)) {
        }
        else if ((ch == 'a' || ch == 'A')) {
            AppendToList(res, ch);
            AppendToList(res, ch);
        }
        else {
            AppendToList(res, ch);
        }
        current = current->next;
    }
}

void Output(struct Node* head) {
    while (head) {
        printf("%c", head->data);
        head = head->next;
    }
    printf("\n");
}

void Clear(struct Node* head) {
    struct Node* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    struct Node* start = NULL;
    struct Node* end = NULL;
    char ch;

    while ((ch = getchar()) != '\n') {
        AppendToList(&start, ch);
    }

    Process(start, &end);
    Output(end);
    Clear(start);
    Clear(end);

    printf("Press Enter to escape:\n");
    getchar();
    return 0;
}
