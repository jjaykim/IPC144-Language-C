// 23.11.2020

//
// FileHelpers Module/Library
// ==========================
// - file specific functions for saving and loading Residence related data
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "FileHelpers.h"

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
    // write the "house" main member info: houseNumber, streetName, and City
    // use '|' character to delimit each field
    fprintf(fp, "%d|%s|%s|", house->houseNumber, house->streetName, house->city);

    // loop each room
    for (i = 0; i < roomArrSize; i++)
    {
      if (house->rooms[i].name[0] != '\0')
      {
        // write the room member info: name, x, y, z
        printf("%s|%lf|%lf|%lf\n", house->rooms[i].name, 
                                   house->rooms[i].x, house->rooms[i].y, house->rooms[i].z);
      }

      // keep track of written record count
      recCounter++;
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
    printf("%d room records written to file.\n", recCounter);
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