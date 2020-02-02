#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int calculateIndex();

int main(int argc, char const *argv[])
{
    char* text = get_string("Text: \n");
    int letters = 0;
    int sentences = 0;
    int words = 1;

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

    int index = calculateIndex(letters, words, sentences);

    printf("Grade %i", index);
    
    return 0;
}

int calculateIndex(int letters, int words, int sentences)
{
    int L = ; // Average number of letters per 100 words.
    int S = ; // Average number of sentences per 100 words.
    int index = 0.0588 * L - 0.296 * S - 15.8;
    
    return round(index);
}