#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
struct Stack {
    int arr[MAX_SIZE];
    int top;
};
void initialize(struct Stack *stack) {
    stack->top = -1;
}
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push.\n");
        return;
    }
    stack->arr[++stack->top] = data;
}
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop.\n");
        return -1; // Return a sentinel value indicating an error
    }
    return stack->arr[stack->top--];
}
int evaluatePostfix(char expression[]) {
    struct Stack stack;
    initialize(&stack)
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0'); // Convert char to int
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    return -1; // Return a sentinel value indicating an error
            }
        }
    }
    return pop(&stack);
}
int main() {
    char expression[] = "23*5+"; // Postfix expression: 2 * 3 + 5
    int result = evaluatePostfix(expression);
    if (result != -1) {
        printf("Result of %s is: %d\n", expression, result);
    } else {
        printf("Error occurred while evaluating the expression.\n");
    }
    return 0;
}
