// 25.11.2020 ADD

//
// FileHelpers Module/Library
// ==========================
// - file specific functions for saving and loading Residence related data
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "FileHelpers.h"

// Save house data to file (optional to append based on isAppend)
int saveHouseData(const struct House* house, int roomArrSize, int isAppend) // Append: Adding to the end
{
  // Variables:
  int i, recCounter = 0, state = 0;
  FILE* fp = NULL; // safe empty state

  // open a data file (for write or append)
  // WRITE mode ("w"): recreate the file (will lose any existing data)
  // APPEND mode ("a"): adds data to the end of the file
  fp = isAppend ? fopen(FILE_DATA, "a") : fopen(FILE_DATA, "w");
  // if (isAppend)
  // {
  //   fp = fopen(FILE_DATA, "a");
  // }
  // else
  // {
  //   fp = fopen(FILE_DATA, "w");
  // }

  // if the file was opened sucessfully...
  if (fp != NULL)
  {
    // 25.11.2020 ADD *** (BELOW) Set up to ADD more room information on FileHelpers.c

    if (! isAppend) // Set up to avoide repeat the main information
    {
    // write the "house" main member info: houseNumber, streetName, and City
    // use '|' character to delimit each field
    fprintf(fp, "%d|%s|%s|\n", house->houseNumber, house->streetName, house->city);
    }

    // loop each room
    for (i = 0; i < roomArrSize; i++)
    {
      if (house->rooms[i].name[0] != '\0')
      {
        // write the room member info: name, x, y, z
        printf("%s|%lf|%lf|%lf\n", house->rooms[i].name, 
                                   house->rooms[i].x, house->rooms[i].y, house->rooms[i].z);

        // keep track of written record count
        recCounter++;
      }
    }

    // forces any leftover data to be written NOW.
    fflush(fp);

    // close connection to the file
    fclose(fp);

    // reset file connection to a safe empty state
    fp = NULL;
    
    // set state to good!
    state = 1;
    puts("");

    // 25.11.2020 ADD *** (BELOW) Set up to ADD more room information on FileHelpers.c
    if (isAppend)
    {
      printf("%d room records added to file.\n", recCounter);
    }
    else
    {
      printf("%d room records written to file.\n", recCounter);
    }
  }

  // if not opened sucessfully (show error)
  else
  {
    puts("");
    printf("ERROR: Unable to open data file!\n\n");
  }

  // return write status (ie: sucess/fail)
  return state;
}

// 25.11.2020 ADD *** (BELOW) 
// Load house data to file (includes rooms)
int loadHouseData(const struct House* house, int roomArrSize)
{
  // variables:
  int i, roomCounter = 0, status = 0, result;

  // open file for "read" access:
  FILE* fp = fopen(FILE_DATA, "r");

  // oh oh falied to open...
  if (fp == NULL)
  {
    printf("ERROR: Unable to open file for reading.\n\n");
  }
  else
  {
    // read first line of data from file
    // - house information part (street#, Street Name, City)
    result = fscanf(fp, "%d|%100[^|]|%100[^\n]\n", &house->houseNumber, house->streetName, house->city);

    // if reading was sucessful ::
    if (result == 3)
    {
      i = 0;
      // loop each room data until no more...
      while( fscanf(fp, "%100[^|]|%lf|%lf|%lf\n", house->rooms[i].name,
                    &house->rooms[i].x, // x, y, z are integer type so they need "&"
                    &house->rooms[i].y,
                    &house->rooms[i].z) == 4);
      {
        // add to room counter
        roomCounter++;
        i++;  // increase iterator
      }
      // fflush any unread data
      fflush(fp);

      // close the file
      fclose(fp);

      // reset file pointer (safe empty state)
      fp = NULL;

      // Show # of rooms read...
      if(roomCounter > 0)
      {
        printf("%d rooms read from file!\n\n", roomCounter);
        status = 1;
      }
      else
      {
        printf("ERROR: Failed to read house data!\n\n");
      }
      
    }
    // Reading unsuccesful:: Show an error ::
    else
    {
      printf("ERROR: Failed to read house data!\n\n");
    }
  }

  return status;
}
