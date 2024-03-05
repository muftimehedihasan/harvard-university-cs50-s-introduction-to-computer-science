#include <cs50.h>
#include <stdio.h>

// Declare function
int add_two_ints(int a, int b);

int main(void) {
    // Ask user for input
    printf("Give me an integer: ");
    int x;
    if (scanf("%d", &x) != 1) { // Check for successful read
        fprintf(stderr, "Error: Invalid input.\n");
        return 1; // Indicate error
    }

    printf("Give me another integer: ");
    int y;
    if (scanf("%d", &y) != 1) {
        fprintf(stderr, "Error: Invalid input.\n");
        return 1;
    }

    // Add the two numbers using a function call
    int z = add_two_ints(x, y);

    // Output the result
    printf("The sum of %i and %i is %i!\n", x, y, z);

    return 0; // Indicate successful execution
}

// Implementation of the function (assuming it adds two integers)
int add_two_ints(int a, int b) {
    return a + b;
}

