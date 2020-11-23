// 23.11.2020


// -----------------------------------------
// helper function for getting input:
// -----------------------------------------

// Clear the input buffer: prepare it for the next user input
void clearBuffer(void);

// Create a random integer between min and max (inclusive)
int randomInteger(int min, int max);

// total/sum of all characters in all the rooms that have data in
// the provided array of rooms
// -then display the sum/total: "total characters in room names: %d"
void displayTotalRoomChars(struct Room rooms[], int arrSize);
// void displayTotalRoomChars(struct Room* room, int arrSize);

// prompt user for a c string...
// copy that value entered, and replace ALL room names with that new value
void changeRoomNamesToSame(struct Room rooms[], int arrSize);

// Prompt user for a room name and search the data for match
// Display the found room if it was found
void searchRoom(struct Room rooms[], int arrSize);

// Add (append) to the end of all room names "(test)" and display all results
void appendRoomName(struct Room rooms[], int arrSize);

// 3. Summarize all the uppercase, lowercase, spaces, and numbers in all room names:
// 
//    Example output: 
//
//    Character Summary
//    --------------------------
//    UPPERCASE letters: 5
//    lowercase letters: 25
//    spaces           : 6
//    numbers          : 0
void characterSummary(struct Room rooms[], int arrSize);

// 23.11.2020 ADD ***
// Modify all room names to be uppercase characters
void roomNamesToUppercase(struct Room rooms[], int arrSize);

// another helper function to "help" with changing to UPPERCASE
void strToUpper(char* str);