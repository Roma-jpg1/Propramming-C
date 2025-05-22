#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *pre;
} node_t;

node_t *new_Node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    new_node->pre = NULL;
    
    return new_node;
}

void append(node_t **head, int data) {
    node_t *new_node = new_Node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d-> ", current->data);
        current = current->next;
    }
    printf("\n");
}


int main(void) {
    node_t *head = NULL;
    node_t *niz = NULL;
    int value;
    while (1) {
        scanf("%d", &value);
        if (value == 0) {
            break;
        }
        append(&head, value);
    }
    node_t *current = head->next;
    while (current != NULL) {
        current->pre = head;  
        current = current->next;
    }

    struct node *cur=head->next;
    char com;

    head->pre=NULL;
    head->next=NULL;
    while(1){
        printf("текущий элем %d \n", cur->data);
        printf("введите одну из команд (W A S D)");
        scanf(" %c", &com);
        switch (com){
            case 'D':
            if (cur->next!=NULL){
                cur=cur->next;
            }
            else{
                printf("достигнут конец спсика \n");
                printf("\n");
                break;
            }
            break;
            case 'S':
            if (cur->pre != NULL){
                cur=cur->pre;
            }
            else{
                printf("достигнут конец \n");
                printf("\n");
                break;
            }
            break;
        }
    }


    return 0;
}
