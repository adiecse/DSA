#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Initialize the stack and top
int stack[MAX_SIZE];
int top = -1;

// Check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Check if the stack is full
bool isFull() {
    return top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack is full. Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
}

// Pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // You can change this value if you want to handle empty stack differently
    }
    return stack[top--];
}

void evaluate(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (!isEmpty() && (ch == '+' || ch == '-' || ch == '/' || ch == '*')) {
            int second_operand = pop();
            int first_operand = pop();

            int val = 0;
            switch (ch) {
                case '+':
                    val = first_operand + second_operand;
                    break;
                case '-':
                    val = first_operand - second_operand;
                    break;
                case '*':
                    val = first_operand * second_operand;
                    break;
                case '/':
                    val = first_operand / second_operand;
                    break;
            }

            push(val);
        } else if (ch >= '0' && ch <= '9') {
            int value = ch - '0';
            push(value);
        }
    }
}

int main() {
    char str[100] = "48*";
    evaluate(str);
    
    if (isEmpty()) {
        printf("Stack is empty. No result.\n");
    } else {
        int result = pop();
        printf("Result of postfix expression: %d\n", result);
    }
    
    return 0;
}
