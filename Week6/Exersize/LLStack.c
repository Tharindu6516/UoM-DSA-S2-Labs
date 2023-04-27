struct Node
{
    int data;
    struct Node *Next;
};


struct Node* stack_create() {
    struct Node* stackt;
    stackt->data = 5;
    return stackt;
}