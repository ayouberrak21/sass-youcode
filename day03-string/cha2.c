#include <stdio.h>
#include <string.h>

int main(){
    char str1[20];
    printf("taaper une chaine de caractaire : ");
    scanf("%s",str1);

    int i=0;
    while(str1[i] != '\0'){
        i++;
    }
    printf("la  longueur dune chaine de caracteres est : %d",i);
    return 0;
    }

