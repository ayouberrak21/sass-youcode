#include <stdio.h>
#include <math.h>


int main() {
    int note;
    printf("taper la note : ");
    scanf("%d",&note);

    if(note<10){
    printf("il est recalé");
    }
    else if (note>=10 && note<12){
    printf(" il obtient la mention passable");
    }
    else if (note>=12 && note<14){
    printf(" il obtient la mention assez bien");
    }
    else if (note>=14 && note<16){
    printf(" il obtient la mention bien");
    }
    else{
    printf(" il obtient la mention très bien");
    }

    return 0;

    }
