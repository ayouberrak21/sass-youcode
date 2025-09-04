#include <stdio.h>
#include <string.h>

struct perssone{
    char non[10];
    char prenon[10];
    int age;
};
int main() {
    struct perssone p1;

    strcpy(p1.non,"ayoub");
    strcpy(p1.prenon,"errak");
    p1.age=21;

    printf("mon non : %s\n mon prenon : %s\n mon age : %d\n",p1.non,p1.prenon,p1.age);
    return 0;
}
