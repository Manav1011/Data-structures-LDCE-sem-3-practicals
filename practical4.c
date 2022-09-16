// Write a program to implement QUEUE using arrays that performs following operations (a) INSERT (b) DELETE (c) DISPLAY
#include <stdio.h>
#include <stdlib.h>

struct queue{
    int n;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct queue *q){
    if (q->front == q->rear){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if (q->rear == q->n-1){
        return 1;
    }
    return 0;
}


int Enqueue(struct queue *q, int val){
    if (isFull(q)){
        printf("Queue is full\n");
    }else{
        q->rear ++;
        q->arr[q->rear] = val;
        printf("Enqued element: %d\n", val);
    }
}

int Dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("The queue is empty\n");
    }
    else{
        printf("Dequed element is :%d\n", q->arr[q->rear]);
        q->rear--;
    }
}

int Display(struct queue *q){
    for(int i = 0;i< q->n ; i++){
        printf("%d\n", q->arr[i]);
    }
    return 0;
}

int main(){
    struct queue q;
    printf("Enter the size of queue\n");
    scanf("%d",&q.n);    
    int val;
    q.front = q.rear = -1;
    q.arr = (int *) malloc(q.n * sizeof(int));    
    int choice;
    printf("1: Insert\n2: Remove\n3:Display\n");
    do{
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value you want to insert\n");
                scanf("%d",&val);
                Enqueue(&q,val);
                break;
            case 2:
                Dequeue(&q);
                break;
            case 3:
                Display(&q);
                break;
        }
    }    
    while(choice != 4);
    return 0;
   
}