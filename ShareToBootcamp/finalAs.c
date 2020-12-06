//==============================================
// Group Member 1:
//		Name:           Jason Jun
//		Student Number: 126683200
//		Email:          jjun10@myseneca.ca
//		Section:        NNN
//		Date:           December 3, 2020
//==============================================
// Group Member 2:
//		Name:           Jungjoo Kim
//		Student Number: 162641195
//		Email:          jkim594@myseneca.ca
//		Section:        NNN
//		Date:           December 3, 2020
//==============================================
// Group Member 3:
//		Name:           Jiwon Choi
//		Student Number: 154292197
//		Email:          jchoi152@myseneca.ca
//		Section:        NNN
//		Date:           December 3, 2020
//==============================================
// Assignment:     Final Assessment
// Part:           4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#define MIN_CATEGORY 1
#define MAX_CATEGORY 7

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "finalAS.h"

// Clear the standard input buffer
void clearKeyboard(void)
{
  while (getchar() != '\n')
    ; // empty execution code block on purpose
}

// readStockItems:
int readStockItems(struct StockRecord stockRecord[], int maxEntry, int infoInProgram)
{

  // Variables:
  int i;
  int loopFlag = 0;
  //int whileFlag = 1;

  for (i = 0; !loopFlag && i < maxEntry;)
  {

    scanf("%d, %d, %lf, %d, %30[^\n]", &stockRecord[i].productStock.productAmount, &stockRecord[i].productStock.productCategory,
          &stockRecord[i].productStock.productPrice, &stockRecord[i].productStock.byWeight,
          stockRecord[i].productName);
    clearKeyboard();

    // Checking if user wants to end stocking
    if (stockRecord[i].productStock.productAmount == 0)
      loopFlag = 1;

    else
    {
      errorMessage(stockRecord, i, MIN_CATEGORY, MAX_CATEGORY);
      i++;
    }
  }
  return i;
}

// errorMessage
void errorMessage(struct StockRecord stockRecord[], int index, int min, int max)
{

  int whileFlag = 1;

  while (whileFlag)
  {
    if (stockRecord[index].productStock.productCategory < MIN_CATEGORY || stockRecord[index].productStock.productCategory > MAX_CATEGORY)
    {
      printf("Invalid Category - Enter a number between 1 and 7: ");
      scanf("%d,%lf,%d,%30[^\n]", &stockRecord[index].productStock.productCategory,
            &stockRecord[index].productStock.productPrice,
            &stockRecord[index].productStock.byWeight,
            stockRecord[index].productName);
      clearKeyboard();
    }

    else if (stockRecord[index].productStock.byWeight < 0 || stockRecord[index].productStock.byWeight > 1)
    {
      printf("Invalid soldByWeight - Enter a number between 0 and 1: ");
      scanf("%d,%30[^\n]", &stockRecord[index].productStock.byWeight,
            stockRecord[index].productName);
      clearKeyboard();
    }

    else
    {
      whileFlag = 0;
    }
  }
}

// centreText:
void centreText(int numCharacters, char symbol, char *centreMessage)
{

  // Variables:
  int i;
  int starSymbol = (numCharacters - strlen(centreMessage)) / 2;
  int messageFlag = starSymbol + strlen(centreMessage);

  if (strlen(centreMessage) == 0)
  {
    for (i = 0; i < numCharacters; i++)
    {
      printf("%c", symbol);
    }
  }
  else
  {
    for (i = 0; i < numCharacters; i++)
    {

      if (i < starSymbol)
        printf("%c", symbol);

      else if (i < (messageFlag - 2))
      {
        printf(centreMessage);
        i = messageFlag - 1;
      }
      else
        printf("%c", symbol);
    }
  }
}

// convertCategory
void convertCategory(int productCategory, char changeCategory[])
{

  switch (productCategory)
  {
  case 1:
    strcpy(changeCategory, "produce");
    break;

  case 2:
    strcpy(changeCategory, "bakery");
    break;

  case 3:
    strcpy(changeCategory, "meat");
    break;

  case 4:
    strcpy(changeCategory, "dairy");
    break;

  case 5:
    strcpy(changeCategory, "baking");
    break;

  case 6:
    strcpy(changeCategory, "house wares");
    break;

  case 7:
    strcpy(changeCategory, "miscellaneous");
    break;

  default:
    break;
  }
}

// printStockReport
void printStockReport(const struct StockRecord *stockRecord, int maxReport)
{

  // Variables:
  int i;
  char categoryName[30] = {'\0'};

  puts("  ID                        Product        Category   Price Quantity  ");
  for (i = 0; i < maxReport; i++)
  {

    char categoryName[30] = {'\0'};

    convertCategory(stockRecord[i].productStock.productCategory, categoryName);

    printf("%4d %30s %15s %7.2lf %8d\n", (i + 1), stockRecord[i].productName, categoryName,
           stockRecord[i].productStock.productPrice,
           stockRecord[i].productStock.productAmount);
  }
}

// readSale:
int readSale(struct StockRecord stockRecord[], int maxReport, struct SalesRecord salesRecord[])
{

  // Variable:
  int indexRecord;
  int i = 0;
  int whileFlag = 0;

  do
  {

    printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
    scanf("%d, %lf", &salesRecord[i].productID, &salesRecord[i].productSold);
    clearKeyboard();

    if (salesRecord[i].productID == 0)
      whileFlag = 1;

    else
    {
      // Function #1
      while (salesRecord[i].productID < 0 || salesRecord[i].productID > maxReport)
      {
        printf("Invalid Product - Enter a number between 0 and %d: ", maxReport);
        scanf("%d, %lf", &salesRecord[i].productID, &salesRecord[i].productSold);
        clearKeyboard();
      }

      while (salesRecord[i].productSold < 0.10 || salesRecord[i].productSold > 100)
      {
        printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
        scanf("%d, %lf", &salesRecord[i].productID, &salesRecord[i].productSold);
        clearKeyboard();
      }

      // Function #2
      indexRecord = salesRecord[i].productID - 1;

      if (stockRecord[indexRecord].productStock.productAmount < salesRecord[i].productSold)
      {
        stockRecord[indexRecord].amountSold = stockRecord[indexRecord].productStock.productAmount;
        stockRecord[indexRecord].productStock.productAmount = 0;
      }
      else
      {
        stockRecord[indexRecord].productStock.productAmount -= (int)(salesRecord[i].productSold);
        stockRecord[indexRecord].amountSold = salesRecord[i].productSold;
      }

      i++;
    }
  } while (!whileFlag);

  return i;
}

// printSalesReport:
double printSalesReport(struct StockRecord stockRecord[], struct SalesRecord salesRecord[], int saleItems)
{

  // Variable:
  int i, indexRecord;
  double tax = 0.0, purchaseTotal = 0.0, total = 0.0;
  double price = 0.0;

  // Making title of "Seneca Groceries"
  puts("");
  centreText(70, '*', " Seneca Groceries ");
  puts("");
  centreText(70, '=', "");
  puts("");

  for (i = 0; i < saleItems; i++)
  {
    indexRecord = salesRecord[i].productID - 1;
    price = stockRecord[indexRecord].productStock.productPrice * stockRecord[indexRecord].amountSold;

    printf("%30s %8.2lf %7.2lf\n", stockRecord[indexRecord].productName, stockRecord[indexRecord].productStock.productPrice, price);

    if (stockRecord[indexRecord].productStock.productCategory == 6 || stockRecord[indexRecord].productStock.productCategory == 7)
    {
      tax += price * 0.13;
    }

    purchaseTotal += price;
    total = purchaseTotal + tax;
  }

  printf("Purchase Total %32.2lf\n", purchaseTotal);
  printf("Tax %43.2lf\n", tax);
  printf("Total %41.2lf\n", total);
  puts("Thank you for shopping at Seneca!\n");
  return purchaseTotal;
}

// getTopSellers:
void getTopSellers(struct StockRecord stockRecord[], int maxReport, struct SalesRecord topSellers[], int topNumber, int cat)
{

  

  // Variables:
  int i;
  int j = 0;

  int first, second;
  double temp;

  struct SalesRecord topSeller[5] = {{0, 0.0}};

  for (i = 0; i < 3; i++)
  {

    printf("i value: %d\n", i);
    //printf("uservalue(%.2lf)\n\n", stockRecord[i].amountSold);

    if (stockRecord[i].productStock.productCategory == cat + 1)
    {

      printf("category: %d\n\n", stockRecord[i].productStock.productCategory);
      printf("topsellervalue %.2lf\n", topSellers[j].productSold);

      topSellers[j].productSold = stockRecord[i].amountSold;

      j++;
      printf("value(%d): %.2lf\n", j, topSellers[j].productSold);
    }
  }

  // Bubble Sorting (From largest to smallest)

  for (first = j - 1; first > 0; first--)
  {
    for (second = 0; second < first; second++)
    {
      if (topSellers[second].productSold > topSellers[second + 1].productSold)
      {
        temp = topSellers[second].productSold;
        topSellers[second].productSold = topSellers[second + 1].productSold;
        topSellers[second + 1].productSold = temp;
      }
    }
  }
}
/*for (index = (secondIndex - 1); index > 0; index--) {
        for (secondIndex = 0; j < secondIndex; j++) {
            if (topSeller[j].productSold > topSeller[j + 1].productSold) {
                temp = topSeller[j].productSold;
                topSeller[j].productSold = topSeller[j + 1].productSold;
                topSeller[j + 1].productSold = temp;
            }
        }
}*/

// printTopSellers:
void printTopSellers(const struct StockRecord stockRecord[], struct SalesRecord *topSellers, int topNumber, int cat)
{

  printf("Order: %.2lf\n", stockRecord[0].amountSold);

  printf("Order: %.2lf\n", topSellers[0].productSold);
  printf("Order: %.2lf\n", topSellers[1].productSold);
  printf("Order: %.2lf\n", topSellers[2].productSold);
}
