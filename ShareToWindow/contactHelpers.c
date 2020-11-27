//==============================================
// Name:           Jungjoo Kim
// Student Number: 162  641 195
// Email:          jkim594@myseneca.ca
// Section:        NNN
// Date:           2020. 11. 28
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"

// clearKeyboard:  Empty function definition
void clearKeyboard(void)
{
  {
    while (getchar() != '\n')
      ; // empty execution code block on purpose
  }
}

// pause: Empty function definition goes here:
void pause(void)
{
  printf("(Press Enter to Continue)");
  clearKeyboard();
}

// getInt: Empty function definition goes here:
int getInt(void)
{
  int validInt;
  char invalidChar = 'x'; // Declaration to enter the condition of while loop

  while (invalidChar != '\n')
  {
    scanf("%d%c", &validInt, &invalidChar); // Receive only the integer value from the user
    if (invalidChar != '\n')                // Check the second character is a new line or not
    {
      clearKeyboard();
      printf("*** INVALID INTEGER *** <Please enter an integer>: ");
    }
  }
  return validInt;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
  int validRange = getInt();

  while (validRange < min || validRange > max)
  {
    printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
    validRange = getInt();
  }
  return validRange;
}

// yes: Empty function definition goes here:
int yes(void)
{
  int validYes = 0; // 0 means "NO"
  char validChar, newlineChar;

  do
  {
    scanf("%c%c", &validChar, &newlineChar);
    // if statement assess only if the first value is one of the 4 valid characters.
    if (newlineChar != '\n' || (validChar != 'Y' && validChar != 'y' && validChar != 'N' && validChar != 'n'))
    {
      if (newlineChar != '\n') // Set up to erase the new line in the second value
      {
        clearKeyboard();
      }

      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
    }
    else if (validChar == 'Y' || validChar == 'y')
    {
      validYes = 1; // 1 menas "YES"
    }
  } while (newlineChar != '\n' || (validChar != 'Y' && validChar != 'y' && validChar != 'N' && validChar != 'n'));

  return validYes;
}

// menu: Empty function definition goes here:
int menu(void)
{
  puts("Contact Management System");
  puts("-------------------------");
  puts("1. Display contacts");
  puts("2. Add a contact");
  puts("3. Update a contact");
  puts("4. Delete a contact");
  puts("5. Search contacts by cell phone number");
  puts("6. Sort contacts by cell phone number");
  puts("0. Exit");
  puts("");
  printf("Select an option:> ");
  return getIntInRange(0, 6);
}

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
  int valid = 0; 

  do
  {
    switch (menu()) 
    {
    case 0:
      puts("");
      printf("Exit the program? (Y)es/(N)o: ");
      valid = yes();
      puts("");
      break;

    case 1:
      puts("");
      puts("<<< Feature 1 is unavailable >>>\n");
      pause();
      puts("");
      break;

    case 2:
      puts("");
      puts("<<< Feature 2 is unavailable >>>\n");
      pause();
      puts("");
      break;

    case 3:
      puts("");
      puts("<<< Feature 3 is unavailable >>>\n");
      pause();
      puts("");
      break;

    case 4:
      puts("");
      puts("<<< Feature 4 is unavailable >>>\n");
      pause();
      puts("");
      break;

    case 5:
      puts("");
      puts("<<< Feature 5 is unavailable >>>\n");
      pause();
      puts("");
      break;

    case 6:
      puts("");
      puts("<<< Feature 6 is unavailable >>>\n");
      pause();
      puts("");
      break;

    default:
      break;
    }
  } while (valid != 1);

  puts("Contact Management System: terminated");
}

//--------------------------------
// Personal Function
// Creat to check valid and positive integer at one time
//--------------------------------

int getPositiveInt(const char *errrMsg)
{
  int validInt = getInt();

  while (validInt < 0) // Verify that the integer value entered is positive
  {
    printf(errrMsg);
    validInt = getInt();
  }

  return validInt;
}

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;

    while (needInput == 1) 
    {
        scanf("%10[0-9]s", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
        {
            needInput = 0;
        }
        else
        {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    return -1;
}


// displayContactHeader
// Put empty function definition below:



// displayContactFooter
// Put empty function definition below:



// displayContact:
// Put empty function definition below:



// displayContacts:
// Put empty function definition below:



// searchContacts:
// Put empty function definition below:



// addContact:
// Put empty function definition below:



// updateContact:
// Put empty function definition below:



// deleteContact:
// Put empty function definition below:



// sortContacts:
// Put empty function definition below:
