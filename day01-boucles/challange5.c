#include <stdio.h>

int main() {
    int B, EX;
    int R = 1;

    printf("taper la base : ");
    scanf("%d", &B);

    printf("taper lexposant : ");
    scanf("%d", &EX);

    for(int i = 0; i < EX; i++) {
        R *= B;
    }

    printf("le resulta est %d", R);

    return 0;
}
