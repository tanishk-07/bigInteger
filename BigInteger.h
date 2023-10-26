// Function to subtract two linked list representations of big integers.
// It assumes that num1 >= num2 and returns NULL if the result is negative.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a linked list structure to represent digits of a big integer.
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given data value.
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new digit at the beginning of the linked list.
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add two linked list representations of big integers.
struct Node* addBigIntegers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int carry = 0;

    while (num1 || num2 || carry) {
        int sum = carry;
        if (num1) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        insertAtBeginning(&result, sum % 10);
    }

    return result;
}


void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

int compareLinkedLists(struct Node* num1, struct Node* num2) {
    while (num1 != NULL && num2 != NULL) {
        if (num1->data > num2->data) return 1;
        else if (num1->data < num2->data) return 0;
        num1 = num1->next;
        num2 = num2->next;
    }
    return 1; // If we reach here, num1 >= num2
}

// Function to subtract two linked lists.
struct Node* subtractBigIntegers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    struct Node* temp = NULL;
    int borrow = 0;

    while (num1 != NULL || num2 != NULL) {
        int x = (num1 != NULL) ? num1->data : 0;
        int y = (num2 != NULL) ? num2->data : 0;
        int diff = x - y - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        insertAtBeginning(&result, diff);

        if (num1 != NULL) num1 = num1->next;
        if (num2 != NULL) num2 = num2->next;
    }

    while (result != NULL && result->data == 0) {
        temp = result;
        result = result->next;
        free(temp);
    }

    return result;
}

// Function to divide two linked lists.
struct Node* divideBigIntegers(struct Node* dividend, struct Node* divisor) {
    struct Node* quotient = NULL;
    struct Node* tempDividend = NULL;

    while (dividend != NULL) {
        int digit = 0;

        while (compareLinkedLists(dividend, divisor)) {
            dividend = subtractBigIntegers(dividend, divisor);
            digit++;
        }

        insertAtBeginning(&quotient, digit);

        if (dividend != NULL) {
            tempDividend = dividend->next;
            free(dividend);
            dividend = tempDividend;
        }
    }

    return quotient;
} 

void freeLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp); // Free the memory of the current node
    }
}

struct Node* make_empty_list(int size) 
{ 
    struct Node* head = NULL; 
    while (size--) 
        insertAtBeginning(&head, 0); 
    return head; 
} 
 

int reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next; 
    int len = 0; 
    while (current != NULL) { 
        len++; 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
    return len; 
} 

struct Node* reverseList(struct Node* root){
    struct Node* prev=NULL;
    struct Node* p=root;
    while(p!=NULL){
       struct Node* temp=p->next;
       p->next=prev;
       prev=p;
       p=temp;
    }

    return prev;
}
struct Node* multiplyBigIntegers(struct Node* first, struct Node* second) 
{ 
    
    int m = reverse(&first), n = reverse(&second); 
    struct Node* result = make_empty_list(m + n + 1); 
 
   
    struct Node *second_ptr = second, 
        *result_ptr1 = result, *result_ptr2, *first_ptr; 
 
 
    while (second_ptr) { 
 
        int carry = 0; 
        result_ptr2 = result_ptr1; 
 
        first_ptr = first; 
 
        while (first_ptr) { 

            
            int mul = first_ptr->data * second_ptr->data 
                    + carry; 
 
            
            result_ptr2->data += mul % 10; 
 
           
            carry = mul / 10 + result_ptr2->data / 10; 
            result_ptr2->data = result_ptr2->data % 10; 
 
            first_ptr = first_ptr->next; 
            result_ptr2 = result_ptr2->next; 
        } 
 
        
        if (carry > 0) { 
            result_ptr2->data += carry; 
        } 
 
        result_ptr1 = result_ptr1->next; 
        second_ptr = second_ptr->next; 
    } 
 
    reverse(&result); 
    reverse(&first); 
    reverse(&second); 
 

    while (result->data == 0) { 
        struct Node* temp = result; 
        result = result->next; 
        free(temp); 
    } 
    
    result=reverseList(result);
    return result; 
} 

