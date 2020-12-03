#define _CRT_SECURE_NO_WARNINGS

#define MAX_CATEGORY 7
#define MIN_CATEGORY 1

#include <stdio.h>
#include <string.h>

#include "stock.h"

//--------------------------------
// Function Definitions
//--------------------------------

// Clear the standard input buffer
void clearKeyboard(void)
{
  {
    while (getchar() != '\n')
      ; // empty execution code block on purpose
  }
}

// Get and store from standard input the values for SalesRecord
int readStockItems(struct StockRecord stockRecord[], int max, int bonus)
{
  // Variables:
  int i;
  int categoryflag = 1, loopflag = 0;

  // Set up to receive the data from a user
  for (i = 0; i < max || loopflag == 1; i++)
  {
    // receiving data 
    scanf("%d,%d,%lf,%d,%30[^\n]", &stockRecord[i].salesRecord.amout,
          &stockRecord[i].salesRecord.category,
          &stockRecord[i].salesRecord.price,
          &stockRecord[i].salesRecord.byWeight,
          stockRecord[i].product);
    clearKeyboard();

    // Allowcate product ID
    stockRecord[i].productId = i;

    // Set up to check if a user want to stop or not
    if (stockRecord[i].salesRecord.amout == 0)
    {
      loopflag = 1;
    }
    else
    {
      // Set up to check if category value is valid or not
      while (categoryflag == 1)
      {
        if (stockRecord[i].salesRecord.category < MIN_CATEGORY || stockRecord[i].salesRecord.category > MAX_CATEGORY)
        {
          printf("Invalid Category - Enter a number between %d and %d: ", MAX_CATEGORY, MIN_CATEGORY);
          scanf("%d,%lf,%d,%30[^\n]", &stockRecord[i].salesRecord.category,
                &stockRecord[i].salesRecord.price,
                &stockRecord[i].salesRecord.byWeight,
                stockRecord[i].product);
          clearKeyboard();
        }
        else
        {
          // Allocate the 0 to exit from loop
          categoryflag = 0;
        }
      }

      // return value to enter into while loop
      categoryflag = 1;

      // Set up to check if byWeight value is valid or not
      while (categoryflag == 1)
      {
        if (stockRecord[i].salesRecord.byWeight < 0 || stockRecord[i].salesRecord.byWeight > 1)
        {
          printf("Invalid soldByWeight - Enter a number between 0 and 1: ");
          scanf("%d,%30[^\n]", &stockRecord[i].salesRecord.byWeight, stockRecord[i].product);
          clearKeyboard();
        }
        else
        {
          // Allocate the 0 to exit from loop
          categoryflag = 0;
        }
      }
    }
  }

  return i;
};

// Displying the title
void centreText(int num, char symbol, char* title)
{
  // Variables:
  int i;
  int starCount = (num - strlen(title)) / 2;

  // Set up to check if the length of title is 0 or not
  if (strlen(title) == 0)
  {
    // Displaying only symbol character
    for (i = 0; i < num; i++)
    {
      printf("%c", symbol);
    }
  }
  else
  {
    // Set up to count the symbol and title
    for (i = 0; i < num; i++)
    {
      if (i < starCount)
      {
        printf("%c", symbol);
      }
      else if (i < starCount + strlen(title))
      {
        printf(title);
        // Set up to move to next symbol slot
        i = starCount + strlen(title) - 1;
      }
      else
      {
        printf("%c", symbol);
      }
    }
  }
};

void printStockReport(const struct StockRecord* storeStock, int prodID)
{
  int i;

  for (i = 0; i < prodID; i++)
  {
    printf("  ID          Product    Category  Price Quantity");
    printf("%4d %30s %15d %7.2lf %8d", (i + 1), storeStock[i].product,
                                     &storeStock[i].salesRecord.category,
                                     &storeStock[i].salesRecord.price,
                                     &storeStock->salesRecord.amout);
  }
}
 