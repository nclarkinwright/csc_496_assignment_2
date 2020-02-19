/*
* Nicholas Clarkin-Wright
* CSC 496
* Assignment Two
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_int_array(int* array, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}

// Places int in an int array, that is already sorted, in a sorted spot by ascending order
// Should be called on array repeatedly as elements are inserted
void my_insertion_sort(int* array, int array_size, int to_be_inserted)
{
    // Start at end of array 
    for(int i = array_size - 1; i >= 1; i--)
    {
        // If next element over from i, toward beginning of arary,  is less than value to be inserted, insert element
        if (array[i - 1] <= to_be_inserted)
        {
            array[i] = to_be_inserted;
            return;
        }
        // Move element greater than value to be inserted one spot closer to end of array
        else
        {
            array[i] = array[i - 1];
        }  
    }

    // Insert at beginning of array if all values are greater than to_be_inserted
    array[0] = to_be_inserted;
    return;
}

int main(int argc, char* argv[])
{
    char *file, *line, *number_str;
    size_t buf_size = 0;
    FILE *filep;
    int chars_read, numbers_size = 0, *numbers = NULL, number, could_not_place;
    
    // Exit with improperly formatted command
    if (argc != 2)
    {
        return 0;
    }

    // Get file and open
    file = argv[1];
    filep = fopen(file, "r");
    if (filep == NULL)
    {
        printf("sort: cannot open file\n");
        return 1;
    }
     
    // Get list of integers out of file and into array
    while( (chars_read = getline(&line, &buf_size, filep)) != -1)
    {
        // For first integer on a line, must perform once outside of inner loop because of
        // strtok() behavior
        number_str = strtok(line, " ");
        
        // Increase size of array and resize array in memory
        numbers_size++;
        numbers = (int*)realloc(numbers, numbers_size * sizeof(int));
        
        // Convert integer in string to an int and place in array using insertion sort
        number = (int)strtol(number_str, &number_str, 0);
        my_insertion_sort(numbers, numbers_size, number);
        
        // Call strtok() until line is empty
        while((number_str = strtok(NULL, " ")) != NULL)
        {
            // Increase size of array and resize array in memory
            numbers_size++;
            numbers = (int*)realloc(numbers, numbers_size * sizeof(int));
            
            // Convert integer in string to an int and place in array using insertion sort
            number = (int)strtol(number_str, &number_str, 0);
            my_insertion_sort(numbers, numbers_size, number);
        }
    }

    // Close file when no longer needed
    fclose(filep);

    // Display array of numbers
    display_int_array(numbers, numbers_size);

    free(numbers);
    if (line != NULL)
    {
        free(line);
    }

    return 0;
}