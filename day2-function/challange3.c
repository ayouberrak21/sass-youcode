#include <stdio.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int main() {
    int x, y;
    printf("taper  1er nbr : ");
    scanf("%d", &x);
    printf("taper  2eme nbr : ");
    scanf("%d", &y);
    printf("le maximum est : %d\n", max(x, y));
    return 0;
}
