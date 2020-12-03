#define _CRT_SECURE_NO_WARNINGS

#define MAX_CATEGORY 7
#define MIN_CATEGORY 1

#include <stdio.h>

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
  int i;
  int categoryflag = 1;

  for (i = 0; i < max; i++)
  {
    scanf("%d,%d,%lf,%d,%s", &stockRecord[i].salesRecord.amout,
      &stockRecord[i].salesRecord.category,
      &stockRecord[i].salesRecord.price,
      &stockRecord[i].salesRecord.byWeight,
      stockRecord[i].product);

    while (categoryflag == 1)
    {
      if (stockRecord[i].salesRecord.category < MIN_CATEGORY || stockRecord[i].salesRecord.category > MAX_CATEGORY)
      {
        printf("Invalid Category - Enter a number between %d and %d:", MAX_CATEGORY, MIN_CATEGORY);
        scanf("%d,%lf,%d,%s", &stockRecord[i].salesRecord.category, &stockRecord[i].salesRecord.price,
          &stockRecord[i].salesRecord.byWeight, stockRecord[i].product);
      }
      else
      {
        categoryflag = 0;
      }
    }

    categoryflag = 1;

    while (categoryflag == 1)
    {
      if (stockRecord[i].salesRecord.byWeight < 0 || stockRecord[i].salesRecord.byWeight > 1)
      {
        printf("Invalid soldByWeight - Enter a number");
        scanf("%d,%s", &stockRecord[i].salesRecord.byWeight, stockRecord[i].product);
      }
      else
      {
        categoryflag = 0;
      }
    }
  }

  return 1;
};