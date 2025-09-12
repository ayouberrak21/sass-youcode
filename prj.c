#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 30

typedef struct {
    int id;
    char nom[30];
    char prenom[30];
    int numeroMaillot;
    char poste[15];
    int age;
    int buts;
    char dateInscription[20];
    char statut[15];
} Joueur;

Joueur equipe[MAX];
int nbJoueurs = 0;
int nextId = 1;

int ValidNumMaillot(int numero) {
    for(int i =0;i<nbJoueurs; i++) {
        if(equipe[i].numeroMaillot == numero)
            return 1;
    }
    return 0;
}

void retureMenu() {
    printf("\n appuyez sur entree pour revenir au menu ");
    getchar();
    getchar();
    system("cls");
}

int validerDate(char date[20]) {
    int jour,mois,annee;

    if(strlen(date)!=10) return 0;
    if(date[2]!='/' || date[5]!='/')
        return 0;

    for(int i=0; i<10; i++) {
        if(i==2 || i==5) continue;
        if(!isdigit(date[i])) return 0;
    }

    sscanf(date, "%2d/%2d/%4d",&jour,&mois,&annee);

    if(jour<1 || jour>30) return 0;
    if(mois<1 || mois>12) return 0;
    if(annee<1900 || annee>2025) return 0;

    return 1;
}

void afficherTableauEntete() {
    printf("\n===================================================================================================================\n");
    printf("| ID |      Nom      |    Prenom    | Maillot |    Poste    | Age | Buts |  Date insc.  |   Statut   |\n");
    printf("===================================================================================================================\n");
}

void afficherTableauLigne(Joueur j) {
    printf("| %-2d | %-12s | %-11s | %-7d | %-10s | %-3d | %-4d | %-12s | %-9s |\n",
           j.id, j.nom, j.prenom, j.numeroMaillot, j.poste, j.age, j.buts, j.dateInscription, j.statut);
}

void afficherTableauFin() {
    printf("===================================================================================================================\n");
}

void ajouterChanpsJoueur(){
    int choixP;
    if(nbJoueurs>=MAX){
        printf("la liste des joueurs est plaine ");
        retureMenu();
    }

    Joueur j;
    j.id=nextId++;

    printf("Taper le nom : ");
    scanf("%s", j.nom);

    printf("Taper le prenom : ");
    scanf("%s", j.prenom);

    int numero;
    do {
        printf("taper le numero de maillot : ");
        scanf("%d", &numero);
        if(numero<=0 || numero>=100){
            printf("le numero est incorect \n");
        }else if(ValidNumMaillot(numero)) {
            printf("ce numero a un autre joueur \n");
        }
    } while(ValidNumMaillot(numero) || numero<=0 || numero>=100);
    j.numeroMaillot = numero;

    printf("taper le poste ( 1: gardien / 2: defenseur / 3: milieu / 4: attaquant ) \n ");
    printf("taper ton choix : ");
    scanf("%d",&choixP);
    switch(choixP) {
        case 1: strcpy(j.poste,"gardien"); break;
        case 2: strcpy(j.poste,"defenseur"); break;
        case 3: strcpy(j.poste,"milieu"); break;
        case 4: strcpy(j.poste,"attaquant"); break;
        default: strcpy(j.poste,"inconnu"); printf("le poste est inconue\n");
    }

    do{
        printf("taper votre age : ");
        scanf("%d", &j.age);
        if(j.age<=18 || j.age>=45){
            printf("l age de joueurs n'est pas convenable \n");
        }
    }while(j.age<=18 || j.age>=45);

    do{
        printf("taper le nombre de buts de joueur : ");
        scanf("%d", &j.buts);
        if(j.buts<0){
            printf("nombre de buts invalid ");
        }
    }while(j.buts<0);

    do {
        printf("taper date d inscription (JJ/MM/AAAA) : ");
        scanf("%s", j.dateInscription);
        if(!validerDate(j.dateInscription)) {
            printf(" date invalide \n");
        }
    } while(!validerDate(j.dateInscription));

    int choixS;
    printf("Statut (1: titulaire / 2: remplacant) \n ");
    printf("taper votre choix : ");
    scanf("%d", &choixS);
    switch(choixS) {
        case 1: strcpy(j.statut, "titulaire"); break;
        case 2: strcpy(j.statut, "remplacant"); break;
        default: strcpy(j.statut, "inconnu"); printf("le status et inconue \n");
    }

    equipe[nbJoueurs++] = j;
    printf(" joueur ajoute avec succes.\n");
    retureMenu();
}

void ajouteJoueur(){
    int choix;
    do {
        printf("\n=============================\n");
        printf("|       Menu d ajout        |");
        printf("\n=============================\n");
        printf("|      1: choix simple      |\n");
        printf("|      2: choix multiple    |\n");
        printf("|         0: quitter        |\n");
        printf("=============================\n");
        printf("taper votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterChanpsJoueur();
                break;
            case 2: {
                int choix1;
                do {
                    printf("\n==========================\n");
                    printf("|      Menu multiple     |\n");
                    printf("==========================\n");
                    printf("|       1: continuer     |\n");
                    printf("|       0: quitter       |\n");
                    printf("==========================\n");
                    printf("taper votre choix : ");
                    scanf("%d", &choix1);
                    if(choix1==1) ajouterChanpsJoueur();

                } while (choix1 != 0);
                break;
            }
            case 0:
                retureMenu();
                break;
            default:
                printf("choix invalide\n");
        }
    } while (choix != 0);

}

void triNom() {
    Joueur temp;
    for (int i=0;i<nbJoueurs-1;i++) {
        for (int j=i+1;j<nbJoueurs;j++) {
            if (strcmp(equipe[i].nom, equipe[j].nom) > 0) {
                temp = equipe[i];
                equipe[i] = equipe[j];
                equipe[j] = temp;
            }
        }
    }
}

void triAge() {
    Joueur temp;
    for (int i=0;i<nbJoueurs-1;i++) {
        for (int j=i+1;j<nbJoueurs;j++) {
            if (equipe[i].age > equipe[j].age) {
                temp = equipe[i];
                equipe[i] = equipe[j];
                equipe[j] = temp;
            }
        }
    }
}

void triPoste() {
    int choix;
    char posteSelect[20];
    int trouve = 0;

    printf("\n=== Affichage par poste ===\n");
    printf("1: Gardien\n");
    printf("2: Defenseur\n");
    printf("3: Milieu\n");
    printf("4: Attaquant\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix){
        case 1: strcpy(posteSelect, "gardien"); break;
        case 2: strcpy(posteSelect, "defenseur"); break;
        case 3: strcpy(posteSelect, "milieu"); break;
        case 4: strcpy(posteSelect, "attaquant"); break;
        default: printf("choix invalid .\n"); return;
    }

    afficherTableauEntete();
    for (int i = 0; i < nbJoueurs; i++) {
        if (strcmp(equipe[i].poste, posteSelect) == 0) {
            afficherTableauLigne(equipe[i]);
            trouve = 1;
        }
    }
    afficherTableauFin();

    if (!trouve) {
        printf("il n y a auncun joueur \n");
    }
}
void afficherUnJoueur(Joueur j) {
    printf("===================================================================================================================\n");
    printf("| ID |      Nom      |    Prénom    | Maillot |    Poste    | Age | Buts |  Date insc.  |   Statut   |\n");
    printf("===================================================================================================================\n");
    printf("| %-2d | %-12s | %-11s | %-7d | %-10s | %-3d | %-4d | %-12s | %-9s |\n",
           j.id, j.nom, j.prenom, j.numeroMaillot, j.poste, j.age, j.buts, j.dateInscription, j.statut);
    printf("===================================================================================================================\n");
    retureMenu();
}
void joueurStar() {
    if (nbJoueurs == 0) {
        printf("\nAucun joueur enregistré.\n");
        return;
    }

    int indexMax = 0;
    for (int i = 1; i < nbJoueurs; i++) {
        if (equipe[i].buts > equipe[indexMax].buts) {
            indexMax = i;
        }
    }

    printf("\n Star de l’équipe (meilleur buteur) \n");
    afficherUnJoueur(equipe[indexMax]);
}
void afficherJoueurs() {
    if (nbJoueurs == 0) {
        printf("\nil n ya aucun joueur \n");
        retureMenu();
        return;
    }
    afficherTableauEntete();
    for (int i = 0; i < nbJoueurs; i++) {
        afficherTableauLigne(equipe[i]);
    }
    afficherTableauFin();
}

void menuAffichage() {
    int choix;
    do {
        printf("\n========================================================\n");
        printf("|                    Menu d affichage                  |\n");
        printf("========================================================\n");
        printf("|  1: afficher les joueur par ordre alphabetique (Nom) |\n");
        printf("|        2: afficher les joueurs par le moins agee     |\n");
        printf("|           3: afficher les joueurs par poste          |\n");
        printf("|            4: afficher tous les joueurs              |\n");
        printf("|                     0: Quitter                       |\n");
        printf("========================================================\n");

        printf("Votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: triNom(); afficherJoueurs(); break;
            case 2: triAge(); afficherJoueurs(); break;
            case 3: triPoste(); break;
            case 4: afficherJoueurs(); break;
            case 0: retureMenu(); break;
            default: printf("choix invalide\n"); break;
        }
    } while (choix != 0);

}

void rechercherId() {
    int id, trouve = 0;
    printf("taper id de joueur : ");
    scanf("%d", &id);

    afficherTableauEntete();
    for (int i=0;i<nbJoueurs;i++) {
        if (equipe[i].id == id) {
            afficherTableauLigne(equipe[i]);
            trouve = 1;
            break;
        }
    }
    afficherTableauFin();

    if (!trouve) {
        printf("il n ya aucun joueur avec id %d.\n", id);
    }
}

void rechercherNom() {
    char nom[30];
    int trouve = 0;
    printf("taper le nom du joueur : ");
    scanf("%s", nom);

    afficherTableauEntete();
    for (int i=0;i<nbJoueurs;i++) {
        if (strcasecmp(equipe[i].nom, nom) == 0) {
            afficherTableauLigne(equipe[i]);
            trouve = 1;
        }
    }
    afficherTableauFin();

    if (!trouve) {
        printf("il n ya aucun joueur de non donne \n" );
    }
}
void rechercherParTrancheAge() {
    int ageMin, ageMax;
    int trouve = 0;

    printf("Taper l'âge minimum : ");
    scanf("%d", &ageMin);
    printf("Taper l'âge maximum : ");
    scanf("%d", &ageMax);

    if(ageMin > ageMax) {
        printf("La tranche d'âge est invalide (min > max).\n");
        return;
    }

    printf("\n=== Joueurs dans la tranche d'âge [%d - %d] ===\n", ageMin, ageMax);
    printf("===================================================================================================================\n");
    printf("| ID |      Nom      |    Prénom    | Maillot |    Poste    | Age | Buts |  Date insc.  |   Statut   |\n");
    printf("===================================================================================================================\n");

    for (int i = 0; i < nbJoueurs; i++) {
        if (equipe[i].age >= ageMin && equipe[i].age <= ageMax) {
            printf("| %-2d | %-12s | %-11s | %-7d | %-10s | %-3d | %-4d | %-12s | %-9s |\n",
                   equipe[i].id, equipe[i].nom, equipe[i].prenom, equipe[i].numeroMaillot,
                   equipe[i].poste, equipe[i].age, equipe[i].buts, equipe[i].dateInscription, equipe[i].statut);
            trouve = 1;
        }
    }
    if(!trouve) {
        printf("|                      Aucun joueur trouvé dans cette tranche d'âge                                       |\n");
    }
    printf("===================================================================================================================\n");
}


void menuRecherche() {
    int choix;
    do {
        printf("\n================================\n");
        printf("|          Menu Recherche      | \n");
        printf("================================\n");
        printf("|      1: rechercher par id    |\n");
        printf("|      2: rechercher par nom   |\n");
        printf("|3: rechercher par tranche age|\n");
        printf("|            0: quitter        |\n");
        printf("================================\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: rechercherId(); break;
            case 2: rechercherNom(); break;
            case 3: rechercherParTrancheAge(); break;
            case 0: retureMenu(); break;
            default: printf("choix invalide.\n"); break;
        }
    } while (choix != 0);
}

void modifierJoueur() {
    int id, trouve = 0;
    printf("taper id du joueur pour modifier : ");
    scanf("%d", &id);

    for (int i=0;i<nbJoueurs;i++) {
        if (equipe[i].id == id) {
            trouve = 1;
            int choix;
            do {
                printf("\n======================================");
                printf("\n|       modification de Joueur        |\n");
                printf("======================================\n");
                printf("|         1: modifier le poste       |\n");
                printf("|           2: modifier l age        |\n");
                printf("|    3: modifier le nombre de buts   |\n");
                printf("|              0: quitter            |\n");
                printf("======================================\n");
                printf("votre choix : ");
                scanf("%d", &choix);

                switch (choix) {
                    case 1: {
                        int choixP;
                        printf("l ancien poste de ce joueur est : %s\n",equipe[i].poste);
                        printf("taper le nouveau poste (1: gardien / 2: defenseur / 3: milieu / 4: attaquant) : ");
                        scanf("%d", &choixP);
                        switch (choixP) {
                            case 1: strcpy(equipe[i].poste, "gardien"); break;
                            case 2: strcpy(equipe[i].poste, "defenseur"); break;
                            case 3: strcpy(equipe[i].poste, "milieu"); break;
                            case 4: strcpy(equipe[i].poste, "attaquant"); break;
                            default: printf("modification annule\n");
                        }
                        break;
                    }
                    case 2:
                        printf("l ancien age de ce joueur : %d\n",equipe[i].age);
                        printf("taper le nouveau age : ");
                        scanf("%d", &equipe[i].age);
                        break;
                    case 3:
                        printf("l ancien nombre de buts de ce joueur : %d\n",equipe[i].buts);
                        printf("taper le nouveau nombre de buts : ");
                        scanf("%d", &equipe[i].buts);
                        break;
                    case 0: retureMenu(); break;
                    default: printf("choix invalide.\n");
                }
            } while (choix != 0);
            break;
        }
    }

    if (!trouve) {
        printf("il n ya aucun joueur avec id %d\n", id);
        retureMenu();
    }
}

void supprimerJoueur() {
    int id, trouve = 0;
    printf("taper id de joueur pour supprimer : ");
    scanf("%d", &id);

    for (int i=0;i<nbJoueurs;i++) {
        if (equipe[i].id == id) {
            trouve = 1;
            for (int j = i; j < nbJoueurs - 1; j++) {
                equipe[j] = equipe[j + 1];
            }
            nbJoueurs--;
            printf("joueur est supprime avec succes.\n");
            retureMenu();
            break;
        }
    }

    if (!trouve) {
        printf("il n ya aucun joueur avec id donne\n");
        retureMenu();
    }
}

void afficherNombreJoueurs() {
    printf(" nombre total de joueurs est : %d\n", nbJoueurs);
}

void afficherAgeMoyen() {
    if (nbJoueurs == 0) {
        printf(" il n ya aucun joueur.\n");
        return;
    }
    int somme = 0;
    for (int i=0;i<nbJoueurs;i++) {
        somme += equipe[i].age;
    }
    float moyenne = (float)somme / nbJoueurs;
    printf("age moyen des joueurs est : %.2f\n",moyenne);
}

void joueursPlusButs() {
    int nbrB, trouve = 0;
    printf("taper le nombre de buts : ");
    scanf("%d", &nbrB);

    afficherTableauEntete();
    for (int i=0;i<nbJoueurs;i++) {
        if (equipe[i].buts > nbrB) {
            afficherTableauLigne(equipe[i]);
            trouve = 1;
        }
    }
    afficherTableauFin();

    if (!trouve) printf("il n ya aucun joueur \n");
}

void joueurMaxBut() {
    if (nbJoueurs == 0) {
        printf("il n ya aucun joueur \n");
        return;
    }
    int maxButs=equipe[0].buts;
    int index=0;
    for (int i=1;i<nbJoueurs;i++) {
        if (equipe[i].buts > maxButs) {
            maxButs = equipe[i].buts;
            index = i;
        }
    }
    printf("meilleur buteur est : %s %s avec %d buts\n",
           equipe[index].nom, equipe[index].prenom, equipe[index].buts);
}

void joueurJeuneEtAge() {
    if (nbJoueurs == 0) {
        printf("il n ya aucun joueur\n");
        return;
    }
    int minAge = equipe[0].age, maxAge = equipe[0].age;
    int indexJeune = 0, indexVieux = 0;
    for (int i=1;i<nbJoueurs;i++) {
        if (equipe[i].age < minAge) {
            minAge = equipe[i].age;
            indexJeune = i;
        }
        if (equipe[i].age > maxAge) {
            maxAge = equipe[i].age;
            indexVieux = i;
        }
    }
    printf("le joueur le plus jeune : %s %s \n",
           equipe[indexJeune].nom, equipe[indexJeune].prenom);
    printf("le joueur le plus agee : %s %s \n",
           equipe[indexVieux].nom, equipe[indexVieux].prenom);
}

void menuStatistique() {
    int choix;
    do {
        printf("\n===========================================\n");
        printf("|            Menu Statistiques             |\n");
        printf("===========================================\n");
        printf("|       1: afficher nombre de joueurs      |\n");
        printf("|          2: afficher age moyen           |\n");
        printf("|     3: joueur avec plus de buts que n    |\n");
        printf("|        4: joueur avec max buts           |\n");
        printf("|  5: joueur le plus jeune et le plus agee |\n");
        printf("|                 0: quitter               |\n");
        printf("===========================================\n");
        printf("votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: afficherNombreJoueurs(); break;
            case 2: afficherAgeMoyen(); break;
            case 3: joueursPlusButs(); break;
            case 4: joueurMaxBut(); break;
            case 5: joueurJeuneEtAge(); break;
            case 0: retureMenu(); break;
            default: printf("choix invalide\n");
        }
    } while (choix != 0);
}

int main() {
    int choix;
    do {
        printf("\n=======================================\n");
        printf("|       Gestion d une equipe foot      |\n");
        printf("=======================================\n");
        printf("|          1: ajouter joueur           |\n");
        printf("|        2: afficher les joueurs       |\n");
        printf("|         3: rechercher joueur         |\n");
        printf("|         4: modifier joueur           |\n");
        printf("|         5: supprimer joueur          |\n");
        printf("|       6: statistiques equipe         |\n");
        printf("|    7: star de l equipe (buteur)      |\n");
        printf("|              0: quitter              |\n");
        printf("=======================================\n");

        printf("taper votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouteJoueur(); break;
            case 2: menuAffichage(); break;
            case 3: menuRecherche(); break;
            case 4: modifierJoueur(); break;
            case 5: supprimerJoueur(); break;
            case 6: menuStatistique(); break;
            case 7: joueurStar(); break;
            case 0: printf("quitter le programme ...\n"); break;
            default: printf("choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
