// Now, Testing weather there are any changes between Mac and Window
// Yessss, super great working now !!!!

// =====================================================================
//  C strings and string functions
//  November 30, 2020
// =====================================================================
// HOMEWORK:
//
// Create the below functions in the helper module that does the following:
//
// 3. Create a function that will WRITE or APPEND to a text file all the data of a
//    struct House type.  Use a pipe character '|' as a field delimiter.  The
//    function will return 1 for successful, and 0 for an error.
//    The function should display the # of successfully written room records.
//
//    Prototype:
//    int saveHouseData(const struct House* house, int roomArrSize, int isAppend);
//
//    NOTE:
//    If the "isAppend" value is 1, then append data to the file, otherwise,
//    recreate (overwrite) the file with new data
//
// ## DONE ###
//
// 4. Create a function that will READ from a text file all the data of a
//    struct House type.  Assume a pipe character '|' as a field delimiter.
//    The function will return 1 for success, 0 for error.
//    The function should display the # of successfully read room records.
//
//    Prototype:
//    int loadHouseData(const struct House* house, int roomArrSize);
//
//---------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>     // <-- system libraries/modules/resources
#include <stdlib.h>    // <-- rand() function
#include <time.h>

#include "residence3.h" // <-- user defined libraries/modules/resources

int main(void)
{
	// set random seed to unique value for this execution!
	// (default is set to 1)
	srand(time(NULL)); // time(NULL): returns current time in Millseconds

	// Residence module will control main application flow
	residenceStart();

	// How to show "special characters" using escape sequences: \ and %:
	//printf("Here's a double quote:\"\n"); // use backslash for showing a double quote " 
	//printf("Here's a double percent:%%\n"); // use extra percent for showing percent %
	//printf("Here's a backslash:\\\n");

    return 0;
}