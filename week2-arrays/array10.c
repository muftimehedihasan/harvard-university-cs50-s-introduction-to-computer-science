#include <cs50.h>
#include <stdio.h>

int numbers[5];
int i;

int main(void) {
    printf("Enter 5 numbers:\n");

    for (i = 0; i < 5; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        printf("\n"); // Add a newline after each prompt
    }

    printf("Entered numbers are:\n");

    for (i = 0; i < 5; i++) {
        printf("%d\n", numbers[i]); // Add a newline after each number
    }

    return 0;
}
