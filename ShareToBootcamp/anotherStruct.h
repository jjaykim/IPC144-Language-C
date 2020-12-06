#define MAX_ITEMS_IN_SALE 14 // The total number of Items is 14 
#define NUM_CATS 7           // Total 2 times diplay Top 2 rank!

//--------------------------------
// Structure Types
//--------------------------------

// Structure type productStock declaration
struct ProductStock
{
  int productAmount;   // Amount of product in the beginning
  int productCategory; // Category a product belongs in
  double productPrice; // Price of a product
  int byWeight;         // 0 or 1 depending how a product is sold
};

// Structure type StockRecord declaration
struct StockRecord
{
  struct ProductStock productStock;
  char productName[30];   // Name of a product
  double amountSold;      // How many products are bought by the user
};

// Structure type SalesRecord declaration
struct SalesRecord
{
  int productID;   // ID of a product
  double productSold; // How many of a product is sold
};

//--------------------------------
// FUNCTIONS: PROTOTYPES
//--------------------------------

// Clear the standard input buffer
void clearKeyboard(void);

// Get and store from standard input the values for SalesRecord
int readStockItems(struct StockRecord stockRecord[], int max, int bonus);

// Displying the title
void centreText(int num, char symbol, char *title);

// Displaying inventory status
void printStockReport(const struct StockRecord* storeStock, int range);

// Change the Category name form integer to Character
void changeCate(int prodc, char cate[]);

// Receiving a product ID to purchase from a user
int readSale(struct StockRecord* storeStock, int range, struct SalesRecord saleItems[]);

// Checking the valid product ID
int findValidID(int inputID);

// Avoid negative value when subtracting the quantity
int getPositiveInt(struct StockRecord* storeStock, int validID, int inputQun);

// Finding an empty slot
int findEmptySpace(struct SalesRecord saleItems[]);

// Displaying the results of sale
double printSalesReport(struct StockRecord storeStock[], struct SalesRecord saleItems[], int numSaleItems);

// Sorting
void getTopSellers(struct StockRecord storeStock[], int range, struct SalesRecord topSellers[], int topCount, int category);
