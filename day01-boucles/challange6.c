#include <stdio.h>

int main() {
    int nbr;

    printf("taper le  nombre entier  : ");
    scanf("%d", &nbr);

    printf("les premiers nombres pair sont : ");
    for (int i = 1; i <= nbr; i++) {
        printf("%d", 2 * i);
        if (i < nbr) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}
