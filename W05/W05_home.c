//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NNN
// Workshop:       5 (at-home)
//==============================================

// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 4
#define SIZE 4

// Declare Struct Employee 
struct Employee
{
	int empid;			// Declare Employee ID
	int empage;			// Declare Employee Age
	double empsalary;	// Declare Employee Salary
};

/* main program */
int main(void) 
{
	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee emp[SIZE] = { {0} };
	int valid = 0;	// true = any NON-ZERO value other false = 0
	int option = 0, empcount = 0, loopcount = 0;
	int updateid = 0, updatecount = 0; 
	// double newsalary = 0.0;  edited 
 int idvalid = 0;  // *** Feedback ***
	
	
    
	printf("---=== EMPLOYEE DATA ===---\n\n");

	do 
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		
		// Capture input to option variable
		scanf("%d",&option);
		printf("\n");

		
		switch (option) 
		{
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!");
			break;

		case 1: // Display Employee Data
				// @AT_HOME

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0
			// Initialize variable "loopcount" to start from first index
			for (loopcount = 0; loopcount < SIZE; loopcount++)
			{
				if (emp[loopcount].empid > 0)
				{
					printf("%6d%9d%11.2lf\n", emp[loopcount].empid,
											  emp[loopcount].empage,
											  emp[loopcount].empsalary);
				}
			}
			printf("\n");
			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 
			break;

		case 2:	// Adding Employee
				// @AT_HOME
				printf("Adding Employee\n");
				printf("===============\n");

    // *** Feedback ***
    idvalid = 0;  // Control to exit from the loop

				// Check for limits on the array.
				if (empcount < SIZE)
				{                                  // *** Feedback ***
					for (loopcount= 0; loopcount < SIZE && idvalid == 0; loopcount++)
					{
						// Set the "if" statement to add employee data accordingly 
						// and check the empty array
						if (emp[loopcount].empid < 1)
						{
							printf("Enter Employee ID: ");
							scanf("%d", &emp[loopcount].empid);
							printf("Enter Employee Age: ");
							scanf("%d", &emp[loopcount].empage);
							printf("Enter Employee Salary: ");
							scanf("%lf", &emp[loopcount].empsalary);
							printf("\n");
       idvalid = 1; // Set to exit the loop *** Feeedbakc***
							// loopcount = SIZE;	// Set to exit the loop *** feedback ***
							empcount++;
						}
					}
				} else
				{
					printf("ERROR!!! Maximum Number of Employees Reached\n");
					printf("\n");
				}
			break;
		
		case 3: // Update Salary
				// @AT_HOME

			printf("Update Employee Salary\n");
			printf("======================\n");

			// Set the "do-while" loop to find the ID user want to change.
			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &updateid);
				
				// Set the "for" loop to check 
				// if the original user ID matches the user input ID.
				{                             
				idvalid = 0; // Control to exit from the loop *** Feedback ***
    for (loopcount = 0; loopcount < SIZE && idvalid == 0; loopcount++)
				{
					if (updateid == emp[loopcount].empid)
					{
						valid = 0;				 
						printf("The current salary is %.2lf\n", emp[loopcount].empsalary);
						/* *** edited *** */
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[loopcount].empsalary);
						/* *** edited ***
						updatecount = loopcount;  // store the correct index before the next step.
						*/
      idvalid = 1; // Control to exit from the loop *** Feedback ***
						// loopcount = SIZE;		  // Minimize the number of the loop working. *** Feedback ***
					} else
					{
 						valid = 1;				  // Means Id of user input is not correct.
					}
				}
    }
				
				if (valid == 1)
				{
					printf("*** ERROR: Employee ID not found! ***\n");
				}
			} while (valid);					  // Find the coreect index

			/* *** Edited ***
			// Allocate Employee new Salary to the matching index the user want to change.
			printf("Enter Employee New Salary: ");
			scanf("%lf", &newsalary);
			emp[updatecount].empsalary = newsalary;
			printf("\n");
			*/

			break;
		
		case 4: // Remove Employee
				// @AT_HOME

			printf("Remove Employee\n");
			printf("===============\n");

			// Set the "do-while" loop to find the ID user want to change.
			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &updateid);
				
				// Set the "for" loop to check 
				// if the original user ID matches the user input ID.
				idvalid = 0; // Control to exit from the loop *** Feedback ***
				for (loopcount = 0; loopcount < SIZE && idvalid == 0; loopcount++)
				{
					if (updateid == emp[loopcount].empid)
					{
						valid = 0;
						printf("Employee %d will be removed\n", emp[loopcount].empid);
						printf("\n");
						emp[loopcount].empid = 0;	// The meaning of "ID = -1" is null value.
						empcount--;					// Decrement to fit in the condition for case 2
      idvalid = 1; // Control to exit from the loop *** Feedback ***
						// loopcount = SIZE;			// Minimize the number of the loop working. *** Feedback ***
					} else
					{
						valid = 1;					// Means Id of user input is not correct.
					}
				}
				if (valid == 1)
				{
					printf("*** ERROR: Employee ID not found! ***\n");
				}
			} while (valid);					    // Find the coreect index and remove that values

			break;

		// Explore non-optional values
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}
	} while (option != 0);

	return 0; 
}


// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 222
Enter Employee Age: 22
Enter Employee Salary: 22222.22

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 333
Enter Employee Age: 33
Enter Employee Salary: 33333.33

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 444
Enter Employee Age: 44
Enter Employee Salary: 44444.44

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 555
Enter Employee Age: 55
Enter Employee Salary: 55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   33333.33
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 123
*** ERROR: Employee ID not found! ***
Enter Employee ID: 321
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
The current salary is 33333.33
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   99999.99
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 789
*** ERROR: Employee ID not found! ***
Enter Employee ID: 987
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
Employee 333 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 666
Enter Employee Age: 66
Enter Employee Salary: 66666.66

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
666       66   66666.66
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
