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
  for (i = 0; i < max && !loopflag; i++)
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
      while (categoryflag)
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
      while (categoryflag)
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
  int titleflag = starCount + strlen(title);

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
      else if (i < titleflag - 2)
      {
        printf(title);
        // Set up to move to next symbol slot
        i = titleflag - 1;
      }
      else
      {
        printf("%c", symbol);
      }
    }
  }
};

// Change the Category name from integer to Character
void changeCate(int prodc, char cate[])
{
  switch (prodc)
  {
  case 1:
    strcpy(cate, "produce");
    break;

  case 2:
    strcpy(cate, "bakery");
    break;

  case 3:
    strcpy(cate, "meat");
    break;
  case 4:
    strcpy(cate, "dairy");
    break;
  case 5:
    strcpy(cate, "baking");
    break;
  case 6:
    strcpy(cate, "house wares");
    break;
  case 7:
    strcpy(cate, "miscellaneous");
    break;

  default:
    break;
  }
};

// Displaying inventory status
void printStockReport(const struct StockRecord* storeStock, int range)
{
  int i;
  char alpabetCate[30] = { '\0' };

  puts("  ID          Product    Category  Price Quantity");

  for (i = 0; i < range; i++)
  {
    char alpabetCate[30] = { '\0' };

    changeCate(storeStock[i].salesRecord.category, alpabetCate);

    printf("%4d %17s %15s %7.2lf %-6d\n", (i + 1), storeStock[i].product, //  I didn't match the line yet,, haha
                                          alpabetCate,
                                          storeStock[i].salesRecord.price,
                                          storeStock[i].salesRecord.amout);
  }
}

// Checking the valid product ID
int findValidID(const struct StockRecord storeStock[], int range, int inputID)
{
  int i = 0;
  int loopflag = 1;

  while (loopflag)
  {
    if (inputID - storeStock[i].productId == 1)
    {
      loopflag = 0;
    }
    else
    {
      i++;
    }
  }

  return i;
}

// Calculating the total price with only valid quantity
int getTotalPrice(struct StockRecord *storeStock, int validID, int inputQun)
{
  double totalPrice = 0.0;

  // Set up to calculate the valid total prices
  if (storeStock[validID].salesRecord.amout < inputQun)
  {
    totalPrice = storeStock[validID].salesRecord.price * storeStock[validID].salesRecord.amout;
  }
  else
  {
    totalPrice = storeStock[validID].salesRecord.price * inputQun;
  }
  
  return totalPrice;
}

// Avoid negative value when subtracting the quantity
int getPositiveInt(struct StockRecord* storeStock, int validID, int inputQun)
{
  int convertNum = 0;

  // Set up to make a zero value if quantity is less than zero
  if (storeStock[validID].salesRecord.amout - inputQun < 0)
  {
    convertNum = 0;
  }
  else
  {
    convertNum = storeStock[validID].salesRecord.amout - inputQun;
  }

  return convertNum;
}

// initialization struct SalesRecord array
void initPrice(struct SalesRecord salesItems[], int range)
{
  int i;

  for (i = 0; i < range; i++)
  {
    salesItems[i].price = 0.0;
  }
}

// Receiving a product ID to purchase from a user
int readSale(struct StockRecord storeStock[], int range, struct SalesRecord saleItems[])
{
  // Variables:
  int i = 0, validID;
  int inputID, inputQun;
  int loopFlag = 1;

  initPrice(saleItems, range);

  // Set up to receive the data from a user
  do
  {
    printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
    scanf("%d,%d", inputID, inputQun);

    // Set up to check if a user want to exit or not
    if (inputID == 0)
    {
      loopFlag = 0;
    }
    else
    {
      // Set up to check if inputted product ID is valid or not
      while (inputID < 0 || inputID > range)
      {
        printf("Invalid Product - Enter a number between 0 and &d: ", range);
        scanf("%d,%d", &inputID, &inputQun);
      }

      // Set up to check if inputted product quntity is valid or not
      while (inputQun < 0.1 || inputQun > 100)  // I cannot figure out the meaning of 0.1 and 100
      {
        printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
        scanf("%d,%d", &inputID, &inputQun);
      }

      // Finding the valid ID
      validID = findValidID(storeStock, range, inputID);

      // Declear the total price
      saleItems[validID].price = getTotalPrice(storeStock, validID, inputQun);

      // Declear the valid quantity
      storeStock[validID].salesRecord.amout = getPositiveInt(storeStock, validID, inputQun);

      i++;
    }
  } while (loopFlag);

  // Return the count of total sales
  return i;
}

// Displaying the results of sale
double printSalesReport(const struct StockRecord storeStock[], struct SalesRecord saleItems[], int numSaleItems)
{
  // Variables:
  int i = 0, j = 0;
  double totalPurchase = 0.0, tax = 0.0, totalPrice = 0.0;
  
  puts("*********************** Seneca Groceries ***********************");
  puts("================================================================");

  // Set up to display the receipt
  while (i < numSaleItems)
  {
    // Set up to find the inputted product ID with price vlaue
    if (saleItems[j].price > 0)
    {
      printf("%16s %5.2lf %7.2lf\n", storeStock[j].product, storeStock[j].salesRecord.price, saleItems[j].price);

      // Set up to find if the value need to be calculated taxes
      if (storeStock[j].salesRecord.category == 6 || storeStock[j].salesRecord.category == 7)
      {
        tax += (saleItems[j].price * 0.13);
      }

      totalPurchase += saleItems[j].price;
      totalPrice = totalPurchase + tax;

      i++;
      j++;
    }
    else
    {
      j++;
    }
  }

  printf("Purchase Total %8.2lf\n", totalPurchase);
  printf("Tax %8.2lf\n", tax);
  printf("Total %8.2lf\n", totalPrice);
  puts("Thank you for shopping at Seneca!\n");

  return totalPrice - tax;
}

// void getTopSellers(const struct StockRecord *storeStock, int range, struct SalesRecord topSellers[], int rank, int cat)
// {
//   int i;
  
// }
