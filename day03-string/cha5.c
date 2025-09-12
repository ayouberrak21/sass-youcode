#include <stdio.h>
#include <string.h>

int main(){
    char str1[20];
    printf("taper la 1er chaine : ");
    scanf("%c",&str1);

    int i,l;
    l=strlen(str1);

    for(i=l-1;i>=0;i--){
        printf("%c",str1[i]);
    }

    return 0;
    }

