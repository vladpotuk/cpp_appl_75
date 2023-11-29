#include "calculator.h"
#include <iostream>

int main() {
    system("chcp 1251");
    system("cls");
    const int MAX_EXPRESSION_LENGTH = 100;
    char expression[MAX_EXPRESSION_LENGTH];

    std::cout << "Enter an arithmetic expression: ";
    std::cin.getline(expression, MAX_EXPRESSION_LENGTH);

    double result = evaluateExpression(expression);

    
    std::cout << "\n+--------------------------+\n";
    std::cout << "| Àð³ôìåòè÷íà ä³ÿ          |\n";
    std::cout << "|--------------------------|\n";
    std::cout << "| " << expression;
    for (int i = 0; i < 26 - std::strlen(expression); ++i)
        std::cout << " ";
    std::cout << "|\n";
    std::cout << "|--------------------------|\n";
    std::cout << "| Â³äïîâ³äü                |\n";
    std::cout << "|--------------------------|\n";
    std::cout << "| " << result;
    for (int i = 0; i < 26 - (result < 0 ? 2 : 1) - (int)result / 10; ++i)
        std::cout << " ";
    std::cout << "|\n";
    std::cout << "+--------------------------+\n";

    return 0;
}
