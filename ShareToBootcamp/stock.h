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
  char product[30]; // Chocolate cup cakes -> 19 words so in advance...haha
  double idk;
};

// Get and store from standard input the values for SalesRecord
void getSalesRecord(struct SalesRecord* salesRecord);