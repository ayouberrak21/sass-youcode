#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CONTACTS 100

// Codes ANSI pour les couleurs
#define RESET   "\033[0m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define ORANGE  "\033[0;33m"
#define BLUE    "\033[1;34m"

struct contact {
    char nom[50];
    char telephone[20];
    char email[50];
};

struct contact contacts[MAX_CONTACTS];
int nombreContacts = 0;

int validerTelephone(char tel[]) {
    int len = strlen(tel);
    if (len != 10) return 0;
    if (!((tel[0]=='0' && tel[1]=='6') || (tel[0]=='0' && tel[1]=='7')))
        return 0;
    for (int i=0; i<len; i++)
        if (!isdigit(tel[i])) return 0;
    return 1;
}

void menu() {
    printf("\n" ORANGE "appuyez sur entree pour revenir au menu..." RESET);
    while(getchar() != '\n');
    getchar();
    system("cls");
}

void triContacts() {
    struct contact temp;
    for (int i = 0; i < nombreContacts - 1; i++) {
        for (int j = i + 1; j < nombreContacts; j++) {
            if (strcmp(contacts[i].nom, contacts[j].nom) > 0) {
                temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
}

void afficherContact() {
    if (nombreContacts == 0) {
        printf(RED "aucun contact  \n" RESET);
        menu();
        return;
    }
    triContacts();
    printf(ORANGE "+----------------------+------------+----------------------+\n" RESET);
    printf(ORANGE "|" RESET BLUE " nom                  "ORANGE"|"RESET BLUE " telephone  "ORANGE"|"RESET BLUE" email                " ORANGE "|\n" RESET);
    printf(ORANGE "+----------------------+------------+----------------------+\n" RESET);
    for (int i=0; i<nombreContacts; i++) {
    printf(ORANGE "|" RESET " %-20s " ORANGE "|" RESET " %-10s " ORANGE "|" RESET " %-20s " ORANGE "|\n" RESET,
               contacts[i].nom,
               contacts[i].telephone,
               contacts[i].email);
    }
    printf(ORANGE "+----------------------+------------+----------------------+\n" RESET);
    menu();
}

int rechercherContact(char nom[]) {
    for (int i=0; i<nombreContacts; i++) {
        if (strcmp(contacts[i].nom, nom)==0)
            return i;
    }
    return -1;
}

void rechercheContact1() {
    char nom[50];
    printf("taper le nom du contact : ");
    scanf(" %[^\n]", nom);
    int index = rechercherContact(nom);
    if (index == -1) {
        printf(RED "contact introuvable.\n" RESET);
        menu();
        return;
    }
    printf(ORANGE "+----------------------+------------+----------------------+\n" RESET);
    printf(ORANGE "|" RESET BLUE " nom                  "ORANGE"|"RESET BLUE " telephone  "ORANGE"|"RESET BLUE" email                " ORANGE "|\n" RESET);
    printf(ORANGE "+----------------------+------------+----------------------+\n" RESET);
    printf(ORANGE "|" RESET " %-20s " ORANGE "|" RESET " %-10s " ORANGE "|" RESET " %-20s " ORANGE "|\n" RESET,
           contacts[index].nom,
           contacts[index].telephone,
           contacts[index].email);
    printf(ORANGE "+----------------------+------------+----------------------+\n" RESET);
    menu();
}

void ajouterContact() {
    if (nombreContacts >= MAX_CONTACTS) {
        printf(RED "impossible ajouter plus de contacts\n" RESET);
        menu();
        return;
    }
    printf("taper votre nom : ");
    scanf(" %[^\n]", contacts[nombreContacts].nom);

    do {
        printf("taper votre numero de telephone : ");
        scanf(" %[^\n]", contacts[nombreContacts].telephone);
        if (!validerTelephone(contacts[nombreContacts].telephone))
            printf(RED "taper un numero convenable \n" RESET);
    } while (!validerTelephone(contacts[nombreContacts].telephone));

    printf("taper votre email : ");
    scanf(" %[^\n]", contacts[nombreContacts].email);

    nombreContacts++;
    printf(GREEN "contact ajoute avec succes.\n" RESET);
    menu();
}

void modifierContact() {
    char nom[50];
    printf("taper le nom du contact : ");
    scanf(" %[^\n]", nom);
    int index = rechercherContact(nom);
    if (index==-1) {
        printf(RED "contact introuvable.\n" RESET);
        menu();
        return;
    }

    printf("ancien telephone : %s\n", contacts[index].telephone);
    do {
        printf("taper le nouveau numero  : ");
        scanf(" %[^\n]", contacts[index].telephone);
        if (!validerTelephone(contacts[index].telephone))
            printf(RED "taper un numero convenable .\n" RESET);
    } while (!validerTelephone(contacts[index].telephone));

    printf("ancien email : %s\n", contacts[index].email);
    printf("taper le nouveau email : ");
    scanf(" %[^\n]", contacts[index].email);

    printf(GREEN "contact modifie avec succes.\n" RESET);
    menu();
}

void supprimerContact() {
    char nom[50];
    printf("taper le nom du contact : ");
    scanf(" %[^\n]", nom);
    int index = rechercherContact(nom);
    if (index==-1) {
        printf(RED "contact introuvable.\n" RESET);
        menu();
        return;
    }
    char confirmation;
    printf("confirmez la suppression du contact '%s' (O/N) : ", contacts[index].nom);
    scanf(" %c", &confirmation);
    if (confirmation=='O' || confirmation=='o') {
        for (int i=index; i<nombreContacts-1; i++) {
            contacts[i] = contacts[i+1];
        }
        nombreContacts--;
        printf(GREEN "contact supprime avec succes.\n" RESET);
    } else {
        printf(ORANGE "suppression annulee.\n" RESET);
    }
    menu();
}

int main() {
    int choix;
    do {
        system("cls");
        printf("\n" ORANGE "===================================\n" RESET);
        printf(ORANGE "|" RESET BLUE "     MENU GESTION DES CONTACTS   " RESET ORANGE "|\n" RESET);
        printf(ORANGE "===================================\n" RESET);
        printf(ORANGE "|" RESET "     1. ajouter un contact       " ORANGE "|\n" RESET);
        printf(ORANGE "|" RESET "    2. afficher les contacts     " ORANGE "|\n" RESET);
        printf(ORANGE "|" RESET "    3. rechercher un contact     " ORANGE "|\n" RESET);
        printf(ORANGE "|" RESET "     4. modifier un contact      " ORANGE "|\n" RESET);
        printf(ORANGE "|" RESET "    5. supprimer un contact      " ORANGE "|\n" RESET);
        printf(ORANGE "|" RESET "           6. quitter            " ORANGE "|\n" RESET);
        printf(ORANGE "===================================\n" RESET);
        printf("taper votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouterContact(); break;
            case 2: afficherContact(); break;
            case 3: rechercheContact1(); break;
            case 4: modifierContact(); break;
            case 5: supprimerContact(); break;
            case 6: printf(GREEN " fin de programme \n" RESET); break;
            default: printf(RED "choix invalide\n" RESET); menu();
        }
    } while (choix!=6);
    return 0;
}
