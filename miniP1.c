#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CONTACTS 100

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
    printf("\n appuyez sur Entree pour revenir au menu...");
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
        printf("aucun contact a afficher \n");
        menu();
        return;
    }
    triContacts();
    printf("+----------------------+------------+----------------------+\n");
    printf("| nom                  | telephone  | email                |\n");
    printf("+----------------------+------------+----------------------+\n");
    for (int i=0; i<nombreContacts; i++) {
        printf("| %-20s | %-10s | %-20s |\n",
               contacts[i].nom,
               contacts[i].telephone,
               contacts[i].email);
    }
    printf("+----------------------+------------+----------------------+\n");
    menu();
}

int rechercherContact(char nom[]) {
    for (int i=0; i<nombreContacts; i++) {
        if (strcmp(contacts[i].nom, nom)==0)
            return i;
    }
    return -1;
}

void ajouterContact() {
    if (nombreContacts >= MAX_CONTACTS) {
        printf("impossible ajouter plus de contacts\n");
        menu();
        return;
    }
    printf("taper votre nom : ");
    scanf(" %[^\n]", contacts[nombreContacts].nom);

    do {
        printf("taper votre numero de telephone : ");
        scanf(" %[^\n]", contacts[nombreContacts].telephone);
        if (!validerTelephone(contacts[nombreContacts].telephone))
            printf("taper un numero convenable \n");
    } while (!validerTelephone(contacts[nombreContacts].telephone));

    printf("taper votre email : ");
    scanf(" %[^\n]", contacts[nombreContacts].email);

    nombreContacts++;
    printf("contact ajoute avec succes.\n");
    menu();
}

void rechercheContact1() {
    char nom[50];
    printf("taper le nom du contact : ");
    scanf(" %[^\n]", nom);
    int index = rechercherContact(nom);
    if (index == -1) {
        printf("contact introuvable.\n");
        menu();
        return;
    }
    printf("+----------------------+------------+----------------------+\n");
    printf("| nom                  | telephone  | email                |\n");
    printf("+----------------------+------------+----------------------+\n");
    printf("| %-20s | %-10s | %-20s |\n",
           contacts[index].nom,
           contacts[index].telephone,
           contacts[index].email);
    printf("+----------------------+------------+----------------------+\n");
    menu();
}

void modifierContact() {
    char nom[50];
    printf("taper le nom du contact : ");
    scanf(" %[^\n]", nom);
    int index = rechercherContact(nom);
    if (index==-1) {
        printf("contact introuvable.\n");
        menu();
        return;
    }

    printf("ancien telephone : %s\n", contacts[index].telephone);
    do {
        printf("taper le nouveau numero  : ");
        scanf(" %[^\n]", contacts[index].telephone);
        if (!validerTelephone(contacts[index].telephone))
            printf("taper un numero convenable .\n");
    } while (!validerTelephone(contacts[index].telephone));

    printf("ancien email : %s\n", contacts[index].email);
    printf("taper le nouveau email : ");
    scanf(" %[^\n]", contacts[index].email);

    printf("contact modifie avec succes.\n");
    menu();
}

void supprimerContact() {
    char nom[50];
    printf("taper le nom du contact : ");
    scanf(" %[^\n]", nom);
    int index = rechercherContact(nom);
    if (index==-1) {
        printf("contact introuvable.\n");
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
        printf("contact supprime avec succes.\n");
    } else {
        printf("suppression annulee.\n");
    }
    menu();
}

int main() {
    int choix;
    do {
        system("cls");
        printf("\n===================================\n");
        printf("|     MENU GESTION DES CONTACTS   |\n");
        printf("===================================\n");
        printf("|     1. ajouter un contact       |\n");
        printf("|    2. afficher les contacts     |\n");
        printf("|    3. rechercher un contact     |\n");
        printf("|     4. modifier un contact      |\n");
        printf("|    5. supprimer un contact      |\n");
        printf("|           6. quitter            |\n");
        printf("===================================\n");
        printf("taper votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouterContact(); break;
            case 2: afficherContact(); break;
            case 3: rechercheContact1(); break;
            case 4: modifierContact(); break;
            case 5: supprimerContact(); break;
            case 6: printf(" fin de programme \n"); break;
            default: printf("choix invalide\n"); menu();
        }
    } while (choix!=6);
    return 0;
}
