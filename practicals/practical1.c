// Introduction to pointers. Call by Value and Call by reference.
#include <stdio.h>

void CallByValue(int number){
    number = number +100;
}

void CallByReference(int* number){
    (*number) += +100;
}
int main(){
    int number = 10;
    printf("Call By Value\n");
    printf("The number before changing is %d\n",number);    
    CallByValue(number);
    printf("The number after changing is %d\n",number);

    printf("Call By Reference\n");
    printf("The number before changing is %d\n",number);    
    CallByReference(&number);
    printf("The number after changing is %d\n",number);
}