#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for their name
    string name = get_string("Enter your name: ");

    // Print a greeting message
    printf("hello, %s\n", name);
}

