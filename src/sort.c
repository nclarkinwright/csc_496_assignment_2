/*
* Nicholas Clarkin-Wright
* CSC 496
* Assignment Two
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_partition(long int* array_left, long int* array_right, int array_size)
{
    long int pivot_value, pivot_index;
    int left_index = 0;
    int right_index = array_size - 1;
    
    // Pivot on first element
    pivot_value = *array_left;
    
    // Which pointer, of left and right, is to be advanced towards center
    int move_right = 1;
    
    // Sort array so elements less than pivot go on left, greater than pivot on right
    while (left_index < right_index)
    {
        // Check values on right
        while(move_right == 1)
        {
            // Break out of loop if pointers pass one another
            if (left_index < right_index)
            {
                break;
            }

            // If value on right is less than pivot, move it left
            // swap to moving left pointer
            if (*array_right <= pivot_value)
            {
                *array_left = *array_right;
                array_left++, left_index++;
                move_right = 0;
            }
            // Else advance right pointer
            else
            {
                array_right--, right_index--;
            }
        }

        // Check values on left
        while(move_right == 0)
        {
            // Break out of loop if pointers pass one another
            if (left_index < right_index)
            {
                break;
            }

            // If value on left is greater than pivot, move it right
            // swap to moving right pointer
            if (*array_left >= pivot_value)
            {
                *array_right = *array_left;
                array_right--, right_index--;
                move_right = 1;
            }
            // Else advance left pointer
            else
            {
                array_left++, left_index++;
            }
        }
    }

    // Place pivot
    *array_left = pivot_value;
    pivot_index = left_index;

    return pivot_index;
}

void my_quick_sort(long int* array_left, long int* array_right, int array_size)
{
    int pivot_index;
    
    // Base case, array size 1 or 0
    if (array_size <= 1)
    {
        return;
    }

    pivot_index = my_partition(array_left, array_right, array_size);
    // Pass left side
    my_quick_sort(array_left, array_right - pivot_index, pivot_index - 2);
    // Pass right side
    my_quick_sort(array_left + pivot_index + 1, array_right, array_size - pivot_index);
}

void display_int_array(int* array, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}

int main(int argc, char* argv[])
{
    char *file, *line, *number_str;
    size_t buf_size = 0;
    FILE *filep;
    int chars_read, numbers_size = 0, *numbers = NULL, *numbers_right, number;
    
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
        
        // Convert integer in string to an int and place in array
        number = strtol(number_str, &number_str, 0);
        numbers[numbers_size - 1] = number;
        
        // Call strtok() until line is empty
        while((number_str = strtok(NULL, " ")) != NULL)
        {
            // Increase size of array and resize array in memory
            numbers_size++;
            numbers = (int*)realloc(numbers, numbers_size * sizeof(int));
            
            // Convert integer in string to an int and place in array
            number = strtol(number_str, &number_str, 0);
            numbers[numbers_size - 1] = number;
        }
    }

    // Close file when no longer needed
    fclose(filep);
    
    // Sort numbers
    //numbers_right = numbers + numbers_size + 1;
    //my_quick_sort(numbers, numbers_right, numbers_size);

    // Display array of numbers
    display_int_array(numbers, numbers_size);

    free(numbers);
    if (line != NULL)
    {
        free(line);
    }

    return 0;
}