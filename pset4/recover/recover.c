#include <stdio.h>
#include <stdlib.h>

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
}
