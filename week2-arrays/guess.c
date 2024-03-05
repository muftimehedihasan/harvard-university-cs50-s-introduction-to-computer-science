#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = 5;

    int guess = get_int("what's your guess? ");

    while (guess != number)
    {
        printf("Wrong guess!");
    }
    printf("You're correct!");
}
