#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt the user for the height of the pyramid
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0); // Validate user input


    // Build the pyramid
    for (int i = 0; i < height; i++)
    {
        // Print spaces for alignment
        for (int j = height - 1; j > 1; j--)
        {
            printf(" ");
        }

        // Print hashes for the pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
      printf("\n"); // Move to the next line for the next

        ////
    }

    return 0;
}
