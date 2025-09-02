#include <stdio.h>
#include <math.h>


int main() {
    int annee;
    int mois;
    int jour;
    int heure;
    int minute;
    int seconde;
    int choix;
    printf("taper l'anne : ");
    scanf("%d",&annee);
    printf("\n1, covertir en mois \n ");
    printf("2, covertir en jours \n ");
    printf("3, covertir en heures \n ");
    printf("4, covertir en minutes  \n");
    printf("5, covertir en seconde  \n");
    printf("taper ton choix:");
    scanf("%d",&choix);
    mois = annee*12;
    jour=mois*30;
    heure=jour*24;
    minute=heure*60;
    seconde=minute*60;
    switch (choix){
        case 1:
            printf("%d",mois);
            break;
        case 2:
            printf("%d",jour);
            break;
        case 3:
            printf("%d",heure);
            break;
        case 4:
            printf("%d",minute);
            break;
        case 5:
            printf("%d",seconde);
            break;

}
return 0;
}
