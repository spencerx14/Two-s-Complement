#include<stdio.h>
void main(){
    int n,bin[5],i;
    printf("Enter decimal no.: ");
    scanf("%d",&n);
    for(i=0;i<5;i++){
        bin[i]=n%2;
        n=n/2;
    }
    printf("Binary no.: ");
    for(i=4;i>=0;i--){
        printf("%d",bin[i]);
    }
}