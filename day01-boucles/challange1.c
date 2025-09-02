#include <stdio.h>

int main() {
    int nbr;

    printf("taper le nombre : ");
    scanf("%d", &nbr);

    for (int i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", nbr, i, nbr * i);
    }

    return 0;
}
