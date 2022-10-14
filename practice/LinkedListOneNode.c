#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
};

void PrintLinkedList(struct LinkedList *head){
    printf("head-> ");
    while(head != NULL){
        printf("%d-> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int InsertAtMid(struct LinkedList **head,int data){
    int length = 0;
    struct LinkedList *NewNode;
    NewNode = malloc(sizeof(struct LinkedList));
    NewNode->data = data;
    struct LinkedList *temp;
    temp = *head;
    while(temp){
        temp = temp->next;
        length ++;
    }
    int mid = 0;
    temp = *head;
    while(mid != length / 2 && temp){
        temp = temp->next;
        mid ++;
    }
    NewNode -> next = temp->next;
    temp->next = NewNode;
    return temp->data;
}
int InsertAfterData(struct LinkedList **head,int dataBefore,int NewData){
    struct LinkedList *NewNode;
    NewNode = malloc(sizeof(struct LinkedList));
    NewNode->data = NewData;
    struct LinkedList *temp;
    temp = *head;
    while(temp->data != dataBefore){
        temp = temp->next;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
}
int InsertAtEnd(struct LinkedList **head,int data){
    struct LinkedList *NewNode;
    struct LinkedList *temp;
    temp = *head;
    NewNode = malloc(sizeof(struct LinkedList));
    NewNode->data = data;
    NewNode->next = NULL;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = NewNode;
    return NewNode->data;
}
int main(){
    struct LinkedList *head;
    struct LinkedList *one;
    one = malloc(sizeof(struct LinkedList));
    one->data = 10;
    one->next = NULL;
    head = one;
    int UserChoice;
    printf("How many entries you want to make?:\n");
    scanf("%d",&UserChoice);
    for(int i = 0;i<UserChoice;i++){
        int Value;
        printf("Enter the value: \n");
        scanf("%d",&Value);
        printf("The node you inserted at end is %d\n",InsertAtEnd(&head,Value));
    }
    InsertAfterData(&head,20,100);
    InsertAtMid(&head,200);
    PrintLinkedList(head);
}