#include <stdio.h>
#include <math.h>


int main() {
    int nbr1;
    int nbr2;
    int S;
    int T;

    printf("taper le nombre 1 : ");
    scanf("%d",&nbr1);
    printf("taper le nombre 2 : ");
    scanf("%d",&nbr2);
    S=nbr1+nbr2;

    if(nbr1!=nbr2){
            printf("%d",S);
    }else {
        T=S*S*S;
        printf("%d",T);
    }

return 0;
}
