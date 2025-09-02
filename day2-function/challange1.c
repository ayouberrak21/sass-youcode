#include <stdio.h>

int somme(int a, int b) {
    return a + b;
}

int main() {
    int x ;
    int y ;
    printf("taper le nbr 1 : ");
    scanf("%d",&x);
    printf("taper le nbr 2 : ");
    scanf("%d",&y);
    int s;
    s=somme(x, y);
    printf("la somme est %d",s);

    return 0;
}
