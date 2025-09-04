#include <stdio.h>
#include <string.h>

int main() {
    char str1[20];
    printf("taper la 1er chaine : ");
    gets(str1);
    int i,l;
    l=strlen(str1);
    while (i<l){
        if(str1[i]!=' '){
            printf("%c",str1[i]);
        }
        i++;
    }
    return 0;
}
