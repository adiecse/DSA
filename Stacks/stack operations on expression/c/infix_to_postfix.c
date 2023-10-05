#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Initialize the stack
int top = -1;
char stack[MAX_SIZE];

// Check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Check if the stack is full
bool isFull() {
    return top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(char value) {
    if (isFull()) {
        printf("Stack is full. Cannot push %c\n", value);
        return;
    }
    stack[++top] = value;
}

// Pop an element from the stack
char pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }
    return stack[top--];
}

// Get the top element of the stack without popping
char peek() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot peek.\n");
        return '\0';
    }
    return stack[top];
}

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix
void convert(char str[], char ret[]) {
    int j = 0;
    char top;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (!isEmpty() && ch == '(') {
            push(ch);
        } else if (!isEmpty() && ch == ')') {
            top = peek();
            while (top != '(') {
                top = pop();
                ret[j] = top;
                j++;
                top = peek();
            }
            pop(); // Remove the '(' from the stack
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!isEmpty() && ((ch == '+' && peek() == '-') || (ch == '-' && peek() == '+') ||
                                  (ch == '*' && peek() == '/') || (ch == '/' && peek() == '*'))) {
                top = pop();
                ret[j] = top;
                j++;
            }
            push(ch);
        } else {
            ret[j] = ch;
            j++;
        }
    }
    while (!isEmpty()) {
        ret[j] = pop();
        j++;
    }
    ret[j] = '\0';
}

int main() {
    char infix[] = "a+b*(c-d)/e";
    char postfix[MAX_SIZE];
    convert(infix, postfix);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
