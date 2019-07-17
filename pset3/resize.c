int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    if (argv[0] > 0 && argv[0] <= 100)
    {
        printf("The first parameter needs to be between 0 and 100.\n");
        return 1;
    }

    // Remember the file names
    char *infile = argv[1];
    char *outfile = argv[2];

     // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf(stderr, "Could not create %s.\n", outfile);
        return 1;
    }
    
    
    return 0;
}
