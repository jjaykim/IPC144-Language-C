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

// Creat to check the value is valid or not
// void getValidvalue(const char* cateErrMsg, const char* byWeightErrMsg, const struct StockRecord stockRecord[], int num);


// centreText(70, '*', " Seneca Groceries - Opening Stock ");

// printStockReport(storeStock, numStockItems);
