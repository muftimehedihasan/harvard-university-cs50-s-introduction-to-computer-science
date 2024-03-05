#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 2, 4, 4, 8, 4, 10};

int calculate_score(const char *word)
{
    int score = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        char letter = tolower(word[i]); // Convert to lowercase for case-insensitive scoring
        if (letter >= 'a' && letter <= 'z')
        {
            score += POINTS[letter - 'a'];
        }
    }
    return score;
}

int main()
{
    char word1[50], word2[50];

    // Prompt player 1 and calculate score
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = '\0'; // Remove newline character
    int score1 = calculate_score(word1);

    // Prompt player 2 and calculate score
    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = '\0'; // Remove newline character
    int score2 = calculate_score(word2);

    // Determine and print winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
