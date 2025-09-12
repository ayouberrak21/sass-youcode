#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// definition des couleur
#define RESET   "\033[0m"
#define JAUNE   "\033[33m"
#define BLEU    "\033[34m"
#define VERT    "\033[32m"
#define ROUGE   "\033[31m"

#define MAX 30
// la structure principale
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

// implementation de structure
int nbJoueurs = 15;
int nextId = 16;
Joueur equipe[MAX] = {
        {1, "courtois", "thibaut", 1, "gardien", 32, 0, "01/01/2020", "titulaire"},
        {2, "lunin", "andre", 1, "gardien", 32, 0, "01/01/2020", "remplacant"},
        {3, "hakimi", "achraf", 2, "defenseur", 26, 10, "05/03/2019", "titulaire"},
        {4, "vandijik ", "virgil", 4, "defenseur", 34, 5, "10/06/2018", "titulaire"},
        {5, "huijsen", "dean", 23, "defenseur", 29, 3, "12/07/2019", "titulaire"},
        {6, "carreras", "alvaro", 3, "defenseur", 28, 7, "20/08/2020", "titulaire"},
        {7, "mendes", "nuno", 12, "defenseur", 22, 3, "20/08/2020", "remplacant"},
        {8, "rodri", "hernandez", 21, "milieu", 28, 4, "02/09/2017", "titulaire"},
        {9, "valverde", "federico", 8, "milieu", 24, 6, "15/10/2021", "titulaire"},
        {10, "guler", "arda", 15, "milieu", 27, 9, "11/11/2018", "titulaire"},
        {11, "belligham", "jude", 5, "milieu", 27, 9, "11/11/2018", "titulaire"},
        {12, "pedri", "hernandez", 10, "milieu", 27, 9, "11/11/2018", "remplacant"},
        {13, "junior", "vini", 7, "attaquant", 30, 20, "01/01/2016", "titulaire"},
        {14, "mbappe", "kilian", 9, "attaquant", 27, 25, "13/04/2018", "titulaire"},
        {15, "yamal", "lamine", 11, "attaquant", 29, 15, "07/05/2016", "remplacant"}
    };

// la fomction qui evite le doublement de numero de maillot
int ValidNumMaillot(int numero) {
    for(int i =0;i<nbJoueurs; i++){
        if(equipe[i].numeroMaillot == numero)
            return 1;
    }
    return 0;
}
// la fomction pour returner au menu et effacer le cmd
void retureMenu() {
    printf(JAUNE"\n appuyez sur entree pour revenir au menu "RESET);
    getchar();
    getchar();
    system("cls");
}

int validerDate(char date[20]) {
    int jour,mois,annee;
// condition de long de la date et les / /
    if(strlen(date)!=10)
        return 0;
    if(date[2]!='/' || date[5]!='/')
        return 0;
// verification si est nombre
    for(int i=0; i<10; i++) {
        if(i==2 || i==5)
            continue;
        if(!isdigit(date[i]))
            return 0;
    }
// lire et valider la date
    sscanf(date, "%2d/%2d/%4d",&jour,&mois,&annee);

    if(jour<1 || jour>30)
        return 0;
    if(mois<1 || mois>12)
        return 0;
    if(annee<1970 || annee>2025)
        return 0;

    return 1;
}
// pour voir est ce q'il ya un gardian titulaire
int gardienTitulaireExiste() {
    for (int i = 0; i < nbJoueurs; i++) {
        if (strcmp(equipe[i].poste, "gardien") == 0 && strcmp(equipe[i].statut, "titulaire") == 0) {
            return 1;
        }
    }
    return 0;
}
// pour compter les joueurs titulaire
int compterTitulaires() {
    int count = 0;
    for (int i = 0; i < nbJoueurs; i++) {
        if (strcmp(equipe[i].statut, "titulaire") == 0) {
            count++;
        }
    }
    return count;
}


void afficherTableauEntete(){
    printf(JAUNE"===================================================================================================\n"RESET);
    printf(JAUNE"|"RESET BLEU" ID"RESET JAUNE" |"RESET BLEU"      Nom"RESET JAUNE"     |"RESET BLEU"   Prénom"RESET JAUNE"    |"RESET BLEU" Maillot"RESET JAUNE" |"RESET BLEU"   Poste"RESET JAUNE"    |"RESET BLEU" Age"RESET JAUNE" |"RESET BLEU" Buts "RESET JAUNE"|"RESET BLEU"  Date insc. "RESET JAUNE" | "RESET BLEU"  Statut  "RESET JAUNE" |\n"RESET);
    printf(JAUNE"===================================================================================================\n"RESET);
}

void afficherTableauLigne(Joueur j) {
           printf(JAUNE"|"RESET" %-2d "JAUNE"|"RESET" %-12s "JAUNE"|"RESET" %-11s "JAUNE"|"RESET" %-7d "JAUNE"|"RESET" %-10s "JAUNE"|"RESET" %-3d "JAUNE"|"RESET" %-4d "JAUNE"|"RESET" %-12s "JAUNE"|"RESET" %-10s "JAUNE"|\n"RESET,
           j.id, j.nom, j.prenom, j.numeroMaillot, j.poste, j.age, j.buts, j.dateInscription, j.statut);
}

void afficherTableauFin() {
    printf(JAUNE"===================================================================================================\n"RESET);
}
// ajout de chanp de joueur
void ajouterChanpsJoueur(){
    int choixP;
// si il est plein
    if(nbJoueurs>=MAX){
        printf(ROUGE"la liste des joueurs est plaine "RESET);
        retureMenu();
    }
// incrementation de id
    Joueur j;
    j.id=nextId++;
// taper les information avec les validation des info
    printf("taper le nom : ");
    scanf("%s", j.nom);

    printf("taper le prenom : ");
    scanf("%s", j.prenom);

    int numero;
    do {
        printf("taper le numero de maillot : ");
        scanf("%d", &numero);
        if(numero<=0 || numero>=100){
            printf(ROUGE"le numero est incorect \n"RESET);
        }else if(ValidNumMaillot(numero)) {
            printf(ROUGE"ce numero a un autre joueur \n"RESET);
        }
    } while(ValidNumMaillot(numero) || numero<=0 || numero>=100);
    j.numeroMaillot = numero;

    printf(JAUNE"taper le poste ( 1: gardien / 2: defenseur / 3: milieu / 4: attaquant ) \n "RESET);
    printf("taper ton choix : ");
    scanf("%d",&choixP);
    switch(choixP) {
        case 1:
            strcpy(j.poste,"gardien");
            break;
        case 2:
            strcpy(j.poste,"defenseur");
            break;
        case 3:
            strcpy(j.poste,"milieu");
            break;
        case 4:
            strcpy(j.poste,"attaquant");
            break;
        default:
            strcpy(j.poste,"inconnu");
            printf(ROUGE"le poste est inconue\n"RESET);
    }

    do{
        printf("taper votre age : ");
        scanf("%d", &j.age);
        if(j.age<=18 || j.age>=45){
            printf(ROUGE"l age de joueurs n'est pas convenable \n"RESET);
        }
    }while(j.age<=18 || j.age>=45);

    do{
        printf("taper le nombre de buts de joueur : ");
        scanf("%d", &j.buts);
        if(j.buts<0){
            printf(ROUGE"nombre de buts invalid "RESET);
        }
    }while(j.buts<0);

    do {
        printf("taper date d inscription (JJ/MM/AAAA) : ");
        scanf("%s", j.dateInscription);
        if(!validerDate(j.dateInscription)) {
            printf(ROUGE" date invalide \n"RESET);
        }
    } while(!validerDate(j.dateInscription));

    int nbTitulaires = compterTitulaires();
    // si il y a 11 titutaire
    if (nbTitulaires >= 11) {
        strcpy(j.statut, "remplacant");
        printf(JAUNE" il y a 11 joueurs titulaires , ce joueur sera remplacant\n"RESET);
    } else {
        // si ila un gardian tidulaire
        if (strcmp(j.poste,"gardien") == 0) {
            if (gardienTitulaireExiste()) {
                strcpy(j.statut,"remplacant");
                printf(JAUNE"il ya un gardien titulaire , ce gardien sera remplacant\n"RESET);
            } else {
        // si il n ya pas un gardian tidulaire
                strcpy(j.statut,"titulaire");
                printf(VERT"ce gardien est defini comme titulaire.\n"RESET);
            }
        } else {
            // taper le status manuelemet
            int choixS;
            printf(JAUNE"Statut (1: titulaire / 2: remplacant) "RESET);
            printf("taper ton choix : ");
            scanf("%d",&choixS);
            switch(choixS){
                case 1:
                    strcpy(j.statut,"titulaire");
                    break;
                case 2:
                    strcpy(j.statut,"remplacant");
                    break;
                default:
                    strcpy(j.statut,"remplacant");
                    printf(JAUNE"statut invalide le joueur ajout dans remplacant\n"RESET); break;
            }
        }
    }
// si tous les information sont valide il s ajoute
    equipe[nbJoueurs++] = j;
    printf(VERT" joueur ajoute avec succes.\n"RESET);
    retureMenu();
}
// le menu de ajoute simple ou multiple
void ajouteJoueur(){
    int choix;
    do {
        printf(JAUNE"\n=============================\n"RESET);
        printf(JAUNE"|"RESET BLEU"       Menu d ajout        "RESET JAUNE"|"RESET);
        printf(JAUNE"\n=============================\n"RESET);
        printf(JAUNE"|"RESET"      1: choix simple      "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"      2: choix multiple    "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"         0: quitter        "JAUNE"|\n"RESET);
        printf(JAUNE"=============================\n"RESET);
        printf("taper votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterChanpsJoueur();
                break;
            case 2: {
                int choix1;
// menu de lajout multiple
                do {
                    printf(JAUNE"\n==========================\n"RESET);
                    printf(JAUNE"|"RESET BLEU"      Menu multiple     "RESET JAUNE"|\n"RESET);
                    printf(JAUNE"==========================\n"RESET);
                    printf(JAUNE"|"RESET"       1: continuer     "JAUNE"|\n"RESET);
                    printf(JAUNE"|"RESET"       0: quitter       "JAUNE"|\n"RESET);
                    printf(JAUNE"==========================\n"RESET);
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
                printf(ROUGE"choix invalide\n"RESET);
        }
    } while (choix != 0);

}
// function qui tri par lordre alphabetique
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
// function qui tri de moins age au plus
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
// tri par poste avec donner un menu
void triPoste() {
    int choix;
    char posteSelect[20];
    int trouve = 0;

    printf(JAUNE"\n==="RESET BLEU" affichage par poste "RESET JAUNE"===\n"RESET);
    printf(JAUNE"1: gardien\n");
    printf("2: defenseur\n");
    printf("3: milieu\n");
    printf("4: attaquant\n"RESET);
    printf("votre choix : ");
    scanf("%d", &choix);

    switch (choix){
        case 1:
            strcpy(posteSelect, "gardien");
            break;
        case 2:
            strcpy(posteSelect, "defenseur");
            break;
        case 3:
            strcpy(posteSelect, "milieu");
            break;
        case 4:
            strcpy(posteSelect, "attaquant");
            break;
        default:
            printf(ROUGE"choix invalid .\n"RESET);
            return;
    }
// lafichage
    afficherTableauEntete();
    for (int i = 0; i < nbJoueurs; i++) {
        if (strcmp(equipe[i].poste, posteSelect) == 0) {
            afficherTableauLigne(equipe[i]);
            trouve = 1;
        }
    }
    afficherTableauFin();

    if (!trouve) {
        printf(ROUGE"il n y a auncun joueur \n"RESET);
    }
}
// function pour ajoute un seul joueur
void afficherUnJoueur(Joueur j) {
   afficherTableauEntete();
    afficherTableauLigne(j);
    afficherTableauFin();
    retureMenu();
}
// la fontion de joueur qui est le plus marquant
void joueurStar() {
    if (nbJoueurs == 0) {
        printf(ROUGE"\n aucun joueur enregistre \n"RESET);
        return;
    }

    int indexMax = 0;
    for (int i = 1; i < nbJoueurs; i++) {
        if (equipe[i].buts > equipe[indexMax].buts) {
            indexMax = i;
        }
    }
// laffichage
    printf(VERT"\n Star de lequipe  \n"RESET);
    afficherUnJoueur(equipe[indexMax]);
}
// laffichge deplusieurs joueur
void afficherJoueurs() {
    if (nbJoueurs == 0) {
        printf(ROUGE"\nil n ya aucun joueur \n"RESET);
        retureMenu();
        return;
    }
    afficherTableauEntete();
    for (int i = 0; i < nbJoueurs; i++) {
        afficherTableauLigne(equipe[i]);
    }
    afficherTableauFin();
}
// lw menu principale de laffichage
void menuAffichage() {
    int choix;
    do {
        printf(JAUNE"\n========================================================\n"RESET);
        printf(JAUNE"|"RESET BLEU"                    Menu d affichage                  "RESET JAUNE"|\n"RESET);
        printf(JAUNE"========================================================\n");
        printf(JAUNE"|"RESET"  1: afficher les joueur par ordre alphabetique (Nom) "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"        2: afficher les joueurs par le moins agee     "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"           3: afficher les joueurs par poste          "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"            4: afficher tous les joueurs              "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"                     0: Quitter                       "JAUNE"|\n"RESET);
        printf(JAUNE"========================================================\n"RESET);

        printf("Votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                triNom();
                afficherJoueurs();
                break;
            case 2:
                triAge();
                afficherJoueurs();
                break;
            case 3:
                triPoste();
                break;
            case 4:
                afficherJoueurs();
                break;
            case 0:
                retureMenu();
                break;
            default:
                printf(ROUGE"choix invalide\n"RESET);
                break;
        }
    } while (choix != 0);

}
// recherche par id
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
        printf(ROUGE"il n ya aucun joueur avec id %d.\n"RESET, id);
    }
}
// recherche par le non
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
        printf(ROUGE"il n ya aucun joueur de non donne \n" RESET);
    }
}
// recherche par tranche dage
void rechercherParTrancheAge() {
    int ageMin, ageMax;
    int trouve = 0;

    printf("taper lage min : ");
    scanf("%d", &ageMin);
    printf("taper lage max : ");
    scanf("%d", &ageMax);
// si min>max
    if(ageMin > ageMax) {
        printf(ROUGE"la tranche dage est invalide \n"RESET);
        return;
    }

    printf(JAUNE"\n=== les joueurs dans la tranche dage entre ===\n"RESET);
    afficherTableauEntete();
    for (int i = 0; i < nbJoueurs; i++) {
        if (equipe[i].age >= ageMin && equipe[i].age <= ageMax) {
            afficherTableauLigne(equipe[i]);
            trouve = 1;
        }
    } //si il n ya aucun joueurs dans la tranche
    if(!trouve) {
        printf(ROUGE"|                      aucun joueur trouve dans cette tranche dage                                     |\n"RESET);
    }
    afficherTableauFin();
}

// rechecher par le status
void rechercherParStatut() {
    int choix;
    char statutRecherche[15];
    int trouve = 0;

    printf(JAUNE"\n==="RESET BLEU " recherche par statut " RESET JAUNE"===\n");
    printf("1: titulaire\n");
    printf("2: remplaçant\n"RESET);
    printf("Votre choix : ");
    scanf("%d", &choix);

    if (choix == 1) {
        strcpy(statutRecherche, "titulaire");
    } else if (choix == 2) {
        strcpy(statutRecherche, "remplacant");
    } else {
        printf(ROUGE"choix invalide\n"RESET);
        return;
    }

    afficherTableauEntete();
    for (int i = 0; i < nbJoueurs; i++) {
        if (strcasecmp(equipe[i].statut, statutRecherche) == 0) {
            afficherTableauLigne(equipe[i]);
            trouve = 1;
        }
    }
    afficherTableauFin();

    if (!trouve) {
        printf(ROUGE"aucun joueur trouve avec le statut entre \n"RESET);
    }
}


//le menu principale de recherche
void menuRecherche() {
    int choix;
    do {
        printf(JAUNE"\n================================\n"RESET);
        printf(JAUNE"|"RESET BLEU"          menu recherche      "RESET JAUNE"| \n"RESET);
        printf(JAUNE"================================\n"RESET);
        printf(JAUNE"|"RESET"      1: rechercher par id    "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"      2: rechercher par nom   "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"3: rechercher par tranche age "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"   4: rechercher par statut   "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"            0: quitter        "JAUNE"|\n"RESET);
        printf(JAUNE"================================\n"RESET);
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                rechercherId();
                break;
            case 2:
                rechercherNom();
                break;
            case 3:
                rechercherParTrancheAge();
                break;
            case 4:
                rechercherParStatut();
            case 0:
                retureMenu();
                break;
            default:
                printf(ROUGE"choix invalide.\n"RESET);
                break;
        }
    } while (choix != 0);
}
// le menu de modification et les function
void modifierJoueur() {
    int id, trouve = 0;
    printf("taper id du joueur pour modifier : ");
    scanf("%d", &id);

    for (int i=0;i<nbJoueurs;i++) {
        if (equipe[i].id == id) {
            trouve = 1;
            int choix;
            do {
                printf(JAUNE"\n======================================"RESET);
                printf(JAUNE"\n|"RESET BLEU"       modification de joueur       "RESET JAUNE"|\n"RESET);
                printf(JAUNE"======================================\n"RESET);
                printf(JAUNE"|"RESET"         1: modifier le poste       "JAUNE"|\n"RESET);
                printf(JAUNE"|"RESET"           2: modifier l age        "JAUNE"|\n"RESET);
                printf(JAUNE"|"RESET"    3: modifier le nombre de buts   "JAUNE"|\n"RESET);
                printf(JAUNE"|"RESET"   4: modifier le status de joueur  "JAUNE"|\n"RESET);
                printf(JAUNE"|"RESET"              0: quitter            "JAUNE"|\n"RESET);
                printf(JAUNE"======================================\n"RESET);
                printf("votre choix : ");
                scanf("%d", &choix);

                switch (choix) {
                    case 1: {
                        // modification de poste
                        int choixP;
                        printf(JAUNE"l ancien poste de ce joueur est : %s\n"RESET,equipe[i].poste);
                        printf("taper le nouveau poste (1: gardien / 2: defenseur / 3: milieu / 4: attaquant) : ");
                        scanf("%d", &choixP);
                        switch (choixP) {
                            case 1:
                                strcpy(equipe[i].poste, "gardien");
                                printf(VERT"la modification est effectuee"RESET);
                                 break;
                            case 2:
                                strcpy(equipe[i].poste, "defenseur");
                                printf(VERT"la modification est effectuee"RESET);
                                break;
                            case 3:
                                strcpy(equipe[i].poste, "milieu");
                                printf(VERT"la modification est effectuee"RESET);
                                break;
                            case 4:
                                strcpy(equipe[i].poste, "attaquant");
                                printf(VERT"la modification est effectuee"RESET);
                                break;
                            default:
                                printf(ROUGE"modification annule\n"RESET);
                        }
                        break;
                    }
                    case 2:
                        // modification de age
                        printf(JAUNE"l ancien age de ce joueur : %d\n"RESET,equipe[i].age);
                        printf("taper le nouveau age : ");
                        scanf("%d", &equipe[i].age);
                        printf(VERT"la modification est effectuee"RESET);
                        break;
                    case 3:
                        // modification de nbr but
                        printf(JAUNE"l ancien nombre de buts de ce joueur : %d\n"RESET,equipe[i].buts);
                        printf("taper le nouveau nombre de buts : ");
                        scanf("%d", &equipe[i].buts);
                        printf(VERT"la modification est effectuee"RESET);
                        break;
                    case 4:
                        if (strcmp(equipe[i].statut,"remplacant") == 0) {
                            // de remplaçant vers titulaire
                            if (compterTitulaires() >= 11) {
                            // si il ya les 11 titulaire
                                printf(ROUGE" impossible : il y a les 11 titulaires\n"RESET);
                            } else if (strcmp(equipe[i].poste,"gardien") == 0 && gardienTitulaireExiste()) {
                                printf(ROUGE"impossible : un gardien titulaire existe\n"RESET);
                            } else {
                                strcpy(equipe[i].statut,"titulaire");
                                printf(VERT" le joueur est maintenant titulaire\n"RESET);
                            }
                        } else {
                            // de titulaire vers remplaçant
                            strcpy(equipe[i].statut,"remplacant");
                            printf(VERT"le joueur est maintenant remplacant\n"RESET);
                        }
                        break;
                    case 0: retureMenu(); break;
                    default: printf(ROUGE"choix invalide.\n"RESET);
                }
            } while (choix != 0);
            break;
        }
    }
// si il n ya aucun joueur avec id donne
    if (!trouve) {
        printf(ROUGE"il n ya aucun joueur avec id %d\n"RESET, id);
        retureMenu();
    }
}
// supprimer joueur
void supprimerJoueur() {
    int id, trouve = 0;
    printf("taper id de joueur pour supprimer : ");
    scanf("%d", &id);
    for (int i = 0; i < nbJoueurs; i++) {
        if (equipe[i].id == id) {
            trouve = 1;
            // comfirmation de suppressien
            printf(JAUNE"\n voulez vous supprimer le joueur ? \n"RESET);
            printf(" 1: oui , supprimer\n 0: non , annuler\n Votre choix : ");

            int confirm;
            scanf("%d", &confirm);

            if (confirm == 1) {
                for (int j = i; j < nbJoueurs - 1; j++) {
                    equipe[j] = equipe[j + 1];
                }
                nbJoueurs--;
                printf(VERT"\n le joueur supprime avec succes.\n"RESET);
            } else {
                printf(ROUGE"\n suppression annulee.\n"RESET);
            }
            retureMenu();
            return;
        }
    }

    if (!trouve) {
        printf(ROUGE"il n ya aucun joueur avec id donne\n"RESET);
        retureMenu();
    }
}
// satatistique de nbr joueur
void afficherNombreJoueurs() {
    printf(" nombre total de joueurs est : %d\n", nbJoueurs);
}
// satatistique de age moyen
void afficherAgeMoyen() {
    if (nbJoueurs == 0) {
        printf(ROUGE" il n ya aucun joueur.\n"RESET);
        return;
    }
    float somme = 0;
    for (int i=0;i<nbJoueurs;i++) {
        somme += equipe[i].age;
    }
    float moyenne = somme / nbJoueurs;
    printf("age moyen des joueurs est : %.2f\n",moyenne);
}
// satatistique de joueur qui marque plus de buts
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

    if (!trouve) printf(ROUGE"il n ya aucun joueur \n"RESET);
}
// satatistique de joueur qui marque plus de but
void joueurMaxBut() {
    if (nbJoueurs == 0) {
        printf(ROUGE"il n ya aucun joueur \n"RESET);
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
    printf(VERT"le meilleur buteur est : %s %s a marque %d buts\n"RESET,
           equipe[index].nom, equipe[index].prenom, equipe[index].buts);
}
// satatistique du plus jeune et le plus agge
void joueurJeuneEtAge() {
    if (nbJoueurs == 0) {
        printf(ROUGE"il n ya aucun joueur\n"RESET);
        return;
    }
    int minAge = equipe[0].age, maxAge = equipe[0].age;
    int indexJeune = 0, indexVieux = 0;
    for (int i=1;i<nbJoueurs;i++) {
        //pour le plus jeune
        if (equipe[i].age < minAge) {
            minAge = equipe[i].age;
            indexJeune = i;
        }
        // le plus agee
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
// le menu principale des satatistique
void menuStatistique() {
    int choix;
    do {
        printf(JAUNE"\n============================================\n"RESET);
        printf(JAUNE"|"RESET BLEU"             nenu statistiques            "RESET JAUNE"|\n"RESET);
        printf(JAUNE"============================================\n"RESET);
        printf(JAUNE"|"RESET"       1: afficher nombre de joueurs      "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"          2: afficher age moyen           "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"     3: joueur avec plus de buts que n    "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"        4: joueur avec max buts           "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"  5: joueur le plus jeune et le plus agee "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"                 0: quitter               "JAUNE"|\n"RESET);
        printf(JAUNE"============================================\n"RESET);
        printf("votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficherNombreJoueurs();
                break;
            case 2:
                afficherAgeMoyen();
                break;
            case 3:
                joueursPlusButs();
                break;
            case 4:
                joueurMaxBut();
                break;
            case 5:
                joueurJeuneEtAge();
                break;
            case 0:
                retureMenu();
                break;
            default:
                printf(ROUGE"choix invalide\n"RESET);
        }
    } while (choix != 0);
}
// le menu dans la fonction prinsipale
int main() {
    int choix;
    do {
        printf(JAUNE"\n========================================\n"RESET);
        printf(JAUNE"|"RESET BLEU"       GESTION D UNE EQUIPE FOOT      "RESET JAUNE"|\n" RESET);
        printf(JAUNE"========================================\n"RESET);
        printf(JAUNE"|"RESET"          1: ajouter joueur           "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"        2: afficher les joueurs       "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"         3: rechercher joueur         "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"         4: modifier joueur           "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"         5: supprimer joueur          "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"       6: statistiques equipe         "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"        7: star de l equipe           "JAUNE"|\n"RESET);
        printf(JAUNE"|"RESET"              0: quitter              "JAUNE"|\n"RESET);
        printf(JAUNE"========================================\n"RESET);

        printf("taper votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouteJoueur();
                break;
            case 2:
                menuAffichage();
                break;
            case 3:
                menuRecherche();
                break;
            case 4:
                modifierJoueur();
                break;
            case 5:
                supprimerJoueur();
                break;
            case 6:
                menuStatistique();
                break;
            case 7:
                joueurStar();
                break;
            case 0:
                printf(VERT"quitter le programme \n"RESET);
                break;
            default:
                printf(ROUGE"choix invalide.\n"RESET);
        }
    } while (choix != 0);

    return 0;
}
