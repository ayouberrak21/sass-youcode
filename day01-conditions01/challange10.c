#include <stdio.h>

int main() {
    int jour, mois, anne;
    char *lesmois[] = {
        "", "Janvier", "Février", "Mars", "Avril", "Mai", "Juin",
        "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"
    };

    printf("taper une date  jj/mm/aaaa : ");
    scanf("%d/%d/%d", &jour, &mois, &anne);


    printf("%02d-%s-%d\n", jour, lesmois[mois], anne);

    return 0;
}
