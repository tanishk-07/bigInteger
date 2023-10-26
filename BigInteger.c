#include<stdio.h>
#include "BigInteger.h"

int main() {
    char num1_str[100];
    gets(num1_str);
    char num2_str[100];
    gets(num2_str);

    struct Node* num1 = NULL;
    struct Node* num2 = NULL;

    // Convert the input strings to linked list representations.
    for (int i = 0; i < strlen(num1_str); i++) {
        insertAtBeginning(&num1, num1_str[i] - '0');
    }

    for (int i = 0; i < strlen(num2_str); i++) {
        insertAtBeginning(&num2, num2_str[i] - '0');
    }

    struct Node* sum_result = addBigIntegers(num1, num2);
    struct Node* diff_result= subtractBigIntegers(num1,num2);
    struct Node* multi_result= multiplyBigIntegers(num1,num2);
    //struct Node* divide_result=divideBigIntegers(num1,num2);
    printf("Addition: \n");
    displayList(sum_result);
    printf("Subtraction: \n");
    displayList(diff_result);
    printf("Multiply: \n");
    displayList(multi_result);
    printf("Divide: \n");
   //displayList(divide_result);



    return 0;
}
