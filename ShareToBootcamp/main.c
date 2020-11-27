#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contactHelpers.h"
#include "contacts.h"



int main(void)
{
  int needInput = 1;
  char phoneNum[] = { 0 };
  int i, valid;

  while (needInput == 1)
  {
    valid = 0;

    printf("enter the number");
    scanf("%s", phoneNum);
    clearKeyboard();

    // (String Length Function: validate entry of 10 characters)
    for (i = 0; i < 10; i++)
    {
      if (!isdigit(phoneNum[i]))
      {
        valid++;
      }
    }

    if (strlen(phoneNum) == 10 && valid == 0)
    {
        needInput = 0;
    }
    else
    {
      printf("Enter a 10-digit phone number: ");
    }
  }
    printf("the number is %s", phoneNum);

  return 0;
}