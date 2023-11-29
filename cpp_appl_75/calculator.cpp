#include "calculator.h"
#include "stack.h"
#include <iostream>

namespace {
    int getPriority(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    bool isSpace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v';
    }

    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    double applyOperator(double operand1, double operand2, char op) {
        switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1 / operand2;
            else {
                std::cerr << "Error: Division by zero\n";
                exit(EXIT_FAILURE);
            }
        default:
            std::cerr << "Error: Unknown operator\n";
            exit(EXIT_FAILURE);
        }
    }
} // namespace

double evaluateExpression(const char* expression) {
    Stack operands = nullptr;
    Stack operators = nullptr;

    while (*expression) {
        if (isSpace(*expression)) {
            ++expression;
            continue; // Ignore spaces
        }

        if (isDigit(*expression)) {
            push(operands, *expression - '0');
        }
        else if (*expression == '(') {
            push(operators, *expression);
        }
        else if (*expression == ')') {
            while (!isEmpty(operators) && top(operators) != '(') {
                double operand2 = pop(operands);
                double operand1 = pop(operands);
                char op = pop(operators);
                push(operands, applyOperator(operand1, operand2, op));
            }

            pop(operators); // Pop '('
        }
        else {
            while (!isEmpty(operators) && getPriority(top(operators)) >= getPriority(*expression)) {
                double operand2 = pop(operands);
                double operand1 = pop(operands);
                char op = pop(operators);
                push(operands, applyOperator(operand1, operand2, op));
            }

            push(operators, *expression);
        }

        ++expression;
    }

    while (!isEmpty(operators)) {
        double operand2 = pop(operands);
        double operand1 = pop(operands);
        char op = pop(operators);
        push(operands, applyOperator(operand1, operand2, op));
    }

    return pop(operands);
}
