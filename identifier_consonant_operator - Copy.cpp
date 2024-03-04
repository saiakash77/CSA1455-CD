#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    IDENTIFIER,
    CONSTANT,
    OPERATOR
} TokenType;

bool isOperator(char ch) {
    char operators[] = "+-*/=";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return true;
    }
    return false;
}

bool isValidIdentifierChar(char ch) {
    return isalnum(ch) || ch == '_';
}

TokenType analyzeInput(char* input) {
    int length = strlen(input);

    if (length == 1 && isOperator(input[0])) {
        return OPERATOR;
    }
    else if (isdigit(input[0])) {
        bool isConstant = true;
        for (int i = 1; i < length; i++) {
            if (!isdigit(input[i])) {
                isConstant = false;
                break;
            }
        }
        if (isConstant)
            return CONSTANT;
    }
    else if (isValidIdentifierChar(input[0])) {
        bool isIdentifier = true;
        for (int i = 1; i < length; i++) {
            if (!isValidIdentifierChar(input[i])) {
                isIdentifier = false;
                break;
            }
        }
        if (isIdentifier)
            return IDENTIFIER;
    }


    return -1;
}

int main() {
    char input[100];

    printf("Enter an input string: ");
    scanf("%s", input);

    TokenType tokenType = analyzeInput(input);

    if (tokenType == IDENTIFIER)
        printf("Input is an identifier.\n");
    else if (tokenType == CONSTANT)
        printf("Input is a constant.\n");
    else if (tokenType == OPERATOR)
        printf("Input is an operator.\n");
    else
        printf("Invalid token.\n");

    return 0;
}
