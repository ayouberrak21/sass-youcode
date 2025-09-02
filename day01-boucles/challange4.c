#include <stdio.h>

int main() {
    int nbr, i;

    printf("taper un nombre entier : ");
    scanf("%d", &nbr);

    printf("le nombres impairs sont : ");

    for(i = 0; i < nbr; i++) {
        printf("%d", 2*i + 1);
        if (i < nbr - 1) {
            printf(", ");
        }
    }

    printf("\n");
    return 0;
}
