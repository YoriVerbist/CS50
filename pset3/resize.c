int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "You need to give 3 parameters: number n, input file, output file\n");
        return 1;
    }

    else if (argv[0] > 0 && argv[0] <= 100)
        {
            fprintf("The first parameter needs to be between 0 and 100.\n");
            return 1;
        }

    // Remember the file names
    char *infile = argv[1];
    char *outfile = argv[2];

     // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 1;
    }
    
    
    return 0;
}
