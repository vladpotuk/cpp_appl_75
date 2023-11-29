#ifndef STACK_H
#define STACK_H

struct Node {
    double data;
    Node* next;
};

typedef Node* Stack;

void push(Stack& topPtr, double value);
double pop(Stack& topPtr);
double top(const Stack& topPtr);
bool isEmpty(const Stack& topPtr);

#endif 

