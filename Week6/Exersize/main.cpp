#include "LLStack.cpp"
#include <iostream>

int main() {
    node* stack = stack_create();
    std::cout << stack << std::endl;
    std::cout << stack_is_empty(stack) << std::endl;
    std::cout << stack_is_empty(nullptr) << std::endl;
    stack_print(stack);
    stack_push(*stack, 5);
    stack_print(stack);
    stack_print(stack);
    stack_push(*stack, -8);
    stack_print(stack);
    int a = stack_pop(stack);
    stack_print(stack);
    int b = stack_pop(stack);
    stack_print(stack);
    std::cout << a << " " << b << std::endl;
    return 0;
}