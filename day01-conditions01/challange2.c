#include <stdio.h>

int main() {
    char Car;

    printf(" taper un caractère : ");
    scanf("%c", &Car);
    switch (Car) {
        case 'i':
        case 'o':
        case 'e':
        case 'a':
        case 'u':
            printf(" une voyelle.\n", Car);
            break;
        default:
            printf(" n'est pas une voyelle.\n", Car);
    }

    return 0;
}