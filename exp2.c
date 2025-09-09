#include <stdio.h>

int main() {
    int n, bin[5], i;
    printf("Enter decimal number (0-31): ");
    scanf("%d", &n);

    // Decimal to binary (5-bit)
    for(i=0; i<5; i++) {
        bin[i] = n % 2;
        n = n / 2;
    }

    printf("Binary: ");
    for(i=4; i>=0; i--) {
        printf("%d", bin[i]);
    }

    // One's complement
    for(i=0; i<5; i++) {
        bin[i] = (bin[i]==0) ? 1 : 0;
    }

    printf("\nOne's Complement: ");
    for(i=4; i>=0; i--) {
        printf("%d", bin[i]);
    }

    // Two's complement
    int carry = 1;
    for(i=0; i<5 && carry; i++) {
        int sum = bin[i] + carry;
        bin[i] = sum % 2;
        carry = sum / 2;
    }

    printf("\nTwo's Complement: ");
    for(i=4; i>=0; i--) {
        printf("%d", bin[i]);
    }
    printf("\n");

    return 0;
}
