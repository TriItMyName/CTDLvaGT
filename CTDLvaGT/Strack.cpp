#include <stdio.h>
#define MAX_SIZE 100

// Khai báo cấu trúc ngăn xếp (stack)
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Khởi tạo ngăn xếp rỗng
void initialize(Stack* stack) {
    stack->top = -1;
}

// Kiểm tra xem ngăn xếp có rỗng hay không
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Kiểm tra xem ngăn xếp đã đầy hay chưa
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Đẩy một phần tử vào ngăn xếp
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Khong co du bo nho cap phat");
    } else {
        stack->items[++(stack->top)] = item;
    }
}

// Lấy phần tử ở đỉnh ngăn xếp và loại bỏ nó
int pop(Stack* stack) {
    if (isEmpty(stack)) {
   
        return -1;
    } else {
        return stack->items[(stack->top)--];
    }
}

// Chuyển đổi số thập phân sang cơ số nhị phân
void decimalToBinary(int decimal) {
    Stack stack;
    initialize(&stack);

    while (decimal > 0) {
        int remainder = decimal % 2;
        push(&stack, remainder);
        decimal /= 2;
    }

    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
}

void ConvertDecimalToHexadecimal(int decimal) {
    Stack s;
    initialize(&s);

    while (decimal > 0) {
        int remainder = decimal % 16;
        push(&s, remainder);
        decimal /= 16;
    }

    printf("\nSo thap luc phan tuong ung: ");
    while (!isEmpty(&s)) {
        int hexDigit = pop(&s);
        if (hexDigit < 10) {
            printf("%d", hexDigit);
        } else {
            // Chuyển các giá trị 10-15 sang ký tự A-F
            printf("%c", 'A' + (hexDigit - 10));
        }
    }
    printf("\n");
}

void ConvertDecimalToOctal(int decimal) {
    Stack s;
    initialize(&s);

    if (decimal == 0) {
        push(&s, 0);
    } else {
        while (decimal > 0) {
            int remainder = decimal % 8;
            push(&s, remainder);
            decimal /= 8;
        }
    }

    printf("\nSo bat phan tuong ung: ");
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main() {
    int decimal;
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    ConvertDecimalToHexadecimal(decimal);

    ConvertDecimalToOctal(decimal);
    return 0;
}