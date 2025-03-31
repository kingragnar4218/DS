#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100


char stack[MAX];
int top = -1;


int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}


void push(char c) {
    stack[++top] = c;
}


char pop() {
    return stack[top--];
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');                                                            
}


void infixToPostfix(char *infix, char *postfix) {
    int i = 0, k = 0;
    char symbol;
    
    
    while ((symbol = infix[i++]) != '\0') {
        if (isalnum(symbol)) {
            
            postfix[k++] = symbol;
        }
		 else if (symbol == '(') {
            
            push(symbol);
        } 
		else if (symbol == ')') {
            
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); 
        } 
		else if (isOperator(symbol)) {
            
            while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                postfix[k++] = pop();
            }
            push(symbol); 
        }
    }
    
    
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

   
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; 

    
    infixToPostfix(infix, postfix);

   
    printf("Postfix expression: %s\n", postfix);

    return 0;
}


