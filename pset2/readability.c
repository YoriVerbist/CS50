#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

float calculateIndex(float letters, float words, float sentences);

int main(int argc, char const *argv[])
{
    char *text = get_string("Text: \n"); // Get text input from user
    float letters = 0;
    float sentences = 0;
    float words = 1; // 1 So it handles the end of the sentences (.)

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    //printf("%i\n%i\n%i", letters, words, sentences);

    int index = calculateIndex(letters, words, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

float calculateIndex(float letters, float words, float sentences)
{
    float L = 100 / words * letters; // Average number of letters per 100 words.
    float S = (100 / words) * sentences; // Average number of sentences per 100 words.
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}