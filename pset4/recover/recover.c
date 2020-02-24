#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Give only 1 argument (image name)");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    // Check if the file exists
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", file);
        return 1;
    }
}
