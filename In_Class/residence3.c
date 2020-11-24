// 23.11.2020

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>      // <--- system libraries/modules/resources
#include <stdlib.h>    // <-- "standard library"
#include <math.h>      // <-- needed for float abs functions labs()..

#include "residence3.h"  // <--- user defined libraries/modules/resources
#include "helper3.h"
#include "FileHelpers.h"


// -----------------------------------------
// Function definitions

//Display details about a Room Type
void displayRoomInfo(struct Room* room) // pointer! (uses address to access values)
{
	// ------------------- --------- --------- ---------
	// Kitchen                  10.5      12.2       8.0

	// printf("%s (%.2lf x %.2lf x %.2lf)\n", room->name, room->x, room->y, room->z);
	printf("%-19s %9.1lf %9.1lf %9.1lf\n", room->name, room->x, room->z, room->y);

}

// Display details about a house (including rooms)
void displayHouseInfo(struct House* house)
{
	int i;

	// display house info location:
	// printf("%d %s (%s)\n", house->houseNumber, house->streetName, house->city);
	printf("Address: %d %s, %s\n", house->houseNumber, house->streetName, house->city);
  
  // display tabular column headers:
	// Room Name           Width     Length    Height
	// ------------------- --------- --------- ---------
	printf("%-19s %-9s %-9s %-9s\n", "Room Name", "Width", "Length", "Height" );
	printf("%-19s %-9s %-9s %-9s\n", "-------------------",	"---------", "---------", "---------");

	for (i = 0; i < ROOM_MAX; i++)
	{

    // Only show records where the room name is not empty:
    // Check for non-null terminator byte!  (will have data!)
	  if (house->rooms[i].name[0] != '\0')
    { 
     displayRoomInfo(&house->rooms[i]);
    }
	}
}

// Get user input for a house (including room info)
void getHouseInfo( struct House* mansion )
{

  int i, addMore = 1;

	// prompt user for House #
	// randomly generate a house number (integer) 1 - 2000 (inclusive)
	mansion->houseNumber = randomInteger(1, 2000);
	printf("Enter house number: %d\n", mansion->houseNumber);

  // prompt user for House #
  // printf("Enter house number: ");
  // scanf("%d", &mansion->houseNumber); // input buffer: '\n'
  // clearBuffer();

  // prompt user for Street Name
  printf("Enter Street name: ");
  // get user for Street Name 
  scanf("%100[^\n]", mansion->streetName);
  clearBuffer();

  // prompt user for city
  printf("Enter city name: ");
  // get user for city
  scanf("%100[^\n]", mansion->city);
  clearBuffer();

	// Method 2: after each room data entry.. ask if another should be done...

  // get room info's !!!
  for (i = 0; i < ROOM_MAX && addMore; i++)
  {
    // prompt user for room(s) info!
    printf("Enter data for room$%d...\n", i + 1);

    // get user for room(s)
    // call a sub-process/function to do this part
    getRoomInfo( &mansion->rooms[i]);

    // ask user if more rooms need to be entered (values 1 or 0):
    printf("\n");
    do
    {
      printf("Do you want to enter another room? (1:yes|0:no): ");
      scanf("%d", &addMore); // '\n' left in the input buffer
      clearBuffer();
    } while (addMore < 0 || addMore > 1);
 }
}

// Get user input for a room
void getRoomInfo(struct Room* box)
{
	// promot for the room name
	printf("Enter room name: ");
	// get user input for room name
	scanf(" %100[^\n]", box->name);
	clearBuffer();

	// promot for x dimension (width)
	printf("Enter room width: ");
	// get user input for x dimension (width)
	scanf(" %lf", &box->x);
	// fabs = double | fabsf = float | fabsl = long double
	box->x = fabs(box->x); // 'fabs()' makes to positive number from negative number
	clearBuffer();

	// promot for z dimension (length)
	printf("Enter room length: ");
	// get user input for z dimension (length)
	scanf("%lf", &box->z);
	box->z = fabs(box->z); // fabs = double | fabsf = float | fabsl = long double
	clearBuffer();

	// promot for y dimension (height)
	printf("Enter room height: ");
	// get user input for y dimension (height)
	scanf("%lf", &box->y);
	box->y = fabs(box->y); // fabs = double | fabsf = float | fabsl = long double
	clearBuffer();
}

// Residence mian hub/driver for l ogical entry point
void residenceStart(void)
{
  struct House house = { 100, "Seneca Street", "Toronto",
                        {
                          {"Kitchen", 10.0, 12.0, 10.0},
                          {"Bedroom-1", 11.0, 12.0, 8.0},
                          {"Bedroom-2", 12.0, 12.0, 8.0},
                          {"Bedroom-3", 13.0, 12.0, 8.0},
                          {"Bedroom-4", 14.0, 12.0, 8.0},
                          {"Bedroom-5", 15.0, 12.0, 8.0},
                          {"Living Room", 16.0, 12.0, 10.0},
                          {"Dining Room", 17.0, 12.0, 10.0},
                          {"Bathroom-1", 8.0, 11.0, 8.0},
                          {"Bathroom-2", 8.0, 10.0, 8.0}
                        }     
                       };

  // display house information:
  displayHouseInfo(&house);

  // test chars count on all room names:
  // displayTotalRoomChars(house.rooms, ROOM_MAX);

  // replace all room names with new value:
  // changeRoomNamesToSame(house.rooms, ROOM_MAX);

  // Search for a room!
  // searchRoom(house.rooms, ROOM_MAX);

  // Append "(test)" to all room names...
	// appendRoomName(house.rooms, ROOM_MAX);

	// summary of character types:
	// characterSummary(house.rooms, ROOM_MAX);

  // 23.11.2020 ADD *** (BELOW)

  // change all room names to UPPERCASE
  // roomNamesToUppercase(house.rooms, ROOM_MAX);

  // save data to file
  saveHouseData(&house, ROOM_MAX, 0);

	// display house information:
	// displayHouseInfo(&house);
}