#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Check if the stack is full
bool isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d\n", value);
        return;
    }
    s->items[++s->top] = value;
}

// Pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // You can change this value if you want to handle empty stack differently
    }
    return s->items[s->top--];
}

void evaluate(char exp[]) {
    struct Stack st;
    initStack(&st);

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (!isEmpty(&st) && (ch == '+' || ch == '-' || ch == '/' || ch == '*')) {
            int second_operand = pop(&st);
            int first_operand = pop(&st);

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

            push(&st, val);
        } else if (ch >= '0' && ch <= '9') {
            int value = ch - '0';
            push(&st, value);
        }
    }

    if (isEmpty(&st)) {
        printf("Stack is empty. No result.\n");
    } else {
        int result = pop(&st);
        printf("Result of postfix expression: %d\n", result);
    }
}

int main() {
    char str[100] = "48*";
    evaluate(str);
    
    return 0;
}
