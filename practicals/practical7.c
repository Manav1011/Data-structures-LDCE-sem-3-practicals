// Write a program to implement stack using linked list
#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int data;
    struct Stack* next;
};

int isEmpty(struct Stack* stack){
    if(stack->next == NULL){
        printf("The stack is empty\n");
        return 1;
    }
    return 0;
}

int PUSH(struct Stack **head,int data){
    struct Stack *node;
    node = malloc(sizeof(struct Stack));
    if (head == NULL){
        printf("Node cannnot be null");
        return 0;
    }    
    node->data = data;
    node->next = (*head)->next;
    (*head)->next = node;    
    printf("%d Inserted\n",node->data);
}

int POP(struct Stack **head){
    if((isEmpty(*head))){        
        return 0;
    }
    printf("The deleted element is %d\n",(*head)->next->data);
    (*head)->next = (*head)->next->next;
}

int PEEK(struct Stack **head){
    if((isEmpty(*head))){        
        return 0;
    }
    return (*head)->next->data;
}

int Display(struct Stack **head){
    struct Stack *node;
    node = *head;
    if((isEmpty(*head))){        
        return 0;
    }
    printf("Stack is: ");
    while( node ->next!=NULL){
        printf("%d->",node->next->data);
        node = node ->next;
    }
    printf("NULL");
}

int main(){  
    struct Stack *head;
    head = malloc(sizeof(struct Stack));    
    head->next = NULL;
    PUSH(&head,1);
    PUSH(&head,2);
    PUSH(&head,3);
    POP(&head);
    POP(&head);
    printf("TOP element is %d\n",PEEK(&head));
    Display(&head);
}