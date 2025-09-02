#include <stdio.h>

int min(int a, int b) {
    if (a < b) {
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
    printf("le minimom est : %d\n", min(x, y));
    return 0;
}
