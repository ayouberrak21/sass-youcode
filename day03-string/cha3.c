#include <stdio.h>
#include <string.h>

int main(){
    char str1[20];
    char str2[20];
    printf("taper la 1er chaine : ");
    scanf("%s",&str1);
    printf("taper la 2eme chaine : ");
    scanf("%s",&str2);
    printf("%s",strcat(str1, str2));

    return 0;
    }

