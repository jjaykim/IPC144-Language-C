// **********************************
//        USING GROUP Struct
// **********************************

#define _CRT_SECURE_NO_WARNINGS

#define MAX_CATEGORY 7
#define MIN_CATEGORY 1

#include <stdio.h>
#include <string.h>

#include "anotherStruct.h"

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
  for (i = 0; i < max && !loopflag;)
  {
    // receiving data
    scanf("%d,%d,%lf,%d,%30[^\n]", &stockRecord[i].productStock.productAmount,
                                   &stockRecord[i].productStock.productCategory,
                                   &stockRecord[i].productStock.productPrice,
                                   &stockRecord[i].productStock.byWeight,
                                   stockRecord[i].productName);

    clearKeyboard();

    // Set up to check if a user want to stop or not
    if (stockRecord[i].productStock.productAmount < 1)
    {
      loopflag = 1;
    }
    else
    {
      // Set up to check if category value is valid or not
      while (categoryflag)
      {
        if (stockRecord[i].productStock.productCategory < MIN_CATEGORY || stockRecord[i].productStock.productCategory > MAX_CATEGORY)
        {
          printf("Invalid Category - Enter a number between %d and %d: ", MAX_CATEGORY, MIN_CATEGORY);
          scanf("%d,%lf,%d,%30[^\n]", &stockRecord[i].productStock.productCategory,
                                      &stockRecord[i].productStock.productPrice,
                                      &stockRecord[i].productStock.byWeight,
                                      stockRecord[i].productName);
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
        if (stockRecord[i].productStock.byWeight < 0 || stockRecord[i].productStock.byWeight > 1)
        {
          printf("Invalid soldByWeight - Enter a number between 0 and 1: ");
          scanf("%d,%30[^\n]", &stockRecord[i].productStock.byWeight, stockRecord[i].productName);
          clearKeyboard();
        }
        else
        {
          // Allocate the 0 to exit from loop
          categoryflag = 0;
        }
      }

      i++;
    }
  }

  return i;
}

// Displying the title
void centreText(int num, char symbol, char *title)
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
}

// Change the Category name form integer to Character
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
}

// Displaying inventory status
void printStockReport(const struct StockRecord* storeStock, int range)
{
  int i;
  char alpabetCate;

  puts("  ID                        Product        Category   Price Quantity  ");

  for (i = 0; i < range; i++)
  {
    char alpabetCate[30] = {'\0'};

    changeCate(storeStock[i].productStock.productCategory, alpabetCate);

    //  I didn't match the line yet,, haha
    printf("%4d %30s %15s %7.2lf %8d\n", (i + 1),
                                         storeStock[i].productName,
                                         alpabetCate,
                                         storeStock[i].productStock.productPrice,
                                         storeStock[i].productStock.productAmount);
  }
}
// 잠깐 밑으로 옮김
// // Checking the valid product ID
// int findValidID(int inputID)
// {
//   int i = inputID - 1;
//    return i;
// }

// Avoid negative value when subtracting the quantity
int getPositiveInt(struct StockRecord* storeStock, int validID, int inputQun)
{
  int convertNum;

  // Set up to make a zero value if quantity is less than zero
  if (storeStock[validID].productStock.productAmount - inputQun < 0)
  {
    convertNum = 0;
  }
  else
  {
    convertNum = storeStock[validID].productStock.productAmount - inputQun;
  }

  return convertNum;
}

/*
// Finding an empty slot
int findEmptySpace(struct SalesRecord saleItems[])
{
  int valid = 0, whileFlag = 1;
  
  while(valid)
  {
    if (saleItems[valid].productID < 0)
    {
      whileFlag = 0;
    }
    else
    {
      valid++;
    }
  }

  return valid;
}
*/

 // Receiving a product ID to purchase from a user
int readSale(struct StockRecord* storeStock, int range, struct SalesRecord saleItems[])
{
  // Variables:
  // int i = 0, validID;
  int i = 0;

  int loopFlag = 0;

  // Set up to receive the data from a user
  do
  {
    printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
    scanf("%d,%lf", &saleItems[i].productID, &saleItems[i].productSold);

    // Set up to check if a user want to exit or not
    if (saleItems[i].productID == 0)
    {
      loopFlag = 1;
    }
    else
    {
      // Set up to check if inputted product ID is valid or not
      while (saleItems[i].productID < 0 || saleItems[i].productID > range)
      {
        printf("Invalid Product - Enter a number between 0 and %d: ", range);
        scanf("%d,%lf", &saleItems[i].productID, &saleItems[i].productSold);
      }

      // Set up to check if inputted product quntity is valid or not
      while (saleItems[i].productSold < 0.10 || saleItems[i].productSold > 100) // I cannot figure out the meaning of 0.1 and 100
      {
        printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
        scanf("%d,%lf", &saleItems[i].productID, &saleItems[i].productSold);
      }

      // print functiond에서 한번에 하려고 옮겨봄
      // // Finding the valid ID
      // validID = findValidID(saleItems[i].productID);

      // // Overwrite
      // storeStock[validID].productStock.productAmount = getPositiveInt(storeStock, validID, saleItems[i].productID);

      i++;
    }
  } while (!loopFlag);

  // Return the count of total sales
  return i;
}

// To determine the exact quantity that users can buy
int getValidQuntity(struct StockRecord storeStock[], struct SalesRecord saleItems[], int validAmount, int inputAmount)
{
  int validQuntity = 0;

  if (storeStock[validAmount].productStock.productAmount < saleItems[inputAmount].productSold)
  {
    validQuntity = storeStock[validAmount].productStock.productAmount;
  }
  else
  {
    validQuntity = saleItems[inputAmount].productSold;
  }
  
  return validQuntity;  
}

// Checking the valid product ID
int findValidID(int inputID)
{
  int i = inputID - 1;
  return i;
}

// Displaying the results of sale
double printSalesReport(struct StockRecord storeStock[], struct SalesRecord saleItems[], int numSaleItems)
{
  // Variables:
  int i = 0;
  int valid = 0;
  double salesTotal = 0.0, totalPurchase = 0.0, tax = 0.0, totalPrice = 0.0;

  centreText(70, '*', " Seneca Groceries ");
  puts("");
  centreText(70, '=', "");
  puts("");
  // Finding the valid ID
  valid = findValidID(saleItems[i].productID);

  // Overwrite
  storeStock[valid].productStock.productAmount = getPositiveInt(storeStock, valid, saleItems[i].productID);

      // Set up to display the receipt
      while (i < numSaleItems)
  {
    valid = saleItems[i].productID - 1;
    saleItems[i].productSold = getValidQuntity(storeStock, saleItems, valid, i);
    salesTotal = (storeStock[valid].productStock.productPrice * saleItems[i].productSold);

    printf("%16s %5.2lf %7.2lf\n", storeStock[valid].productName, storeStock[valid].productStock.productPrice, salesTotal);

    // Set up to find if the value need to be calculated taxes
    if (storeStock[valid].productStock.productCategory == 6 || storeStock[valid].productStock.productCategory == 7)
    {
      tax += (salesTotal * 0.13);
    }

    totalPurchase += salesTotal;
    totalPrice = totalPurchase + tax;

    i++;
  }
  
  printf("Purchase Total %8.2lf\n", totalPurchase);
  printf("Tax %8.2lf\n", tax);
  printf("Total %8.2lf\n", totalPrice);
  puts("Thank you for shopping at Seneca!\n");

  return totalPrice - tax;
}

// Sorting
// void getTopSellers(struct StockRecord storeStock[], int range, struct SalesRecord topSellers[], int topCount, int arrayvalue)
// {
//   int i, j;
  
//   }
