#include <stdio.h>

// Function to print binary (4 bits)
void printBinary(int num) {
    for (int i = 3; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    int dividend, divisor;
    int A = 0, Q, M, n = 4;
    int i;

    printf("Enter dividend (0-15): ");
    scanf("%d", &dividend);
    printf("Enter divisor (1-15): ");
    scanf("%d", &divisor);

    if (divisor == 0) {
        printf("Error: Division by zero not allowed!\n");
        return 0;
    }

    Q = dividend; // Quotient register
    M = divisor;  // Divisor

    printf("\n--- Non-Restoring Division Steps ---\n");
    printf("Initial: A=%d (", A); printBinary(A);
    printf("), Q=%d (", Q); printBinary(Q);
    printf("), M=%d (", M); printBinary(M);
    printf(")\n");

    for (i = 0; i < n; i++) {
        // Step 1: Left shift (A,Q)
        A = (A << 1) | ((Q & 0x8) >> 3); // bring MSB of Q into LSB of A
        Q = (Q << 1) & 0xF;              // keep Q within 4 bits

        // Step 2: Conditional operation
        if (A >= 0) {
            A = A - M;   // subtract divisor
            if (A >= 0) Q = Q | 1; // set Q0 = 1
        } else {
            A = A + M;   // add divisor
            if (A >= 0) Q = Q | 1; // set Q0 = 1
        }

        printf("Step %d: A=%2d (", i + 1, A); printBinary(A & 0xF);
        printf("), Q=%2d (", Q); printBinary(Q);
        printf(")\n");
    }

    // Final correction if remainder is negative
    if (A < 0) {
        A = A + M;
    }

    printf("\nFinal Result:\n");
    printf("Quotient  = %d (", Q); printBinary(Q);
    printf(")\n");
    printf("Remainder = %d (", A); printBinary(A & 0xF);
    printf(")\n");

    return 0;
}
