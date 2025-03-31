//1. Convert the following infix expressions to prefix expressions: [A] 
//? (A + B * C / D - E + F / G / (H + I)) 
//? (A + B) * C + D / (B + A * C) + D


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
char operatorStack[MAX];
int operatorTop = -1;
char resultStack[MAX][MAX];
int resultTop = -1,i;

// Function to push operators onto the operator stack
void pushOperator(char op) {
    operatorStack[++operatorTop] = op;
}

// Function to pop operators from the operator stack
char popOperator() {
    return operatorStack[operatorTop--];
}

// Function to push result onto the result stack
void pushResult(char *res) {
    strcpy(resultStack[++resultTop], res);
}

// Function to pop result from the result stack
void popResult(char *res) {
    strcpy(res, resultStack[resultTop--]);
}

// Function to get operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert infix to prefix
void infixToPrefix(char *infix, char *prefix)
{
    int len = strlen(infix);
    char reversed[MAX], result[MAX];
    int j = 0;

    // Step 1: Reverse the infix expression and handle parentheses
    for (i = len - 1; i >= 0; i--)
	{
        if (infix[i] == '(') {
            reversed[j++] = ')';
        } else if (infix[i] == ')') {
            reversed[j++] = '(';
        } else {
            reversed[j++] = infix[i];
        }
    }
    reversed[j] = '\0';

    // Step 2: Parse the reversed infix
    for (i = 0; i < j; i++) 
	{
        if (isalnum(reversed[i]))
		{  // Operand
            char operand[2] = {reversed[i], '\0'};
            pushResult(operand);
        }
		else if (reversed[i] == '(')
		{  // Left parenthesis
            pushOperator(reversed[i]);
        }
		else if (reversed[i] == ')')
		{  // Right parenthesis
            while (operatorTop != -1 && operatorStack[operatorTop] != '(')
			{
                char op = popOperator();
                char op1[MAX], op2[MAX], combined[MAX];
                popResult(op1);
                popResult(op2);
                sprintf(combined, "%c %s %s", op, op2, op1);
                pushResult(combined);
            }
            popOperator(); // Remove '('
        }
		else if (isOperator(reversed[i]))
		{  // Operator
            while (operatorTop != -1 && precedence(operatorStack[operatorTop]) >= precedence(reversed[i]))
			{
                char op = popOperator();
                char op1[MAX], op2[MAX], combined[MAX];
                popResult(op1);
                popResult(op2);
                sprintf(combined, "%c %s %s", op, op2, op1);
                pushResult(combined);
            }
            pushOperator(reversed[i]);
        }
    }

    // Step 3: Pop remaining operators
    while (operatorTop != -1)
	{
        char op = popOperator();
        char op1[MAX], op2[MAX], combined[MAX];
        popResult(op1);
        popResult(op2);
        sprintf(combined, "%c %s %s", op, op2, op1);
        pushResult(combined);
    }

    // Final result
    strcpy(prefix, resultStack[resultTop--]);
}

int main()
{
    char infix1[MAX] = "(A + B * C / D - E + F / G / (H + I))";
    char infix2[MAX] = "(A + B) * C + D / (B + A * C) + D";
    char prefix1[MAX], prefix2[MAX];

    // Convert infix to prefix
    infixToPrefix(infix1, prefix1);
    infixToPrefix(infix2, prefix2);

    // Print results
    printf("infix 1:%s \n",infix1);
    printf("\n");
    printf("Prefix of Infix 1: %s\n", prefix1);
    printf("\n");
    printf("infix 2:%s \n",infix2);
    printf("\n");
    printf("Prefix of Infix 2: %s\n", prefix2);
    printf("\n");

    return 0;
}
