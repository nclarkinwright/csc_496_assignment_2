/*
* Nicholas Clarkin-Wright
* CSC 496
* Assignment 2
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *line = NULL, *file;
    size_t buf_size = 0;
    int numbers[10], index = 0, chars_read, sum = 0;
    FILE *filep;
    
    // Check for filename in command
    if (argc != 2) {
        return 0;
    }
    file = argv[1];

    // Open file and check it
    filep = fopen(file, "r");
    if (filep == NULL)
    {
        printf("sum: could not open file\n");
        return 1;
    }
    
    // Get the 10 integers in the file
    chars_read = getline(&line, &buf_size, filep);
    while (chars_read != -1)
    {
        numbers[index] = atoi(line);
        ++index;
        chars_read = getline(&line, &buf_size, filep);
    }
    
    // Sum the integers and print
    for(int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
    {
        sum += numbers[i];
    }

    printf("The sum of these integers is %d.\n", sum);

    fclose(filep);
    free(line);
    
    return 1;
}