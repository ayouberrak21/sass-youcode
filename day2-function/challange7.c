#include <stdio.h>

int fibo(int nbr) {
    if (nbr <= 0)
        return 0;
    else if (nbr == 1)
        return 1;
    else
        return fibo(nbr-1)+fibo(nbr-2);
}

int main() {
    int n;
    printf("taper un nombre : ");
    scanf("%d", &n);

    printf("la suite de Fibonaci est : %d\n", fibo(n));

    return 0;
}
