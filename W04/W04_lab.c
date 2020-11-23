//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NNN
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>
#define MAXDAYS 10

int main(void)
{
    // declare the variables and initialize at all
    int valid = 0;	// true = any NON-ZERO value other false = 0
    int	day = 0, count = 0;
    int hightemps[MAXDAYS] = { 0 }, lowtemps[MAXDAYS] = { 0 };

    // Print the title of the application
    printf("---=== IPC Temperature Calculator V2.0 ===---\n");

    // Set the do -while loop to calculate and display the results 
    do
    {

        // prompt the user for how many days
        printf("Please enter the number of days, between 3 and 10, inclusive: ");
        scanf("%d", &day);

        //Set the "if" loop to explore the error range
        if (day < 3 || day > 10)
        {
            while (day < 3 || day > 11)
            {
                printf("\n");
                printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
                scanf("%d", &day);
                printf("\n");
            }
        }

        // Set the "for" loop to allocate the value of the high and low temperatures
        for (count = 0; count < day; count++)
        {
            do
            {
                valid = 1;
                printf("Day %d - High: ", count + 1);
                scanf("%d", &hightemps[count]);

                printf("Day %d - Low: ", count + 1);
                scanf("%d", &lowtemps[count]);

                // Set the "if" loop to explore the error range
                if (hightemps[count] > 40 || lowtemps[count] < -40 || hightemps[count] <= lowtemps[count])
                {
                    valid = 0;	// Invalid false 
                    printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.");
                    printf("\n\n");
                }
            } while (!valid);
        }

        // True : All the values have been entered correctly
    } while (!valid);


    // Display the results of each high and low temperature flowing the date respectively   
    printf("\n");
    printf("Day  Hi  Low\n");

    for (count = 0; count < day; count++)
    {
        printf("%d    %d    %d\n", count + 1, hightemps[count], lowtemps[count]);
    }

    return 0;

}