#include <stdio.h>

    int pairinpaire(int nbr){
        if (nbr%2==0){
            return 0;
        }
        else{
            return 1;
            }
        }
    int main(){
        int nbrr ;
        printf("taper lenombre :");
        scanf("%d",&nbrr);
        printf("%d",pairinpaire(nbrr));

        return 0;
    }


