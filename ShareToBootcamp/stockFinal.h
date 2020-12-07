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
//		Name:           
//		Student Number: 
//		Email:          
//		Section:        NNN
//		Date:           December 3, 2020
//==============================================
// Assignment:     Final Assessment
// Part:           4
//==============================================

#define MAX_ITEMS_IN_SALE 14 // The total number of Items is 14 
#define NUM_CATS 7           // The total number of Category is 7

// Structure type productStock declaration
struct productStock {
	int productAmount;    // Amount of product in the beginning
	int productCategory;  // Category a product belongs in
	double productPrice;  // Price of a product
	int byWeight;          // 0 or 1 depending how a product is sold 
};

// Structure type StockRecord declaration
struct StockRecord {
	struct productStock productStock;    // Struct of productStock
	char productName[30];                // Name of a product 
	double amountSold;                   // How many products are bought by the user
};

// Structure type SalesRecord declaration 
struct SalesRecord {
	int productID;	    // ID of a product
	double productSold; // How many of a product is sold
	char productName[30];    // Name of the product sold
};


//--------------------------------
// Function Prototypes
//--------------------------------

// clearKeyboard:
void clearKeyboard(void); // DONE

// readStockItems:
int readStockItems(struct StockRecord stockRecord[], int maxEntry, int infoInProgram); // DONE

//errorMessage
void errorMessage(struct StockRecord stockRecord[], int index, int min, int max); // DONE

// centreText:
void centreText(int numCharacters, char symbol, char* centreMessage); // DONE

// convertCategory
void convertCategory(int productCategory, char changeCategory[]); // DONE

// printStockReport:
void printStockReport(const struct StockRecord* stockRecord, int maxReport); // DONE

// readSale:
int readSale(struct StockRecord StockRecord[], int maxReport, struct SalesRecord SalesRecord[]); // DONE

// printSalesReport:
double printSalesReport(struct StockRecord stockRecord[], struct SalesRecord salesRecord[], int saleItems); // DONE

// getTopSellers:
void getTopSellers(struct StockRecord stockRecord[], int maxReport, struct SalesRecord topSellers[], int topNumber, int cat);

// printTopSellers:
void printTopSellers(const struct StockRecord stockRecord[], struct SalesRecord topSellers[], int topNumber, int cat);


