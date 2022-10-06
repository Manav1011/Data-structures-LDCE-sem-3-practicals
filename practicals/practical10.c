// Write a program to implement following operations on the circular linked  list.
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;    
};

int isEmpty(struct Node *head){
    if(head == NULL){
        return 1;
    }
    return 0;
}

// (a) Insert a node at the end of the linked list.
int InsertAtEnd(struct Node **head,int NewData){
    struct Node *NewNode = malloc(sizeof(struct Node));
    NewNode->data = NewData;
    if((*head) == NULL){        
        (*head)=NewNode;
        NewNode->next = NewNode;
        return NewNode->data;
    }
    struct Node *temp;
    temp=*head;
    while(temp->next != (*head)){
        temp=temp->next;
    }
    temp->next = NewNode;
    NewNode->next = (*head);
    return NewNode->data;
}

// (b) Insert a node before specified position.
int InsertBefore(struct Node **head,int DataAfter,int NewData){
    if(isEmpty(*head)){
        printf("The list is empty\n");
        return 0;
    }
    struct Node *NewNode = malloc(sizeof(struct Node));
    struct Node *temp;
    NewNode->data = NewData;
    temp=*head;
    if(temp->data == DataAfter){ 
        temp->data ;
        printf("Node inserted: %d\n",NewNode->data);
        return 0;
    }
    while(temp->next->data != DataAfter){
        printf("yo\n");
        temp=temp->next;
    }
    
    NewNode->next = temp->next;
    temp->next = NewNode;
    printf("Node inserted: %d\n",NewNode->data);
}

int Display(struct Node *head){
    if(isEmpty(head)){
        printf("The list is empty\n");
        return 0;
    }
    struct Node *temp;
    temp = head;
    printf("%d  ",temp->data);
    while(temp->next != head){
        printf("%d  ",temp->next->data);
        temp = temp->next;
    }    
    printf("\n");
}

int main(){
    struct Node *head = malloc(sizeof(struct Node));
    head = NULL;
    printf("The inserted node is %d:\n",InsertAtEnd(&head,1));
    printf("The inserted node is %d:\n",InsertAtEnd(&head,2));
    printf("The inserted node is %d:\n",InsertAtEnd(&head,3));
    printf("The inserted node is %d:\n",InsertAtEnd(&head,4));
    printf("The inserted node is %d:\n",InsertAtEnd(&head,5));
    printf("The inserted node is %d:\n",InsertAtEnd(&head,7));    
    InsertBefore(&head,1,6);
    Display(head);
}
