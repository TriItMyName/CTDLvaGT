#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc cho một hạng tử đa thức
typedef struct Term {
    int coefficient; // Hệ số
    int exponent;   // Số mũ
    struct Term* next;
} Term;

// Hàm tạo một hạng tử mới
Term* createTerm(int coef, int exp) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coef;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Hàm chèn một hạng tử vào đa thức
void insertTerm(Term** polynomial, int coef, int exp) {
    Term* newTerm = createTerm(coef, exp);
    if (*polynomial == NULL || exp > (*polynomial)->exponent) {
        newTerm->next = *polynomial;
        *polynomial = newTerm;
    } else {
        Term* current = *polynomial;
        while (current->next != NULL && exp < current->next->exponent) {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

// Hàm xóa một hạng tử khỏi đa thức
void deleteTerm(Term** polynomial, int exp) {
    if (*polynomial == NULL) {
        return;
    }
    if ((*polynomial)->exponent == exp) {
        Term* temp = *polynomial;
        *polynomial = (*polynomial)->next;
        free(temp);
    } else {
        Term* current = *polynomial;
        while (current->next != NULL && current->next->exponent != exp) {
            current = current->next;
        }
        if (current->next != NULL) {
            Term* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
}

// Hàm đếm số lượng hạng tử trong đa thức
int countTerms(Term* polynomial) {
    int count = 0;
    Term* current = polynomial;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Hàm tìm hạng tử trong đa thức với số mũ cho trước
Term* findTerm(Term* polynomial, int exp) {
    Term* current = polynomial;
    while (current != NULL && current->exponent != exp) {
        current = current->next;
    }
    return current;
}

// Hàm in đa thức
void printPolynomial(Term* polynomial) {
    if (polynomial == NULL) {
        printf("0");
    } else {
        while (polynomial != NULL) {
            printf("%dX^%d", polynomial->coefficient, polynomial->exponent);
            if (polynomial->next != NULL) {
                printf(" + ");
            }
            polynomial = polynomial->next;
        }
    }
    printf("\n");
}

int main() {
    Term* polynomial = NULL;

    // Chèn các hạng tử vào đa thức
    insertTerm(&polynomial, 3, 2);
    insertTerm(&polynomial, 5, 1);
    insertTerm(&polynomial, 2, 3);

    printf("Da thuc: ");
    printPolynomial(polynomial);

    // Xóa hạng tử với số mũ 2
    deleteTerm(&polynomial, 2);

    printf("Da thuc sau khi xoa hạng tử với số mũ 2: ");
    printPolynomial(polynomial);

    // Đếm số lượng hạng tử trong đa thức
    int termCount = countTerms(polynomial);
    printf("So luong hang tu trong da thuc: %d\n", termCount);

    // Tìm hạng tử với số mũ 3
    Term* foundTerm = findTerm(polynomial, 3);
    if (foundTerm != NULL) {
        printf("Hang tu co so mu 3: %dX^%d\n", foundTerm->coefficient, foundTerm->exponent);
    } else {
        printf("Khong tim thay hang tu co so mu 3.\n");
    }

    return 0;
}
