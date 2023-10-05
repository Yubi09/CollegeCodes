#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coefficient;
    int exponent;
} Term;

Term* addPolynomials(Term* poly1, int size1, Term* poly2, int size2, int* resultSize) {
    int i = 0, j = 0, k = 0;
    int maxSize = (size1 > size2) ? size1 : size2;
    Term* result = (Term*)malloc(maxSize * sizeof(Term));

    while (i < size1 && j < size2) {
        if (poly1[i].exponent == poly2[j].exponent) {
            int sumCoefficients = poly1[i].coefficient + poly2[j].coefficient;
            if (sumCoefficients != 0) {
                result[k].coefficient = sumCoefficients;
                result[k].exponent = poly1[i].exponent;
                k++;
            }
            i++;
            j++;
        } else if (poly1[i].exponent > poly2[j].exponent) {
            result[k] = poly1[i];
            i++;
            k++;
        } else {
            result[k] = poly2[j];
            j++;
            k++;
        }
    }

    while (i < size1) {
        result[k] = poly1[i];
        i++;
        k++;
    }

    while (j < size2) {
        result[k] = poly2[j];
        j++;
        k++;
    }

    *resultSize = k;
    return result;
}

void displayPolynomial(Term* polynomial, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if(polynomial[i].exponent == 0){
            printf("%d", polynomial[i].coefficient);
        }
        if (polynomial[i].coefficient != 0) {
            printf("%dx^%d", polynomial[i].coefficient, polynomial[i].exponent);
            if (i < size - 1 && polynomial[i + 1].coefficient != 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main() {
    int size1, size2, resultSize;
    int i;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &size1);
    Term* poly1 = (Term*)malloc(size1 * sizeof(Term));
    for (i = 0; i < size1; i++) {
        printf("Enter the coefficient: ");
        scanf("%d", &poly1[i].coefficient);
        printf("Enter the exponent: ");
        scanf("%d", &poly1[i].exponent);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &size2);
    Term* poly2 = (Term*)malloc(size2 * sizeof(Term));
    for (i = 0; i < size2; i++) {
        printf("Enter the coefficient: ");
        scanf("%d", &poly2[i].coefficient);
        printf("Enter the exponent: ");
        scanf("%d", &poly2[i].exponent);
    }

    Term* result = addPolynomials(poly1, size1, poly2, size2, &resultSize);

    printf("Resultant polynomial: ");
    displayPolynomial(result, resultSize);

    free(poly1);
    free(poly2);
    free(result);

    return 0;
}