#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Give only 1 argument (image name)\n");
        return 1;
    }
    // Getting file name from command line
    char *infile = argv[1];

    // Opening the file
    FILE *file = fopen(infile, "r");
    // Check if the file exists
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    typedef uint8_t BYTE;
    BYTE buffer[512];

    while (fread(buffer, 512, 1,file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // Last check checks only for 0xe and doesn't care about the number after that.
        {
            
        }
        
    }
    
}
