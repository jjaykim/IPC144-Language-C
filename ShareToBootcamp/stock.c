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
    stockRecord[i].productId = i + 1;

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

// Change the Category name from integer to Character
void changeCate(int prodc, int prodID, char cate[])
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
void printStockReport(const struct StockRecord* storeStock, int lange)
{
  int i;
  char alpabetCate[30] = { '\0' };

  puts("  ID          Product    Category  Price Quantity");

  for (i = 0; i < lange; i++)
  {
    char alpabetCate[30] = { '\0' };

    changeCate(storeStock[i].salesRecord.category, i, alpabetCate);

    printf("%4d %17s %15s %7.2lf %-6d\n", (i + 1), storeStock[i].product, //  I didn't match the line yet,, haha
                                          alpabetCate,
                                          storeStock[i].salesRecord.price,
                                          storeStock[i].salesRecord.amout);
  }
}

/*
Calculating total price
int getTotalPrice(const struct StockRecord* storeStock, int lange, int inputID, int inputQun)
{
  // Variables:
  int i;
  int totalPrice;

  // Set up to find the matched product ID
  for (i = 0; i < lange; i++)
  {
    // I'm not sure should I chage the product ID type from double to int..? 
    if (storeStock[i].productId - inputID == 0)
    {
      totalPrice = storeStock[i].salesRecord.price * inputQun;
    }
  }

  return totalPrice;
}
*/

// Calculating the total price with only valid quantity
int getTotalPrice(const struct StockRecord *storeStock, int inputID, int inputQun)
{
  double totalPrice;

  // Set up to calculate the valid total prices
  if (storeStock[inputID].salesRecord.amout < inputQun)
  {
    totalPrice = storeStock[inputID].salesRecord.price * storeStock[inputID].salesRecord.amout;
  }
  else
  {
    totalPrice = storeStock[inputID].salesRecord.price * inputQun;
  }
  
  return totalPrice;
}

// Avoid negative value when subtracting the quantity
int getPositiveInt(const struct StockRecord* storeStock, int inputID, int inputQun)
{
  int convertNum;

  // Set up to make a zero value if quantity is less than zero
  if (storeStock[inputID].salesRecord.amout - inputQun < 0)
  {
    convertNum = (storeStock[inputID].salesRecord.amout - inputQun) * -1;
    convertNum += storeStock[inputID].salesRecord.amout - inputQun;
  }

  return convertNum;
}

// Receiving a product ID to purchase from a user
int readSale(struct StockRecord* storeStock, int lange, struct SalesRecord saleItems[])
{
  // Variables:
  int i;
  int inputID, inputQun;
  int loopFlag = 0;

  // Set up to receive the data from a user
  for (i = 0; i < lange || loopFlag == 1; i++)
  {
    printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
    scanf("%d,%d", inputID, inputQun);

    // Set up to check if a user want to exit or not
    if (inputID == 0)
    {
      loopFlag = 1;
    }
    else
    {
      // Set up to check if inputted product ID is valid or not
      while (inputID < 0 || inputID > lange)
      {
        printf("Invalid Product - Enter a number between 0 and &d: ", lange);
        scanf("%d,%d", inputID, inputQun);
      }

      // Set up to check if inputted product quntity is valid or not
      while (inputQun < 0.1 || inputQun > 100)  // I cannot figure out the meaning of 0.1 and 100
      {
        printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
        scanf("%d,%d", inputID, inputQun);
      }

      // Declear the total price
      saleItems[inputID].price = getTotalPrice(storeStock, inputID, inputQun);

      // Declear the valid quantity
      storeStock[inputID].salesRecord.amout = getPositiveInt(storeStock, inputID, inputQun);
    }
  }

  // Return the count of total sales
  return i + 1;
}

// Displaying the results of sale
int printSalesReport(const struct StockRecord* storeStock, struct SalesRecord saleItems[], int numSaleItems)
{
  // Variables:
  int i;
  double totalPurchase = 0.0, tax = 0.0, totalPrice = 0.0;
  
  puts("*********************** Seneca Groceries ***********************");
  puts("================================================================");

  // Set up to display the receipt
  for (i = 0; i < numSaleItems; i++)
  {
    // Set up to find the inputted product ID with price vlaue
    if (storeStock[i].salesRecord.price != saleItems[i].price)
    {
      printf("%16s %5.2lf %7.2lf\n", storeStock[i].product, &storeStock[i].salesRecord.price, &saleItems[i].price);
      
      // Set up to find if the value need to be calculated taxes
      if (storeStock[i].salesRecord.category == 6 || storeStock[i].salesRecord.category == 7)
      {
        tax = saleItems[i].price * 0.13;
      }
      
      totalPurchase += saleItems[i].price;
      tax += tax;
      totalPrice = totalPurchase + tax;

      printf("Purchase Total %8.2lf\n", totalPurchase);
      printf("Tax %8.2lf\n", tax);
      printf("Total %8.2lf\n", totalPrice);
      puts("Thank you for shopping at Seneca!\n");
    }
  }
}



// void getTopSellers(const struct StockRecord *storeStock, int lange, struct SalesRecord topSellers[], int rank, int cat)
// {
//   int i;
  
// }
