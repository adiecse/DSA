#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE][MAX_SIZE];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

bool isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, const char *value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %s\n", value);
        return;
    }
    strcpy(s->items[++s->top], value);
}

void pop(struct Stack *s) {
    if (!isEmpty(s)) {
        s->top--;
    }
}

void convert(char postfix[], char *infix) {
    struct Stack st;
    initStack(&st);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (!isEmpty(&st) && (ch == '+' || ch == '-' || ch == '*' || ch == '/')) {
            char second_operand[MAX_SIZE];
            strcpy(second_operand, st.items[st.top]);
            pop(&st);

            char first_operand[MAX_SIZE];
            strcpy(first_operand, st.items[st.top]);
            pop(&st);

            char exp[MAX_SIZE];
            switch (ch) {
                case '+':
                case '-':
                case '*':
                case '/':
                    sprintf(exp, "(%s%c%s)", first_operand, ch, second_operand);
                    break;
            }
            push(&st, exp);
        } else {
            char value[2] = {ch, '\0'};
            push(&st, value);
        }
    }
    
    strcpy(infix, st.items[st.top]);
}

int main() {
    char postfix[] = "ab*dc+/e*";
    char infix[MAX_SIZE];
    struct Stack st;
    initStack(&st);
    convert(postfix, infix);
    printf("Infix is: %s\n", infix);
    return 0;
}
