#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if you give a correct key with the program
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 2;
            }
        }
        
        // Atoi() changes the String to an int
        int cipherkey = atoi(argv[1]);
        //Ask for the text they want to encrypt
        string message = get_string("plaintext: ");
        int n = strlen(message);
        int len_alphabet = 26;

        while (cipherkey > 26)
        {
            cipherkey -= 26;
        }
        
        printf("ciphertext: ");
        for (int i = 0; i < n; i++)
        {
            if (islower(message[i]))
            {
                printf("%c", (message[i] - 'a' + cipherkey) % len_alphabet + 'a');
            }
            else if (isupper(message[i]))
            {
                printf("%c", (message[i] - 'A' + cipherkey) % len_alphabet + 'A');
            }
            // Leave non letters alone
            else
            {
                printf("%c", message[i]);
            }
            
        }
        printf("\n");
        
        return 0;
    }
}
