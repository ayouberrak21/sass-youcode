#include <stdio.h>

int main() {
    int nbr;
    int i;
    int S;

    printf("taper un entier positif : ");
    scanf("%d", &nbr);

    if (nbr < 0) {
        printf("le nombre doit erte positif .\n");
    } else {
        for (i = 1; i <= nbr; i++) {
            S=S+i;
        }
        printf("la somme est : %d",S);
    }
    return 0;
}
