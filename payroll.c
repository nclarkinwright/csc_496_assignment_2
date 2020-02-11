/*
* Nicholas Clarkin-Wright
* CSC 496
* Assignment Two
*/

# include <stdio.h>
# include <stdlib.h>
# define MAX_CHARS 30

int main(int argc, char* argv[]) {
    char first_name[MAX_CHARS], last_name[MAX_CHARS];
    int hours_worked;
    double hourly_rate;
    
    printf("Enter first name (30 characters max): ");
    fgets(first_name, MAX_CHARS, stdin);
    printf("Enter last name (30 characters max): ");
    fgets(last_name, MAX_CHARS, stdin);
    
}
