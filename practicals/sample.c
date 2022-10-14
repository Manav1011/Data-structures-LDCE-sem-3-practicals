// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int a[5];
    // Write C code here
    for(int i=0;i<5;i++){
        printf("Enter value:");
        scanf("%d",&a[i]);
        printf("\n%d\n",a[i]);
    }
    return 0;
}