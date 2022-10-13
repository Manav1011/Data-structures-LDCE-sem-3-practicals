#include<stdio.h>
#include<stdlib.h>

void MergeTwo(int *elements,int *left,int leftlength,int *right,int rightlength){
    int i=0,j=0,k=0;
    while(i<leftlength && j<rightlength){
        if (left[i] < right[j]){
            elements[k] = left[i];
            i++;
        }
        else{
            elements[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<leftlength){
        elements[k] = left[i];
        i++;
        k++;
    }
    while(j<leftlength){
        elements[k] = right[j];
        j++;
        k++;
    }
}
void MergeSort(int *elements,int length){
    if (length <=1){
        return;
    }
    int *left;
    int *right;
    left = malloc(sizeof(int));
    right = malloc(sizeof(int));
    int mid = length / 2;
    // Left part
    int i=0;
    for(i=0;i<mid;i++){
        left[i] = elements[i];
    }
    // right part
    int j=0;
    for(j = mid; j<length; j++){
        right[j-mid] = elements[j];
    }   
    MergeSort(left,i);
    MergeSort(right,j-mid);
    MergeTwo(elements,left,i,right,j-mid);

}
int main(){
    int elements[] = {1,4,2,5,3,6,7};
    int length = sizeof(elements) / 4;
    MergeSort(elements,length);
    for(int i=0;i<length;i++){
        printf("%d  ",elements[i]);
    }
}