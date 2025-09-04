#include <stdio.h>

struct rectangle {
    float lon;
    float lar;
};
int main() {
    struct rectangle r1;  
    float aire;
    printf("taper la longueur du rectangle : ");
    scanf("%f", &r1.lon);

    printf("taper la largeur du rectangle : ");
    scanf("%f", &r1.lar);
    aire = r1.lon * r1.lar;
    printf("L'aire du rectangle est : %.2f\n", aire);

    return 0;
}
