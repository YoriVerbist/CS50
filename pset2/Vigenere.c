#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if you give a keyword and nothing more
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        // check if the keyword doesn't contqin numbers
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                printf("Usage: ./vigenere keyword\n");
                return 2;
            }
        }
        // Get the text to encrypt
        string message = get_string("plaintext: ");
        int n = strlen(message);
        int len_alphabet = 26;
        int keyword_index = 0;

        // Convert keyword to uppercase
        for (int i = 0; argv[1][i]; i++)
        {
            argv[1][i] = toupper(argv[1][i]);
        }
        
        printf("ciphertext: ");

        for (int i = 0; i < n; i++)
        {
            char keyword_map = argv[1][keyword_index % strlen(argv[1])];

            if (islower(message[i])) // Change lowercase letters
            {
                printf("%c", (message[i] - 'a' + (keyword_map - 'A')) % len_alphabet + 'a');
                keyword_index++;
            }
            else if (isupper(message[i])) // Change uppercase letters
            {
                printf("%c", (message[i] - 'A' + (keyword_map - 'A')) % len_alphabet + 'A');
                keyword_index++;
            }
            else // If it isn't a letter do nothing
            {
                printf("%c", message[i]);
            }
        }
        printf("\n");
        return 0;
    }
}
