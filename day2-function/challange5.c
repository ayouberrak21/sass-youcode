#include <stdio.h>

int factorielle(int nbr) {
    if (nbr < 0) {
        return 0;
    }
    int resulta = 1;
    for (int i = 1; i <= nbr; i++) {
        resulta=resulta*i;
    }
    return resulta;
}

int main() {
    int nombre;

    printf("taper un nombre positif : ");
    scanf("%d", &nombre);

    if (nombre < 0) {
        printf("le nombre doit etre positif \n");
    } else {
        printf("La factorielle est %d\n", factorielle(nombre));
    }

    return 0;
}
