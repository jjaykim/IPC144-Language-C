//--------------------------------
// Structure Types
//--------------------------------

struct SalesRecord
{
  int amout;    // typically Amout
  int category; // typically Category
  double price; // typically Price
  int byWeight; // typically beWeight
};

struct StockRecord
{
  struct SalesRecord salesRecord; // struct of SalesRecord
  char product[30];               // Chocolate cup cakes -> 19 words so in advance...haha
  double productId;               // typically product ID
};

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

// Displaying the results of sale
double printSalesReport(const struct StockRecord storeStock[], struct SalesRecord saleItems[], int numSaleItems);

// Avoid negative value when subtracting the quantity
int getPositiveInt(struct StockRecord *storeStock, int validID, int inputQun);

// Calculating the total price with only valid quantity
double getTotalPrice(struct StockRecord *storeStock, int validID, int inputQun);

// Checking the valid product ID
int findValidID(const struct StockRecord storeStock[], int range, int inputID);

// initialization struct SalesRecord array
void initPrice(struct SalesRecord salesItems[], int range);


//
// void getTopSellers(const struct StockRecord* storeStock, int range, struct SalesRecord topSellers[], int rank, int cat);
