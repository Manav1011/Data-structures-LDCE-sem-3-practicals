#include<stdio.h>
#include<stdlib.h>

void MergeTwo(int *left,int llength,int *right,int rlength,int *elements){
    int i=0,j=0,k=0;
    while(i<llength && j< rlength){
        if(left[i] < right[j]){
            elements[k] = left[i];
            i++;
        }
        else{
            elements[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<llength){
        elements[k]=left[i];
        i++;
        k++;
    }
    while(j<rlength){
        elements[k] = right[j];
        j++;
        k++;
    }
}
void MergeSort(int *elements,int length){
    if(length <= 1){
        return;
    }
    int mid  = length /2;
    int left[mid];    
    int i;
    for(i = 0; i<mid; i++){
        left[i] = elements[i];
    }
    int right[length-mid];
    int j;
    for(j=0; j < length-mid; j++){
        right[j] = elements[j + mid];
    }
    MergeSort(left,i);
    MergeSort(right,j);
    MergeTwo(left,i,right,j,elements);
}
int main(){
    int elements[] = {-1,-5,-3,5,2,4,5};
    int length = sizeof(elements) / 4;    
    MergeSort(elements,length);
    for(int i=0;i<length;i++){
        printf("%d  ",elements[i]);
    }
}