// 23.11.2020


#define NAME_SIZE 100
#define ROOM_MAX 40

// ----------------------------------
// DATA TYPES:

struct Room
{
	char name[NAME_SIZE + 1]; // description/name
	double x;                 // typically width
	double z;                 // typically lenght
	double y;                 // typically height
};

struct House
{
	int houseNumber;
	char streetName[NAME_SIZE + 1];
	char city[NAME_SIZE + 1];
	struct Room rooms[ROOM_MAX]; // array of struct Room
};

//		Address: 100 Seneca Street, Toronto
//		Room Name           Width     Length    Height
//		------------------- --------- --------- ---------
//		Kitchen                  10.5      12.2       8.0
//		Bathroom                 21.4       8.7       8.0
//		Bedroom                  10.5      12.2       8.0
//		Dining Room               9.5       8.2       8.0


// ----------------------------------
// FUNCTIONS: PROTOTYPES

// Display details about a Room type
void displayRoomInfo(struct Room* room );

// Display details about a house (including rooms)
void displayHouseInfo(struct House* house );

// Get user input for a house (including room info)
void getHouseInfo(struct House* mansion );

// Get user input for a room
void getRoomInfo(struct Room* box);

// Residence mian hub/driver for logical entry point
void residenceStart(void);