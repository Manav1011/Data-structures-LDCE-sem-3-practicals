// Write a menu driven program to implement following operations onthe  singly linked list.
// (a) Insert a node at the front of the linked list.
// (b) Insert a node at the end of the linked list.
// (c) Insert a node such that linked list is in ascending order. (accordingto  info. Field)
// (d) Delete a first node of the linked list.(e) Delete a node before specified position.
// (f) Delete a node after specified position.

#include <stdio.h>
#include<stdlib.h>


struct LinkedList{
    int data;
    struct LinkedList *next;
};



void Display(struct LinkedList **node){    
    printf("\n");
    printf("LinkedList:  ");
    while((*node) != NULL){
        printf("%d    ",(*node)->data);
        *node= (*node)->next;
    }
}

void InsertAtFront(struct LinkedList **head,int data){
    struct LinkedList *node;
    node = malloc(sizeof(struct LinkedList));
    node->data = data;
    node->next = *head;
    *head = node;    
}

void InsertAtEnd(struct LinkedList **head,int data){
    struct LinkedList *newnode;
    newnode = malloc(sizeof(struct LinkedList));
    newnode->data=data;
    newnode->next = NULL;

    struct LinkedList *temp;
    temp= *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }    
    temp->next = newnode;    
}

void InsertAfter(struct LinkedList *node,int data){
    if (node == NULL){
        printf("Node cannot be null");
        return;
    }
    struct LinkedList *newnode;
    newnode = malloc(sizeof(struct LinkedList));
    newnode->data = data;
    newnode->next = node->next;
    node->next = newnode;
}

int DeleteAtStart(struct LinkedList **node){
    if((*node)->next == NULL || node == NULL){        
        (*node) = NULL;    
        return 0;
    }
    printf("The element you deleted is %d\n",(*node)->data);
    *node =  (*node)->next;
}

int DeleteLastNode(struct LinkedList **node){
    struct LinkedList *temp;
    temp= *node;
    while(temp->next->next!= NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}

int DeleteAfter(struct LinkedList **node){
    (*node)->next = (*node)->next->next;
}



int main(){
    struct LinkedList *head;
    struct LinkedList *one;
    struct LinkedList *two;
    struct LinkedList *three;

    // Allocate memory
    one = malloc(sizeof(struct LinkedList));
    two = malloc(sizeof(struct LinkedList));
    three = malloc(sizeof(struct LinkedList));

    // Assinging data part
    one->data = 1;
    two->data = 2;
    three->data = 3;

    // Assigning pointer part
    one->next = two;
    two->next = three;
    three->next = NULL;
    head = one;
    InsertAtFront(&head,0);
    InsertAtEnd(&head,4);
    InsertAfter(one,10);    
    printf("\n");
    DeleteAtStart(&head);       
    DeleteAtStart(&head);        
    DeleteLastNode(&head);
    DeleteAfter(&head);
    Display(&head);
}
