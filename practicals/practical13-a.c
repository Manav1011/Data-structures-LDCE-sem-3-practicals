#include <stdio.h>
// a) Write a program to implement Queue Sort

int swap(int *elements,int a,int b){
    int temp;
    temp = elements[a];
    elements[a] = elements[b];
    elements[b] = temp;
}

int partition(int *elements,int length,int start,int end){
    int pivot = start;

    while(start < end){
        while (start < length && elements[start] <= elements[pivot]){
            start ++;
        }
        while (elements[end] > elements[pivot]){
            end --;
        }
        if (start < end){
            swap(elements,start,end);
        }
    }
    swap(elements,pivot,end);
    return end;
}

int QuickSort(int *elements,int length,int start,int end){
    if (start<end){
        int partition_point = partition(elements,length,start,end);        
        QuickSort(elements,length,start,partition_point -1); //For left
        QuickSort(elements,length,partition_point + 1,end); //for right
    }
}

int main(){
    int elements[]={1,3,4,2,4,5,6,7};
    int length = sizeof(elements) / 4;
    int start = 0;
    int end = length -1;
    QuickSort(elements,length,start,end);
    for(int i=0; i<length; i++){
        printf("%d  ",elements[i]);
    }
}