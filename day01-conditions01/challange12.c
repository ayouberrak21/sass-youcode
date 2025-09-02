#include <stdio.h>

int main() {
    int h1, m1, s1;
    int h2, m2, s2;

    printf("taper  1er instant hh:mm:ss : ");
    scanf("%d:%d:%d", &h1, &m1, &s1);

    printf("Entrez  2eme instant hh:mm:ss : ");
    scanf("%d:%d:%d", &h2, &m2, &s2);
    int t1 = h1*3600+m1*60+s1;
    int t2 = h2*3600+m2*60+s2;

    if (t1 < t2) {
        printf("Le premier instant vient avant le deuxième ;\n");
    } else if (t1 > t2) {
        printf("Le deuxième instant vient avant le premier ;\n");
    } else {
        printf("Il s'agit du même instant.\n");
    }

    return 0;
}
