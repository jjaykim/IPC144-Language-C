//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NNN
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>
#define NUMS 3		// macro definition

int main(void)
{
	// declare the variables and initialize at all
	int hightemp = 0, lowtemp = 0, day = 0;
	double avetemp = 0.0;
	int valid;	// true = any NON-ZERO value other false = 0


	// Print the title of the application
	printf("---=== IPC Temperature Analyzer ===---\n");
	
	// Set the for statement to calculate days automatically 
	for (day = 1; day <= NUMS; day++)	
	{
		// Set the dp-while stateme to check the user's inputted conditions
		do	
		{
			valid = 1;	// assume entered value will be correct
			printf("Enter the high value for day %d: ", day);	
			scanf("%d", &hightemp);
			printf("\n" 
			
			);

			printf("Enter the low value for day %d: ", day);		
			scanf("%d", &lowtemp);
			printf("\n");

			// Explore the error range
			if (hightemp > 40 || lowtemp < -40 || hightemp < lowtemp)	
			{	
				valid = 0;	// Invalid false 
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.");
				printf("\n\n");
			}
			else  
			{
				// Calculate the results of hightemp and lowtemp
				avetemp = avetemp + hightemp + lowtemp;	
			}
		} while (!valid);	// loop while invalid (wrong value)

	}

	//Calculate and display the results of average temperature
	avetemp /= (double)(NUMS * 2);
	printf("The average (mean) temperature was: %.2lf", avetemp);
	
	return 0;
}