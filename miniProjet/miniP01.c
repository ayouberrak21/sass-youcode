#include <stdio.h>
#include <string.h>

int main(){
    int choix;
    char titre[10][50];
    char auteur[10][50];
    int prix[10];
    int quantite[10];
    int i;
    int nbl=0;
    do{
    printf("==========  MENU  =========")
    printf("1.Ajouter un livre au stock.\n");
    printf("2.Afficher tous les livres disponibles.\n");
    printf("3.Rechercher un livre par son titre.\n");
    printf("4.Mettre à jour la quantité d'un livre.\n");
    printf("5.Supprimer un livre du stock.\n");
    printf("6.Afficher le nombre total de livres en stock.\n");
    printf("7.quitter\n");
    printf("taper ton choix :");
    scanf("%d",&choix);

    switch (choix) {
    case 1 :
        if (nbl<10){
        printf("taper le titre de livre :");
        scanf("%s",&titre[nbl]);
        printf("taper le auteur de livre :");
        scanf("%s",&auteur[nbl]);
        printf("taper le prix de livre :");
        scanf("%d",&prix[nbl]);
        printf("taper le quantite dans le stok :");
        scanf("%d",&quantite[nbl]);
        printf("%s  %s  %d  %d  \n\n",titre[nbl],auteur[nbl],prix[nbl],quantite[nbl]);
        nbl++;
        }else printf("le stock est plein\n\n");
        break;
    case 2:
        if(nbl==0){
                printf("aucun livre en stock.\n\n");
            }else{
                for(i=0;i<nbl;i++) {
                    if(quantite[i]>0) {
                        printf("%s  %s  %d  %d \n\n",titre[i], auteur[i], prix[i], quantite[i]);
                    }
                }
            }
            break;
    case 3:
        char titreD[10];
        printf("taper le titre de livre :");
        scanf("%s",&titreD);
            for(i=0;i<nbl;i++){
            if(strcmp(titreD, titre[i])!=0){
                    printf("il n'a pas ce livre \n \n ");
            }
            else {
                for(i=0;i<nbl;i++){
                    printf("%s  %s  %d  %d  \n\n",titre[i],auteur[i],prix[i],quantite[i]);
            }
            }
            }
            break;
     case 4:
            char titrede[50];
            char OuiNon1[3];
            int tr = 0;
            printf("taper le titre : ");
            scanf("%s", titrede);

            for (i=0;i<nbl;i++){
                if (strcmp(titrede,titre[i])==0) {
                    tr = 1;
                    printf("vous voulait vraiment supprimer le livre (oui/non) : ");
                    scanf("%s",&OuiNon1);
                    if(strcmp(OuiNon1,"oui") == 0){
                        printf("nouveau quantite : ");
                        scanf("%d", &quantite[i]);
                        printf("\n");
                        break;
                    }else
                        break;
                }
            }
            if (!tr) {
                printf("il n a pas ce livre.\n\n");
            }
            break;

        case 5:
            char titreS[50];
            int true = 0;
            char OuiNon2[3];
            printf("taper le titre  : ");
            scanf("%s", titreS);

            for (i = 0; i < nbl; i++) {
                if (strcmp(titre[i],titreS ) == 0) {
                    true = 1;
                    printf("vous voulait vraiment supprimer le livre (oui/non) : ");
                    scanf("%s",&OuiNon2);
                    if(strcmp(OuiNon2,"oui") == 0){
                        printf("\n");
                        for (int j=i;j<nbl-1;j++){
                            strcpy(titre[j], titre[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            prix[j] = prix[j + 1];
                            quantite[j] = quantite[j + 1];
                        }
                    nbl--;
                    break;
                }else
                    break;
            }
            }
            if (!true) {
            printf("il n a pas ce livre .\n\n");
        }
        break;
        case 6 :
            int s=0 ;
            for(int i=0;i<nbl;i++){
                s=s+quantite[i];
            }
            printf("le nombre de livre en stok est : %d\n\n",s);


    }
    }while (choix!=7);

    }

