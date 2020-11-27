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

// +-----------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2     |
// |        function definitions below...                |
// |                                                     |
// | HINT:  Update the getNumbers function to use the    |
// |        new helper function "getTenDigitPhone"       |
// |        where applicable                             |
// +-----------------------------------------------------+

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// getName:
void getName(struct Name *name)
{
  printf("Please enter the contact's first name: ");
  scanf("%30[^\n]", name->firstName);
  clearKeyboard();

  printf("Do you want to enter a middle initial(s)? (y or n): ");
  if (yes() == 1) 
  {
    printf("Please enter the contact's middle initial(s): ");
    scanf("%6[^\n]", name->middleInitial);
    clearKeyboard();
  }
  else
  {
    name->lastName[0] = '\0'; // Set up to maintain no value
  }

  printf("Please enter the contact's last name: ");
  scanf("%35[^\n]", name->lastName);
  clearKeyboard();
}

// getAddress:
void getAddress(struct Address *address)
{
  printf("Please enter the contact's street number: ");
  address->streetNumber = getPositiveInt("*** INVALID STREET NUMBER *** <must be a positive number>: ");

  printf("Please enter the contact's street name: ");
  scanf("%40[^\n]", address->street);
  clearKeyboard();

  printf("Do you want to enter an apartment number? (y or n): ");
  if (yes() == 1)
  {
    printf("Please enter the contact's apartment number: ");
    address->apartmentNumber = getPositiveInt("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
  }

  printf("Please enter the contact's postal code: ");
  scanf("%7[^\n]", address->postalCode);
  clearKeyboard();

  printf("Please enter the contact's city: ");
  scanf("%40[^\n]", address->city);
  clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers *numbers)
{
  printf("Please enter the contact's cell phone number: ");
  getTenDigitPhone(numbers->cell);

  printf("Do you want to enter a home phone number? (y or n): ");
  if (yes() == 1) 
  {
    printf("Please enter the contact's home phone number: ");
    getTenDigitPhone(numbers->home);
  }
  else
  {
    numbers->home[0] = '\0';  // Set up to maintain no value
  }

  printf("Do you want to enter a business phone number? (y or n): ");
  if (yes() == 1) 
  {
    printf("Please enter the contact's business phone number: ");
    getTenDigitPhone(numbers->business);
  }
  else
  {
    numbers->business[0] = '\0';  // Set up to maintain no value

  }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact *contact)
{
  getName(&contact->name);
  getAddress(&contact->address);
  getNumbers(&contact->numbers);
}
