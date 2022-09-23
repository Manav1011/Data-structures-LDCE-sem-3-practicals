// Write a program to implement queue using linked list.2
#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int data;
    struct Queue *next;
};

int isEmpty(struct Queue *head){
    if ((head)->next == NULL){
        return 1;
    }
    return 0;
}

int Enqueue(struct Queue **head,int data){
    struct Queue *node;
    node = malloc(sizeof(struct Queue));
    node->data = data;
    node->next = (*head)->next;
    (*head)->next = node;
    printf("%d Inserted\n",node->data);
}

int Dequeue(struct Queue **head){
    struct Queue *node;
    node = *head;
    if(isEmpty(*head)){
        printf("The queue is empty\n");
        return 0;
    }
    while(node->next->next != NULL){
        node = node->next;        
    }
    printf("%d Dequeued\n",node->next->data);
    node->next = NULL;    
}

int Display(struct Queue **head){
    if(isEmpty(*head)){
        printf("The queue is empty\n");
        return 0;
    }
    struct Queue *temp;
    temp = *head;
    printf("The quqeue is: ");
    while(temp->next != NULL){
        printf("%d->",temp->next->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Queue *head;
    head = malloc(sizeof(struct Queue));    
    head->next = NULL;
    Enqueue(&head,1);    
    Enqueue(&head,2);
    Enqueue(&head,3);
    Dequeue(&head);
    Dequeue(&head);
    Dequeue(&head);   
    Display(&head); 
}
