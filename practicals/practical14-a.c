// a) Write a program to implement Bubble Sort
#include <stdio.h>

void swap(int *elements,int a,int b){
    int temp = elements[a];
    elements[a] = elements[b];
    elements[b] = temp;
}
int BubbleSort(int *elements,int end){
    if(end > 0){
        for(int i =0 ; i<end ;i++){
            if(elements[i] > elements[i+1]){
                swap(elements,i,i+1);
            }
        }
        end--;
        BubbleSort(elements,end);
    }
}
int main(){
    int elements[] = {8,2,1,4,5,6,};
    int length = sizeof(elements) / 4;
    BubbleSort(elements,length);
    for(int i=0;i<length;i++){
        printf("%d  ",elements[i]);
    }
}