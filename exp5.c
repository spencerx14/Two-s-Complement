#include <stdio.h>

int main() {
    int dividend, divisor;
    int A = 0, Q, M, n = 4; // 4-bit numbers
    int i;

    printf("Enter dividend (0-15): ");
    scanf("%d", &dividend);
    printf("Enter divisor (1-15): ");
    scanf("%d", &divisor);

    if (divisor == 0) {
        printf("Error: Division by zero not allowed!\n");
        return 0;
    }

    Q = dividend; // Quotient register initially dividend
    M = divisor;  // Divisor register

    printf("\n--- Restoring Division Algorithm Steps ---\n");
    printf("Initial: A=%d, Q=%d, M=%d\n", A, Q, M);

    for (i = 0; i < n; i++) {
        // Step 1: Left shift (A,Q)
        A = (A << 1) | ((Q & 0x8) >> 3); // bring MSB of Q into LSB of A
        Q = (Q << 1) & 0xF;              // keep Q within 4 bits

        // Step 2: Subtract M
        A = A - M;

        // Step 3: Check sign
        if (A >= 0) {
            Q = Q | 1; // set Q0 = 1
        } else {
            A = A + M; // restore
            // Q0 stays 0
        }

        printf("Step %d: A=%d, Q=%d\n", i + 1, A, Q);
    }

    printf("\nFinal Result:\n");
    printf("Quotient  = %d\n", Q);
    printf("Remainder = %d\n", A);

    return 0;
}
