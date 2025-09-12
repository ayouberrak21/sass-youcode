#include <stdio.h>

void echanger(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void trie(int t[],int taille){
    for (int i =0;i<taille-1;i++){
        int min=i;
        for (int j =i+1;j<taille;j++){
            if (t[j]<t[min]){
                min = j;
            }
        }
        if(min != i){
            echanger(&t[i],&t[min]);
        }

}
}
int main(){
    int t;
    printf("taper la taille de tabeau : ");
    scanf("%d",&t);
    int tab[t];
    for(int i=0;i<t;i++){
        printf("t[%d] = ",i);
        scanf("%d",&tab[i]);
    }
    trie(tab,t);
    for (int i = 0; i < t; i++) {
        printf("%d ", tab[i]);
    }
}