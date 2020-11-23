// 23.11.2020
// -----------------------------------------
// helper function for getting input:
// -----------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>  // <=== string functions
#include <ctype.h>   // <=== character analysis + manipulation functions

#include "helper3.h"  // header file!
#include "residence3.h"

// Clear the input buffer: prepare it for the next user input
void clearBuffer(void)
{
 // we want to "eat" / "discard" extra characters
 // in the input buffer
 // loop the "buffer" until we get to a newline '\n'
 while (getchar() != '\n')
 {
  ; // do nothing... keep eating/discarding!
 }
}

// Create a random integer between min and max (inclusive)
int randomInteger(int min, int max)
{
	// seed: by default is set to 1
	// srand(2);
	return rand() % (max - min + 1) + min;
}

// total/sum of all characters in all the rooms that have data in
// the provided array of rooms
// -then display the sum/total: "total characters in room names: %d"
void displayTotalRoomChars(struct Room rooms[], int arrSize)
{
  int i, charCount = 0;

  // 1.0: Loop the rooms array
  for( i = 0; i < arrSize; i++)
  {
    // 1.1: Only cheeck "valid" records (that have names...):
    // or : if( strlen(rooms[i].name) == 0) // less performant
    if(rooms[i].name[0] != '\0')
    {
      // 1.2: loop each element in name char array and count it nutil
      //      \0 null terminator is founder
      //         ::OR::
      // 1.2: call string function "strlen()"
      // 1.3: sum the # of characters to a variable
      charCount += strlen(rooms[i].name);
      // 1.4: continue looping until no more rooms...(return to 1.0)
    }

    // 2.0: Display results (# of chars counted):
    printf("Total characters in room names: % d\n\n", charCount);
  }
}

  // prompt user for a c string...
  // copy that value entered, and replace ALL room names that have a name with that new value
  void changeRoomNamesToSame(struct Room rooms[], int arrSize)
  {
    // variables: 
    int i;
    char newName[NAME_SIZE + 1] = { 0 };
    char inputFmt[99999] = { 0 };

    // 1.0: prompt for a c string from user (display, and get as input)
    puts(""); // quick way to add a newline (puts displays a cstring with a newline)
    printf("Enter the new room name: ");
    
    // printf("Here is a double quote: \" \n");   // when I want to print out double quote, usind \"
    // printf("Here is a double percent: %% \n"); // when I want to print out percent, usind %%
    sprintf(inputFmt, "%%%d[^\n]", NAME_SIZE);
    // scanf("%100[^\n]", newName); // <== dynamically created using sprintf above!
    scanf(inputFmt, newName);

    // 2.0: Loop each room
    for ( i = 0; i < arrSize; i++)
    {
      // 2.1: check for existing value
      if(rooms[i].name[0] != '\0')
      {
        // 2.2: copy new name (change/modify/overwrite)
        // 2 arguments... one will represent the new value and the other will be
        //                the "estiantion" (where it gets copied)
        strcpy(rooms[i].name, newName);
      }
      // 2.3: return to 2.0
    }
  }

// Prompt user for a room name and search the data for match
// Display the found room if it was found
void searchRoom(struct Room rooms[], int arrSize)
{
  // variables:
  int i, found = 0;
  char roomName[NAME_SIZE + 1] = { '\0' };

  // prompt for user input (enter a room name) NOTE: case sensitive
  printf("Enter the room name to search for: ");

  // Get user input (store to c string array)
  scanf("%100[^\n]", roomName);

  // loop the rooms array until (if) a match is found
  for (i = 0, found = 0; i < arrSize && !found; i++)

    // compare the current room name to the user input value
    // rooms[i].name -> comapre with: "roomName"
    // strcmp: returns 0 when exactly the same  <=== behaves the same on all platforms
    //         returns -1 arg1 "abc" arg2 "add" <=== gurantee's negative value (cuz c < d) but can be less than -1 on other platforms
    //         returns 1 arg1 "ace" arg2 "acd"  <=== hurantee's positive value (cuz e > d) but can be less than -1 on other platforms

    if (strcmp(roomName, rooms[i].name) == 0)
    {
      // if a match is found: display it, and exit loop
      puts("");
      puts("Roon found!\n");
      displayRoomInfo(&rooms[i]);
      found = 1;
    }
  
  // if not match was found; display not found message
  if (!found)
  {
    puts("");  // better than printf("\n"); for insert the new line
    puts("Not Match found!   Try again!!\n");
  }
}

// Add (append) to the end of all room names "(test)" and display all results
void appendRoomName(struct Room rooms[], int arrSize)
{
  // variables:
  int i;

  // loop room array
  for (i = 0; i < arrSize; i++)
  {
    // if it's a valid record; append "(test)" to the room name
    // use room name to se if there is data...
    // if ( strlen(rooms[i].name) > 0)  // <=== also possable but too much working...
    if ( rooms[i].name[0] != '\n')      // <=== best method 
    {
      // append "(test)" to room name:
      // strcat: concatenate(append/add to)
      strcat(rooms[i].name, "(test)");

    }
  }
}

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
void characterSummary(struct Room rooms[], int arrSize)
{
  // variables:
  int i, j;
  int sumUpper = 0, sumLower = 0, sumSpace = 0, sumNumber = 0;

  // loop all valid rooms (with a name)
  for (i = 0; i < arrSize; i++)
  {
    // check for valid room (has a name)
    if (rooms[i].name[0] != '\0')
    {
      // loop each character in the room name
      for (j = 0; rooms[i].name[j] != '\0'; j++ )
      {
        // check for UPPERCASE letter and tabulate(sum):
        // returns: non-zero if it is upeercase otherwise 0
        // sumUpper += isupper(rooms[i].name[j]) ? 1 : 0;
        if(isupper(rooms[i].name[j]))
        {
          sumUpper++;
        }

        // check for lowercase letter and tabulate(sum):
        if(islower(rooms[i].name[j]))
        {
          sumLower++;
        }

        // check for space character and tabulate(sum):
        if(isspace(rooms[i].name[j]))
        {
          sumSpace++;
        }

        // check for number caaracterand tabulate(sum):
        if(isdigit(rooms[i].name[j]))
        {
          sumNumber++;
        }
      }
    }
  }

  // display results:
  puts("");
  puts("Character Summary");
  puts("--------------------------");
  printf("UPPERCASE letters: %3d\n", sumUpper);
  printf("lowercase letters: %3d\n", sumLower);
  printf("spaces           : %3d\n", sumSpace);
  printf("numbers          : %3d\n", sumNumber);
}