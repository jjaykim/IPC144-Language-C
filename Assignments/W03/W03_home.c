//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NNN
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 4		// macro definition

int main(void)
{
	// declare the variables and initialize at all
	int hightemp = 0, lowtemp = 0, mosthightemp = -40, mostlowtemp = 40;
	int day = 0, higesthday = 0, lowestday = 0;
	double totavetemp = 0.0, avehighmep = 0.0, avelowtemp = 0.0;
	int valid;	// true = any NON-ZERO value other false = 0


	// Print the title of the application
	printf("---=== IPC Temperature Analyzer ===---\n");

	// Set the for loop to calculate days automatically 
	for (day = 1; day <= NUMS; day++)
	{
		// Set the dp-while stateme to check the user's inputted conditions
		do
		{
			valid = 1;	// assume entered value will be correct
			printf("Enter the high value for day %d: ", day);
			scanf("%d", &hightemp);
			printf("\n");

			printf("Enter the low value for day %d: ", day);
			scanf("%d", &lowtemp);
			printf("\n");
			

			// Explore the error range
			if (hightemp > 40 || lowtemp < -40 || hightemp < lowtemp)
			{
				valid = 0;	// Invalid false 
				hightemp = 0;
				lowtemp = 0;
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.");
				printf("\n\n");
			}
			else
			{
				// Calculate and allocate the average results of each high and low and total temperature respectively
				avelowtemp += lowtemp;
				avehighmep += hightemp;
				totavetemp = totavetemp + hightemp + lowtemp;
			}

			// Allocate the value of the highest temperature
			if (hightemp > mosthightemp)
			{
				mosthightemp = hightemp;
				higesthday = day;
			}
			
			// Allocate the value of the Lowest temperature
			if (lowtemp < mostlowtemp)
			{
				mostlowtemp = lowtemp;
				lowestday = day;
			}
		} while (!valid);	// loop while invalid (wrong value)

	}

	//Calculate and display the results of each high and low and total temperature respectively
	avelowtemp /= (double)NUMS;
	printf("The average (mean) LOW temperature was: %.2lf\n", avelowtemp);

	avehighmep /= (double)NUMS;
	printf("The average (mean) HIGH temperakture was: %.2lf\n", avehighmep);

	totavetemp /= (double)(NUMS * 2);
	printf("The average (mean) temperature was: %.2lf\n", totavetemp);

	// Display the results of each highest and lowest temperature
	printf("The highest temperature was %d, on day %d\n", mosthightemp, higesthday);
	printf("The lowest temperature was %d, on day %d\n", mostlowtemp, lowestday);

	return 0;

}