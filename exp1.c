#include <stdio.h>
#include <string.h>

// Function to convert decimal to binary using traditional division
void decimalToBinary(int decimal) {
    int binary[4] = {0}; // 4-bit binary array
    int i = 3; // Start from rightmost bit
    
    if (decimal == 0) {
        printf("Binary: 0000\n");
        return;
    }
    
    // Traditional division method
    while (decimal > 0 && i >= 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i--;
    }
    
    printf("Binary: ");
    for (int j = 0; j < 4; j++) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

// Function to convert single hex digit to 4-bit binary using switch case
void hexDigitToBinary(char hexDigit, char* binaryStr) {
    switch (hexDigit) {
        case '0':
            strcpy(binaryStr, "0000");
            break;
        case '1':
            strcpy(binaryStr, "0001");
            break;
        case '2':
            strcpy(binaryStr, "0010");
            break;
        case '3':
            strcpy(binaryStr, "0011");
            break;
        case '4':
            strcpy(binaryStr, "0100");
            break;
        case '5':
            strcpy(binaryStr, "0101");
            break;
        case '6':
            strcpy(binaryStr, "0110");
            break;
        case '7':
            strcpy(binaryStr, "0111");
            break;
        case '8':
            strcpy(binaryStr, "1000");
            break;
        case '9':
            strcpy(binaryStr, "1001");
            break;
        case 'A':
        case 'a':
            strcpy(binaryStr, "1010");
            break;
        case 'B':
        case 'b':
            strcpy(binaryStr, "1011");
            break;
        case 'C':
        case 'c':
            strcpy(binaryStr, "1100");
            break;
        case 'D':
        case 'd':
            strcpy(binaryStr, "1101");
            break;
        case 'E':
        case 'e':
            strcpy(binaryStr, "1110");
            break;
        case 'F':
        case 'f':
            strcpy(binaryStr, "1111");
            break;
        default:
            strcpy(binaryStr, "0000");
            printf("Invalid hex digit! Using 0000\n");
            break;
    }
}

// Function to convert 4-digit hexadecimal to 16-bit binary
void hexToBinary(unsigned int hexValue) {
    char hexStr[5];
    char binaryResult[17] = ""; // 16 bits + null terminator
    char tempBinary[5];
    
    // Convert hex number to string format
    sprintf(hexStr, "%04X", hexValue);
    
    printf("Hexadecimal: %s\n", hexStr);
    printf("16-bit Binary: ");
    
    // Process each hex digit
    for (int i = 0; i < 4; i++) {
        hexDigitToBinary(hexStr[i], tempBinary);
        strcat(binaryResult, tempBinary);
        printf("%s", tempBinary);
    }
    printf("\n");
}

int main() {
    int choice;
    unsigned int hexInput;
    int decimalInput;
    
    printf("=== Number Base Converter ===\n");
    printf("1. Convert Hexadecimal to Binary (4-digit hex to 16-bit binary)\n");
    printf("2. Convert Decimal to Binary (decimal to 4-bit binary)\n");
    printf("3. Exit\n");
    
    while (1) {
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a 4-digit hexadecimal number (using %%x format): ");
                if (scanf("%x", &hexInput) == 1) {
                    // Limit to 4 hex digits (16 bits)
                    hexInput = hexInput & 0xFFFF;
                    hexToBinary(hexInput);
                } else {
                    printf("Invalid hexadecimal input!\n");
                    // Clear input buffer
                    while (getchar() != '\n');
                }
                break;
                
            case 2:
                printf("Enter a decimal number (0-15 for 4-bit): ");
                if (scanf("%d", &decimalInput) == 1) {
                    if (decimalInput >= 0 && decimalInput <= 15) {
                        printf("Decimal: %d\n", decimalInput);
                        decimalToBinary(decimalInput);
                    } else {
                        printf("Number out of range! Please enter 0-15 for 4-bit binary.\n");
                    }
                } else {
                    printf("Invalid decimal input!\n");
                    // Clear input buffer
                    while (getchar() != '\n');
                }
                break;
                
            case 3:
                printf("Exiting program. Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
                break;
        }
    }
    
    return 0;
}