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
        printf("Ngan xep da day. Khong the them phan tu moi!\n");
    } else {
        stack->items[++(stack->top)] = item;
    }
}

// Lấy phần tử ở đỉnh ngăn xếp và loại bỏ nó
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong. Khong the lay phan tu!\n");
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

    printf("Ket qua chuyen doi sang co so nhi phan: ");
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main() {
    int decimal;

    printf("Nhap mot so thap phan: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}