#include <stdio.h>

int mul(int a, int b) {
    return a * b;
}

int main() {
    int x ;
    int y ;
    printf("taper le nbr 1 : ");
    scanf("%d",&x);
    printf("taper le nbr 2 : ");
    scanf("%d",&y);
    int M;
    M=mul(x, y);
    printf("la somme est %d",M);

    return 0;
}
