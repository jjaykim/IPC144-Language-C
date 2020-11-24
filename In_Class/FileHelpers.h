// 23.11.2020

//
// FileHelpers Module/Library
// ==========================
// - file specific functions for saving and loading Residence related data
//

#include "residence3.h" // for using the struct of House

// House data file (physical file name)
#define FILE_DATA "houseData.dat"

// Save house data to file (optional to append based on isAppend)
int saveHouseData(const struct House* house, int roomArrSize, int isAppend);  // Append: Adding to the end

