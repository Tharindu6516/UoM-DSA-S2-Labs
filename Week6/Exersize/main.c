#include "LLStack.c"
#include "stdio.h"

int main() {
    struct Node* stack =  stack_create();
    printf("abs : %d \n", stack->data);
}