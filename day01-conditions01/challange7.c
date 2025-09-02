#include <stdio.h>

int main() {
    char c;
    printf("taper un caractère : ");
    scanf("%c", &c);

    if (c >= 65 && c <= 90) {
        printf("est une lettre majuscule.\n", c);
    } else {
        printf(" est une lettre minuscule.\n", c);
    }

    return 0;
}
