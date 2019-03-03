#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // Ask user how high the pyramid needs to be (max height = 8)
    do
    {
        height = get_int("How high do you want the pyramide to be? ");
    } while (height < 1 || height > 8); // Only accept height between 0 and 9

    for(int line = 0; line < height; line++) // Line per line
    {
        for(int spaces = height - line; spaces > 1; spaces--) // Prints the spaces
        {
            printf(" ");
        }
        for(int hashes = 0; hashes < line + 1; hashes++) // Prints hashes
        {
            printf("#");
        }
        printf(" ");
        for(int hashes = 0; hashes < line + 1; hashes++)
        {
            printf("#");
        }
        printf("\n");   
    }
    return 0;
}
