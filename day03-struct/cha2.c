#include <stdio.h>
#include <string.h>

struct perssone{
    char non[10];
    char prenon[10];
    int age;
    int note[5];
};
int main() {
    struct perssone p1;

    printf("taper ton non :");
    scanf("%s",p1.non);
    printf("taper ton prenon :");
    scanf("%s",p1.prenon);
    printf("taper ton age :");
    scanf("%d",&p1.age);
    int i;
    for (i=0;i<5;i++){
        printf("taper la note %d : ", i + 1);
        scanf("%d",&p1.note[i]);
    }

    printf("\n mon non : %s\n mon prenon : %s\n mon age : %d\n mes notes sont : ",p1.non,p1.prenon,p1.age);
    for (int i = 0; i < 5; i++) {
        printf("%d  ", p1.note[i]);
    }
    printf("\n");
    return 0;
}
