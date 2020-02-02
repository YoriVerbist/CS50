#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        const char *key = argv[1];
        char *plaintext = get_string("plaintext: \n");

        for (int i = 0; i < strlen(key); i++)
        {
            if (isdigit(key[i]))
            {
                printf("Don't put a number in the key.\n");
                return 1; // If there is a number in the key, stop the program
            }
        }
        
        printf("ciphertext: ");

        for (int i = 0; i < strlen(plaintext); i++)
        {
            char letter = plaintext[i];
            char newLetter;
            int place = 0;

            if (isalpha(letter))
            {
                if (isupper(letter))
                {
                    place = letter - 65;
                    newLetter = key[place];
                    newLetter = toupper(newLetter);
                }
                else
                {
                    place = letter - 97;
                    newLetter = key[place];
                    newLetter = tolower(newLetter);
                }
                printf("%c", newLetter);
            }
            else
            {
                printf("%c", letter);
            }
            
        }
        printf("\n");
        return 0;
    }
}
