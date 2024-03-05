#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt the user for a credit card number
    long long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number <= 0);

    // Validate the credit card number using Luhn's Algorithm
    int sum = 0;
    int digit_count = 0;
    bool is_second_digit = false;
    while (card_number > 0)
    {
        int digit = card_number % 10;
        if (is_second_digit)
        {
            digit *= 2;
            while (digit > 0)
            {
                sum += digit % 10;
                digit /= 10;
            }
        }
        else
        {
            sum += digit;
        }
        card_number /= 10;
        is_second_digit = !is_second_digit;
        digit_count++;
    }

    // Check if the sum's last digit is 0
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine the type of credit card
    if ((digit_count == 15) && (card_number == 34 || card_number == 37))
    {
        printf("AMEX\n");
    }
    else if ((digit_count == 16) && (card_number >= 51 && card_number <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((digit_count == 13 || digit_count == 16) && (card_number / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
