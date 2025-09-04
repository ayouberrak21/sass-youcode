#include <stdio.h>
#include <string.h>

int main(){
    char str1[20];
    char str2[20];
    printf("taper la 1er chaine : ");
    scanf("%s",&str1);
    printf("taper la 2eme chaine : ");
    scanf("%s",&str2);
    if(strcmp(str1,str2)==0){
        printf("les chaines sont egales");
    }else
        printf("les chaines sont differentes");

    return 0;
    }

