#include<stdio.h>
int n,i;
int one(int o[n]){
    for(i=0;i<6;i++){
        if(o[i]==0){
            o[i]=1;
        }
        else{
            o[i]=0;
        }
    }
}
void two(int t[6]) {
    int i, carry = 1; // Start with carry = 1 (that's the +1 step)
    for(i = 0; i < 6; i++) {
        int sum = t[i] + carry;
        t[i] = sum % 2;
        carry = sum / 2;
    }
}

int main(){
    int bin[6];
    int dec;
    int sign,mag;
    
    printf("Enter decimal no.: ");
    scanf("%d",&dec);
    if(dec<0){
        sign=1;
        mag=-dec;
    }
    else{
        sign=0;
        mag=dec;
    }
    for(i=0;i<6;i++){
        bin[i]=mag%2;
        mag=mag/2;
    }
    printf("Binary no.: ");
    printf("%d",sign);
    for(i=5;i>=0;i--){
        printf("%d",bin[i]);
    }
    printf("\n");
    printf("One's Complement: ");
    printf("%d",sign);
    if(dec<0){
        one(bin);
    }
    for(i=5;i>=0;i--){
        printf("%d",bin[i]);
    }
    printf("\n");
    printf("Two's Complement: ");
    if(dec<0){
        two(bin);
    }
    printf("%d",sign);
    for(i=5;i>=0;i--){
        printf("%d",bin[i]);
    }
    
    return 0;
}