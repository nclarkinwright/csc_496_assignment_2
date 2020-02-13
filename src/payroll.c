/*
* Nicholas Clarkin-Wright
* CSC 496
* Assignment Two
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
    char *line = NULL, *first_name, *last_name;
    size_t buf_size = 0;
    const char delim[] = {' ','\t','\n','\v','\f','\r'};
    int hours_worked;
    double hourly_rate;
    
    printf("Enter first name: ");
    getline(&line, &buf_size, stdin);
    first_name = strtok(line, delim);
    line = NULL;
    
    printf("Enter last name: ");
    getline(&line, &buf_size, stdin);
    last_name = strtok(line, delim);
    line = NULL;

    printf("Enter hours worked: ");
    getline(&line, &buf_size, stdin);
    hours_worked = (int) round(strtod(line, &line));
    line = NULL;
    
    printf("Enter hourly rate: ");
    getline(&line, &buf_size, stdin);
    hourly_rate = strtod(line, &line);
    
    printf("%s, %s: %.2lf\n", last_name, first_name, hours_worked*hourly_rate);
    
    return 0;
}
