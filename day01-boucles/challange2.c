#include <stdio.h>

int main() {
    int nbr;
    int fac =1 ;
    int i;

    printf("taper un entier positif : ");
    scanf("%d", &nbr);

    if (nbr < 0) {
        printf("le nombre doit erte positif .\n");
    } else {
        for ( i = 1; i <= n; i++) {
            fac *= i;
        }
        printf("%d! = %d\n", nbr, fac);
    }
    return 0;
}
