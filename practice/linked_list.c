#include <stdio.h>
#include<stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
};
void Display(struct LinkedList *node){
    while(node != NULL){
        printf("%d\n",node->data);
        node= node->next;
    }
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

}