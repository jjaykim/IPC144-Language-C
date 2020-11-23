//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NNN
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include <stdio.h>

int main(void)
{
    double cash = 0.0;
    int loonies = 0, quarters = 0;
    
    // prompt the user for the amount of dollars
    printf("Please enter the amount to be paid: $");
    scanf("%lf", &cash);

    // Show the equivalency of the inputted value
    int totcash = cash * 100;

    // Calculate and show the result of loonies
    loonies = totcash / 100;
    totcash %= 100;
    printf("Loonies required: %d, balance owing $%.2lf\n", loonies, totcash * 0.01);

    // Caluclate and show the result of quarters
    quarters = totcash / 25;
    totcash %= 25;
    printf("Quarters required: %d, balance owing $%.2lf\n", quarters, totcash * 0.01);

    return 0;

}