// Write a program to implement following operations on the circular linked  list
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *previous;
};

int isEmpty(struct Node *head){
if(head == NULL){        
        return 1;
    }
return 0;
}


// (a) Insert a node at the front of the linked list
int InsertAtFront(struct Node **head,int Data){
    struct Node *NewNode = malloc(sizeof(struct Node));
    NewNode->data = Data;
    if((*head) == NULL){        
        NewNode->next = NULL;
        NewNode->previous = NULL;
        (*head)=NewNode;
        return NewNode->data;
    }
    struct Node *temp;
    temp = *head;
    NewNode->next = temp;
    NewNode->next->previous = NewNode;
    (*head) = NewNode;
    return NewNode->data;

}


// b) Insert a node at the end of the linked list.
int InsertAtEnd(struct Node **head ,int data){    
    struct Node *NewNode;
    struct Node *temp;
    temp = *head;
    NewNode=malloc(sizeof(struct Node));
    NewNode->data = data;
    if((*head)==NULL){
        NewNode->previous = NULL;
        NewNode->next = NULL;
        (*head)=NewNode;
        return NewNode->data;
    }
    while((temp)->next){
        temp = temp->next;
    }
    temp->next = NewNode;
    NewNode->previous = temp;
    return NewNode->data;
}

// (c) Delete a last node of the linked list.
int DeleteLast(struct Node **head){
    if(isEmpty((*head))){
        printf("The Linked List is empty\n");
        return 0;
    }    
    struct Node *temp;
    temp = *head;
    if(temp->next == NULL){
        (*head)=NULL;
        return temp->data;
    }
    while(temp->next){
        temp=temp->next;
    }
    temp->previous->next = NULL;
    return temp->data;
}

// (d) Delete a node before specified position.
int DeleteBefore(struct Node **head,int DataAfter){            
    struct Node *temp;
    temp = *head;
    if(isEmpty((*head))){
        printf("The Linked List is empty\n");
        exit(0);
    }
    while(temp->data != DataAfter){
        if(temp->next != NULL){
            temp= temp->next;   
        }
        else{
            printf("Data not found\n");
            exit(0);
        }
    }
    if(temp->previous == NULL){
        printf("There is no node before!!\n");
        exit(0);
    }
    if(temp->previous->previous == NULL){
        int DeletedValue = temp->previous->data;
        temp->previous = NULL;
        (*head) = temp;
        return DeletedValue;
    }
    int DeletedValue = temp->previous->data;
    temp->previous = temp->previous->previous;
    temp->previous->next = temp;
    return DeletedValue;
}


// (b) Insert a node before specified position
// int InsertBefore(struct Node **head,int DataAfter,int data){    
//     if(isEmpty((*head))){
//         printf("The Linked List is empty\n");
//         exit(0);
//     }
//     struct Node *temp;
//     struct Node *NewNode = malloc(sizeof(struct Node));
//     NewNode->data = data;    
//     temp = *head;    
//     while(temp->data != DataAfter){          
//         if(temp->next == NULL){
//             printf("Node not found\n");
//             return 0;
//         }
//         temp=temp->next;
//     }    
//     NewNode->next = temp;
//     NewNode->previous = temp->previous;
//     temp->previous = NewNode;

//     if(NewNode->previous == NULL){
//         (*head)=NewNode;
//     }
//     else{
//         NewNode->previous->next = NewNode;
//     }
//     return 0;  
// }

// // (c) Delete a first node of the linked list.
// int DeleteFirst(struct Node **head){
//     if(isEmpty((*head))){
//         printf("The Linked List is empty\n");
//         exit(0);
//     }
//     struct Node* temp;
//     temp=*head;
//     (*head)=temp->next;
//     temp->next->previous = NULL;
//     return temp->data;
// }

// // (d) Delete a node after specified position.
// int DeleteAfter(struct Node **head,int DataBefore){
//     struct Node *temp;
//     temp = *head;    
//     if(isEmpty((*head))){
//         printf("The Linked List is empty\n");
//         exit(0);
//     }    
//     while(temp->data != DataBefore){
//         temp = temp->next;
//     }
//     if(temp->next == NULL){
//         printf("End of the Linked List");
//         exit(0);
//     }    
//     temp->next = temp->next->next;
//     temp->next->previous = temp;
// }

int Display(struct Node *head){
    struct Node *temp = head;
    if(isEmpty(head)){
        printf("The Linked List is empty\n");
        return 0;
    }
    printf("%d ",temp->data);
    while(temp->next){        
        printf("%d  ",temp->next->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node *head = malloc(sizeof(struct Node));
    head = NULL;    
    printf("The node you inserted is %d\n",InsertAtFront(&head,1));
    printf("The node you inserted is %d\n",InsertAtFront(&head,2));
    printf("The node you inserted is %d\n",InsertAtFront(&head,3));
    printf("The node you inserted is %d\n",InsertAtEnd(&head,4));
    printf("The node you inserted is %d\n",InsertAtEnd(&head,5));
    printf("The node you inserted is %d\n",InsertAtEnd(&head,6));
    Display(head);
    printf("The Node you have deleted from the end is %d\n:",DeleteLast(&head));
    printf("The Node you have deleted from the end is %d\n:",DeleteLast(&head));    
    // InsertBefore(&head,2,7);
    // printf("The node that you have deleted is :%d\n",DeleteFirst(&head));    
    printf("The Node you have deleted is %d:\n",DeleteBefore(&head,4));
    Display(head);
}
