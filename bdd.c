#include<stdio.h>
void main(){
    int a[4],b[4],c[4],i;
    printf("Enter first binary no.: ");
    for(i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter second binary no.: ");
    for(i=0;i<4;i++){
        scanf("%d",&b[i]);
    }
    int carry=0;
    for(i=0;i<4;i++){
        int sum=a[i]+b[i]+carry;
        c[i]=sum%2;
        carry=sum/2;
    }
    printf("Sum: ");
    for(i=0;i<4;i++){
        printf("%d",c[i]);
    }
    printf("\n");
}