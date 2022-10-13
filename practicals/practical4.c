// Write a program to implement Circular Queue using arrays that performs following operations. (a) INSERT (b) DELETE (c) DISPLAY

#include <stdio.h>
#include <stdlib.h>

struct CQueue{
        int front;
        int rear;
        int size;
        int *arr;
    };

int isEmpty(struct CQueue *q){
    if (q->front == -1){
        return 1;
    }
    return 0;    
}
int isFull(struct CQueue *q){
    if((q->front == (q->rear +1) )|| (q->front == 0 && q->rear == q->size - 1) ){
        return 1;
    }        
    return 0;    
}

int CDequeue(struct CQueue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else if(q->front == q->rear){
        printf("Dequed element is %d\n",q->arr[q->front]);
        q->front = q->rear = -1;        
    }
    else{
        printf("Dequed element is %d\n",q->arr[q->front]);
        q->front = (q->front + 1)%q->size;
    }
}

int CEnqueue(struct CQueue *q, int val){
    if (isFull(q)){
        printf("Queue is full Cannot insert more\n");
    }
    else{
        if(q->front == -1 && q->rear == -1){
        q->front = 0;
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear]=val;        
        printf("Enqueued element is %d\n",val);
    }
    else{
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear]=val;        
        printf("Enqueued element is %d\n",val);
    }
    }
}

void display(struct CQueue *q){
    for(int i = 0; i <= (q->size -1); i++){
        printf("%d\n",q->arr[i]);
    }
}
int main(){
    struct CQueue q;
    q.front = q.rear = -1;
    q.size = 5;
    q.arr = (int *) malloc(sizeof(int) * q.size);    
    CEnqueue(&q,10);
    CEnqueue(&q,20);
    CEnqueue(&q,30);
    CEnqueue(&q,40);
    CEnqueue(&q,50);    
    CDequeue(&q);   
    CEnqueue(&q,60); 
    display(&q);
    return 0;
}