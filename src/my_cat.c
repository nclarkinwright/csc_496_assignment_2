/*
* Nicholas Clarkin-Wright
* CSC 496
* Assignment 2
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *file, *line;
    FILE *filep;
    size_t buf_size;
    int chars_read;

    // If no file names given, exit
    if (argc == 1)
    {
        return 0;
    }

    // Loop through each filename 
    for (int i = 1; i < argc; i++)
    {
        // Get filename and attempt to open, return error if invalid
        file = argv[i];
        filep =fopen(file, "r");
        if (filep == NULL)
        {
            printf("my_cat: cannot open file\n");
            return 1;
        }

        // Grab line from file and print, until entire file is read
        chars_read = getline(&line, &buf_size, filep);
        while (chars_read != -1)
        {
            printf("%s", line);
            chars_read = getline(&line, &buf_size, filep);
        }

        fclose(filep);
    }

    free(line);
    return 0;
}