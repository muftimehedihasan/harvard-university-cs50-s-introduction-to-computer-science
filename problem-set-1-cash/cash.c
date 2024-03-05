#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Initialize variables to store the count of each coin denomination
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;

    // Calculate how many quarters you should give customer
    quarters = cents / 25;
    cents %= 25;

    // Calculate how many dimes you should give customer
    dimes = cents / 10;
    cents %= 10;

    // Calculate how many nickels you should give customer
    nickels = cents / 5;
    cents %= 5;

    // Calculate how many pennies you should give customer
    pennies = cents;

    // Sum the number of quarters, dimes, nickels, and pennies used
    int total_coins = quarters + dimes + nickels + pennies;

    // Print the total number of coins needed
    printf("%d\n", total_coins);

    return 0;
}
