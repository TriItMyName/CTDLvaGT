#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc ngăn xếp
struct Stack {
    char data;
    struct Stack* next;
};

// Hàm kiểm tra xem một ký tự có phải là toán tử hay không
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Hàm kiểm tra độ ưu tiên của các toán tử
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

// Hàm thêm một phần tử vào ngăn xếp
void push(struct Stack** top, char data) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Hàm lấy và loại bỏ một phần tử khỏi ngăn xếp
char pop(struct Stack** top) {
    if (*top == NULL) {
        fprintf(stderr, "Ngan xep rong\n");
        exit(EXIT_FAILURE);
    }
    char data = (*top)->data;
    struct Stack* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Hàm chuyển đổi biểu thức từ trung tố sang hậu tố
void infixToPostfix(char* infixExpression) {
    struct Stack* stack = NULL;
    char postfixExpression[1000];
    int postfixIndex = 0;

    for (int i = 0; infixExpression[i] != '\0'; i++) {
        if (infixExpression[i] >= '0' && infixExpression[i] <= '9') {
            postfixExpression[postfixIndex++] = infixExpression[i];
        } else if (infixExpression[i] == '(') {
            push(&stack, infixExpression[i]);
        } else if (infixExpression[i] == ')') {
            while (stack != NULL && stack->data != '(') {
                postfixExpression[postfixIndex++] = pop(&stack);
            }
            pop(&stack); // Loại bỏ dấu mở ngoặc
        } else if (isOperator(infixExpression[i])) {
            while (stack != NULL && precedence(infixExpression[i]) <= precedence(stack->data)) {
                postfixExpression[postfixIndex++] = pop(&stack);
            }
            push(&stack, infixExpression[i]);
        }
    }

    while (stack != NULL) {
        postfixExpression[postfixIndex++] = pop(&stack);
    }

    postfixExpression[postfixIndex] = '\0';

    printf("%s", postfixExpression);
}

int main() {
    char infixExpression[1000];
  
    scanf("%s", infixExpression);
    infixToPostfix(infixExpression);
    return 0;
}