#include <cstdlib>
#include <stdexcept>
#include <iostream>

struct node {
    int data;
    struct node* next;
};

node* stack_create() {
    return nullptr;
}

int stack_is_empty(node* head) {
    return head == nullptr;
}

void stack_push(node& head, int data) {
    std::cout << data << std::endl;
    std::cout << &head << std::endl;
    node* newHead = new node{data, &head};
    std::cout << &head << std::endl;
    std::cout << newHead << std::endl;
    head = *newHead;
    std::cout << &head << std::endl;
}

int stack_pop(node* head) {
    if (stack_is_empty(head))
    {
        throw std::overflow_error("Stack Underflow.\n");
        exit(-1);
    }
    
    node* temp = head;
    int ret = head->data;
    head = head->next;
    free(temp);
    return ret;

}

void stack_print(node* head) {
    if (stack_is_empty(head)) {
        std::cout << "Stack Is Empty.\n";
        return;
    }
    
    node* n = head;
    std::cout << "[";
    while (n->next != nullptr) {
        std::cout << n->data << ", ";
        n = n->next;
    }
    std::cout << n->data << "]\n";
}