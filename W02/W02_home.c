//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NNN
// Workshop:       Part-2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
#include <stdio.h>

int main(void)
{
    double cash = 0.0;
    int loonies = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;
   
    // prompt the user for the amount of dollars
    printf("Please enter the amount to be paid: $");
    scanf("%lf", &cash);

    // Caluclate and display the value of GST
    double gst = (cash * 0.13) + 0.005;         // + 0.005 is used to round up
    printf("GST: %.2lf\n", gst);

    // Exchange the value of cash with GST
    cash += gst;
    printf("Balance owing: $%.2lf\n", cash); 

    // Caluclate and show the equivalencyof the inputted value
    int totcash = (int)((cash * 100) + 0.5);    // +0.5 is used to prevent truncation issue

    // Calculate and show the result of loonies
    loonies = totcash / 100;
    totcash %= 100;
    printf("Loonies required: %d, balance owing $%.2lf\n", loonies, (double)totcash / 100);

    // Caluclate and show the result of quarters
    quarters = totcash / 25;
    totcash %= 25;
    printf("Quarters required: %d, balance owing $%.2lf\n", quarters, (double)totcash / 100);

    // Caluclate and show the result of dimes
    dimes = totcash / 10;
    totcash %= 10;
    printf("Dimes required: %d, balance owing $%.2lf\n", dimes, (double)totcash / 100);

    // Caluclate and show the result of nickels
    nickels = totcash / 5;
    totcash %= 5;
    printf("Nickels required: %d, balance owing $%.2lf\n", nickels, (double)totcash / 100);

    // Caluclate and show the result of pennies
    pennies = totcash;
    printf("Pennies required: %d, balance owing $%.2lf\n", pennies, (double)totcash - (double)pennies);

    return 0;

}