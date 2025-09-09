#include <stdio.h>
#include <string.h>

int max(int arr[] ,int  l){
    int max=arr[0];
    for (int i=0;i<l;i++){
            if(max<arr[i]){
                max=arr[i];
        }
    }
        printf("le max de tabelau est : %d\n",max);
    return 0;
}

int min(int arr[] ,int  l){
    int min=arr[0];
    for (int i=0;i<l;i++){
            if(min>arr[i]){
                min=arr[i];
        }
    }
    printf("le min de tabelau est : %d\n",min);


    return 0;
}
int somme(int arr[],int l){
    int s=0;
    for (int i =0 ; i<l;i++){
        s=s+arr[i];
    }
    printf("la somme de tableau est : %d\n",s);
    return s;
}
int ordre(int arr[],int l){
    int temp;
    for (int i=0;i<l-1;i++) {
        for (int j=i+1;j<l;j++) {
            if (arr[i]>arr[j]) {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for (int i = 0; i < l; i++) {
        printf("T[%d] = %d\n", i, arr[i]);
    }
}


int main() {
    int el;
    printf("taper le nombre de element de tableau : ");
    scanf("%d",&el);
    int T[el];

    for (int i = 0; i < el; i++) {
        printf("T[%d] = ", i);
        scanf("%d", &T[i]);
    }
    printf("\n");
    for (int i =0;i<el;i++){
        printf("T[%d]= %d\n",i,T[i]);
    }
    printf("\n");
    max(T,el);
    min(T,el);
    somme(T,el);
    ordre(T,el);
    return 0;
}
