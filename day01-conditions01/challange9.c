#include <stdio.h>

int main() {
    char c;
    printf("taper un caractère : ");
    scanf("%c", &c);

    if (c>='A' && c<='Z') {
        printf("une lettre majuscule.\n");
    }
    else if (c>='a' && c<='z') {
        printf("une lettre minuscule.\n");
    }
    else {
        printf("n'est pas une lettre alphabetique.\n");
    }

    return 0;
}
