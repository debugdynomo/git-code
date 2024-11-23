#include <stdio.h>

void generateMagicSquare(int n) {
    if (n % 2 == 0) {
        printf("Magic square is only possible for odd-order matrices.\n");
        return;
    }

    int magicSquare[n][n];

    // Initialize all positions as 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    // Initial position of 1
    int i = 0, j = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magicSquare[i][j] = num;

        // Calculate new position
        int new_i = (i - 1 + n) % n;
        int new_j = (j + 1) % n;

        // Check if the new position is already occupied
        if (magicSquare[new_i][new_j] != 0) {
            new_i = (i + 1) % n;
            new_j = j;
        }

        i = new_i;
        j = new_j;
    }

    // Print the magic square
    printf("Magic Square of order %d:\n", n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the order of the magic square (odd number): ");
    scanf("%d", &n);

    generateMagicSquare(n);

    return 0;
}
