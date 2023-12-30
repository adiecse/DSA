#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for the stack
struct Stack {
    char items[MAX_SIZE];
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
void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %c\n", value);
        return;
    }
    s->items[++s->top] = value;
}

// Pop an element from the stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }
    return s->items[s->top--];
}

// Get the top element of the stack without popping
char peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
        return '\0';
    }
    return s->items[s->top];
}

// Function to convert infix expression to postfix
void convert(char str[], struct Stack *st, char ret[]) {
    int j = 0;
    char top;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (!isEmpty(st) && ch == '(') {
            push(st, ch);
        } else if (!isEmpty(st) && ch == ')') {
            top = peek(st);
            while (top != '(') {
                top = pop(st);
                ret[j] = top;
                j++;
                top = peek(st);
            }
            pop(st); // Remove the '(' from the stack
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!isEmpty(st) && ((ch == '+' && peek(st) == '-') || (ch == '-' && peek(st) == '+') ||
                                     (ch == '*' && peek(st) == '/') || (ch == '/' && peek(st) == '*'))) {
                top = pop(st);
                ret[j] = top;
                j++;
            }
            push(st, ch);
        } else {
            ret[j] = ch;
            j++;
        }
    }
    while (!isEmpty(st)) {
        ret[j] = pop(st);
        j++;
    }
    ret[j] = '\0';
}

int main() {
    struct Stack st;
    initStack(&st);
    char infix[] = "a+b*(c-d)/e";
    char postfix[MAX_SIZE];
    convert(infix, &st, postfix);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
