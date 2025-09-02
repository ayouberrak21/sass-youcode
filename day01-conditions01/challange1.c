#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nbr ;
    printf("taper le nombre :");
    scanf("%d",&nbr);
    if(nbr%2==0){
        printf("le nombre et pair");
    }else if (nbr%2==1){
            printf("le nombre est impair");
        }
    return 0;
}