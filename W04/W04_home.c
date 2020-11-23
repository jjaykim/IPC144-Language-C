//==============================================
// Name:           Jungjoo Kim 
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NNN
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Place your code below

#include <stdio.h>
#define MINDAYS 3
#define MAXDAYS 10

/*
    You only need 2 array’s; one for the high temperatures and one for the low temperatures
    • Using an array(s) for accumulating the temperatures is problematic, inefficient, and restricts the application design.
    • What if you needed to modify one or more of the input temperature values (after the user has input the data)? 
    You would have to recalculate all the sum/total array’s!
*/

int main(void)
{
    // declare the variables and initialize at all.
    int valid = 0;	// true = any NON-ZERO value other false = 0
    int	day = 0, count = 0, aveinputday = 0, avecount = 0;
    // int hightemps[MAXDAYS] = { 0 }, lowtemps[MAXDAYS] = { 0 }, avetemps[MAXDAYS] = { 0 };
    int hightemps[MAXDAYS] = { 0 }, lowtemps[MAXDAYS] = { 0 };  // *** Feedback ***
    int highesttemps = -40, lowesttemps = 40, hightestday = 0, lowestday = 0;
    double totolavetemps = 0.0;

    // Print the title of the application.
    printf("---=== IPC Temperature Calculator V2.0 ===---\n");

    // prompt the user for how many days
    printf("Please enter the number of days, between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
    scanf("%d", &day);
    printf("\n");

    //Set the "while" loop to explore the error range.
    while (day < MINDAYS || day > MAXDAYS)      // *** feedback ***
    {
        printf("Invalid entry, please enter a number between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
        scanf("%d", &day);
        printf("\n");
    }

    // Set the "for" loop to allocate the value of the high and low temperatures for each index correctly.
    for (count = 0; count < day; count++)
    {
        do
        {
            valid = 1;
            printf("Day %d - High: ", count + 1);
            scanf("%d", &hightemps[count]);

            printf("Day %d - Low: ", count + 1);
            scanf("%d", &lowtemps[count]);

            // Set the "if" loop to explore the error range.
            if (hightemps[count] > 40 || lowtemps[count] < -40 || hightemps[count] <= lowtemps[count])
            {
                valid = 0;	// Invalid false 
                printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.");
                printf("\n\n");
            }
            // else // *** Feedback ***
            // {
            //     // Calculate and allocate the average results of total high and low temperatures for each index correctly.
            //     avetemps[count] = hightemps[count] + lowtemps[count];
            // }

            // Allocate the value of the highest temperature and day for each index correctly.
            if (hightemps[count] > highesttemps)
            {
                highesttemps = hightemps[count];
                hightestday = count + 1;
            }

            // Allocate the value of the Lowest temperature and day for each index correctly.
            if (lowtemps[count] < lowesttemps)
            {
                lowesttemps = lowtemps[count];
                lowestday = count + 1;
            }
        } while (!valid);       // True : All the values have been entered correctly.
    }

    // Display the results of each high and low temperature flowing the date respectively.   
    printf("\n");
    printf("Day  Hi  Low\n");

    for (count = 0; count < day; count++)
    {
        printf("%d    %d    %d\n", count + 1, hightemps[count], lowtemps[count]);
    }

    printf("\n");
    printf("The highest temperature was %d, on day %d\n", highesttemps, hightestday);
    printf("The lowest temperature was %d, on day %d\n", lowesttemps, lowestday);
    printf("\n");

    // Set the "do-while" loop to calculate and display the average value of the day the user wants 
    // until the user inputs the signal of exit.
    do
    {
        // prompt the user for days the user wants.
        printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", day);
        scanf("%d", &aveinputday);
        printf("\n");

        //Set the "while" loop to explore the error range.
        while (aveinputday > day || aveinputday == 0)
        {
            printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", day);
            scanf("%d", &aveinputday);
            printf("\n");
        }

        // explore the signal to exit
        if (aveinputday < 0)
        {
            printf("Goodbye!");
            valid = 1;      // True : The user wants to exit from loop.
        }
        else
        {
            // Set the "for" statement to calculate the average value of the day the user wants.
            for (avecount = 0; avecount >= 0 && avecount < aveinputday; avecount++)
            {
                totolavetemps += (hightemps[avecount] + lowtemps[avecount]);
            }

            // Display the result of average the user wants.
            printf("The average temperature up to day %d is: %.2lf\n", aveinputday, totolavetemps / (aveinputday * 2));
            printf("\n");

            // initialize the value of total temperatures for calculating again.
            totolavetemps = 0;
            valid = 0;          // False : Set for only iteration in the loop.
        }

    } while (!valid);

    return 0;

}