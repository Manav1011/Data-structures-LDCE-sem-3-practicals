// Introduction to Dynamic Memory Allocation. DMA functions malloc(), calloc(), free() etc.
#include <stdio.h>
#include <stdlib.h>
int main(){
    int *p;
    p = (int*)malloc(5*sizeof(int));
    if (p == NULL){
        printf("Memory allocation successful\n");
    }
    for(int i=0; i<5; i++){
        p[i] = i;
    }
    for (int i=0; i<5; i++){
        printf("%d\n", p[i]);
    }
    return 0;
}