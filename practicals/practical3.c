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
    if(q->front == -1 && q->rear == -1){        
        q->rear ++;
        q->front++;
        q->arr[q->rear] = val;
        printf("Enqued element: %d\n", val);
        return 0;
    }
    if (isFull(q)){
        printf("Queue is full\n");
        return 1;
    }else{
        q->rear ++;
        q->arr[q->rear] = val;
        printf("Enqued element: %d\n", val);
        return 0;
    }
}

int Dequeue(struct queue *q){    
    if(isEmpty(q)){
        printf("The queue is empty\n");
        return 1;
    }
    else{
        printf("Dequed element is :%d\n", q->arr[q->front]);
        q->front++;
        return 0;
    }
}

int Display(struct queue *q){
    // printf("Front is : %d\n",q->front);
    printf("Queue is ");
    for(int i = q->front;i< q->n-1 ; i++){
        printf("%d  ", q->arr[i]);
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
    Enqueue(&q,1);
    Enqueue(&q,2);
    Enqueue(&q,3);
    Dequeue(&q);
    Display(&q);
}