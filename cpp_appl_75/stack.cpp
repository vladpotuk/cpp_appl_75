#include "stack.h"

void push(Stack& topPtr, double value) {
    Node* newNode = new Node{ value, topPtr };
    topPtr = newNode;
}

double pop(Stack& topPtr) {
    if (isEmpty(topPtr)) {
        return 0.0; 
    }

    double value = topPtr->data;
    Node* temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
    return value;
}

double top(const Stack& topPtr) {
    if (isEmpty(topPtr)) {
      
        return 0.0;
    }

    return topPtr->data;
}

bool isEmpty(const Stack& topPtr) {
    return topPtr == nullptr;
}
