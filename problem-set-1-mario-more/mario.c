#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // Prompt the user for the height of the pyramid
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // Validate user input

    // Build the pyramid
    for (int i = 0; i < height; i++)
    {
        // Print spaces for left pyramid
        for (int j = height - 1; j > i; j--)
        {
            printf(" ");
        }
        // Print hashes for left pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        // Print gap between pyramids
        printf("  ");
        // Print hashes for right pyramid
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n"); // Move to the next line for the next row
    }

    return 0;
}
