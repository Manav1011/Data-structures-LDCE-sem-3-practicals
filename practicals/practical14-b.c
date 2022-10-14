#include<stdio.h>


void BinarySearch(int *elements,int start,int end,int data){
    if(start > end){
        printf("Not found");
        return;
    }
    int mid = (start + end) / 2;        
    if(data == elements[mid]){
        printf("Element found!!");
        return;
    }

    if(data < elements[mid]){
        BinarySearch(elements,0,mid-1,data);
    }
    else{
        BinarySearch(elements,mid+1,end,data);
    }
}

int main(){
    int elements[] = {1,2,3,4,5,6,7,8};
    int length = sizeof(elements) /4;
    BinarySearch(elements,0,length,9);
}