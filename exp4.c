#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert binary string to integer
int binToDec(char *bin) {
    int num = 0;
    while (*bin) {
        num = num * 2 + (*bin - '0');
        bin++;
    }
    return num;
}

// Function to convert decimal to binary string
void decToBin(int num, char *bin) {
    char temp[65];
    int i = 0;

    if (num == 0) {
        strcpy(bin, "0");
        return;
    }

    while (num > 0) {
        temp[i++] = (num % 2) + '0';
        num /= 2;
    }

    temp[i] = '\0';

    // Reverse the string
    for (int j = 0; j < i; j++) {
        bin[j] = temp[i - j - 1];
    }
    bin[i] = '\0';
}

int main() {
    int choice, op;
    char bin1[65], bin2[65], resultBin[65];
    unsigned int hex1, hex2, result;
    int dec1, dec2;

    printf("Choose number system:\n");
    printf("1. Binary\n");
    printf("2. Hexadecimal\n");
    scanf("%d", &choice);

    printf("Choose operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    scanf("%d", &op);

    if (choice == 1) {
        // Binary operations
        printf("Enter first binary number: ");
        scanf("%s", bin1);
        printf("Enter second binary number: ");
        scanf("%s", bin2);

        dec1 = binToDec(bin1);
        dec2 = binToDec(bin2);

        if (op == 1)
            result = dec1 + dec2;
        else
            result = dec1 - dec2;

        decToBin(result, resultBin);

        printf("\n=== Result (Binary Mode) ===\n");
        printf("Binary Result     : %s\n", resultBin);
        printf("Hexadecimal Result: %X\n", result);
        printf("Decimal Result    : %d\n", result);
    }
    else if (choice == 2) {
        // Hexadecimal operations
        printf("Enter first hexadecimal number: ");
        scanf("%x", &hex1);
        printf("Enter second hexadecimal number: ");
        scanf("%x", &hex2);

        if (op == 1)
            result = hex1 + hex2;
        else
            result = hex1 - hex2;

        char binResult[65];
        decToBin(result, binResult);

        printf("\n=== Result (Hexadecimal Mode) ===\n");
        printf("Hexadecimal Result: %X\n", result);
        printf("Binary Result     : %s\n", binResult);
        printf("Decimal Result    : %d\n", result);
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
