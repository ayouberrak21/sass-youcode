#include <stdio.h>
#include <string.h>

int rechercherElement(int tab[], int t, int num) {
    for (int i = 0; i < t; i++) {
        if (tab[i] == num) {
            return i;
        }
    }
    return -1;
}

int main(){
    int taille = 8;
    int num[]={1,2,3,4,5,6,7,8,9};
    int v;
    printf("taper la valeur : ");
    scanf("%d",&v);
    int index = rechercherElement(num,taille,v);
    if(index==-1){
        printf("il n y a pas cette valeur \n");
    }
    printf("il ya cette valeur ");
    return 0;
}
