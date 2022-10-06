#include<stdio.h>

int main(){
    int i=0;
    int out;
    while(i<5){
         out = (i+1)%5;
        printf("%d\n",out);
        i++;
    }
}