#include <stdio.h>

int main() {
    unsigned int hex1, hex2, sum;

    printf("Enter first hexadecimal number (up to 4 digits): ");
    scanf("%x", &hex1);

    printf("Enter second hexadecimal number (up to 4 digits): ");
    scanf("%x", &hex2);

    // Add the numbers
    sum = hex1 + hex2;

    // Mask to 4 hex digits (16 bits)
    sum = sum & 0xFFFF;

    printf("\n=== Result ===\n");
    printf("First Number : %04X (Decimal: %u)\n", hex1 & 0xFFFF, hex1);
    printf("Second Number: %04X (Decimal: %u)\n", hex2 & 0xFFFF, hex2);
    printf("Sum          : %04X (Decimal: %u)\n", sum, sum);

    return 0;
}
