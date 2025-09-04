#include <stdio.h>
#include <string.h>

int main() {
    char str1[20];
    char c;
    int i, l;
    int nb = 0;
    printf("taper la 1er chaine : ");
    scanf("%s", str1);
    printf("taper un caractere : ");
    scanf(" %c",&c);
    l=strlen(str1);
    for(i=0;i<l;i++) {
        if(str1[i]==c) {
            nb++;
        }
    }
    printf("le nombre de caractaire est : %d", nb);

    return 0;
}
