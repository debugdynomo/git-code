#include <stdio.h>

// Function to swap two characters
void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Function to find the length of the string
int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to print all permutations of a string
void permute(char *str, int left, int right) {
    if (left == right) {
        printf("%s\n", str); // Print the current permutation
    } else {
        for (int i = left; i <= right; i++) {
            swap((str + left), (str + i)); // Swap for the next permutation
            permute(str, left + 1, right); // Recur for the rest
            swap((str + left), (str + i)); // Backtrack to the original string
        }
    }
}

int main() {
    char str[] = "ABC"; // Change this string to test with different inputs
    int n = stringLength(str);
    printf("All permutations of the string \"%s\" are:\n", str);
    permute(str, 0, n - 1);
    return 0;
}


