/*  Program 2, CSCI112
 *  Ryan Cummings, Dennis Pongratz
 *
 *  This program reads a file containing a list of classes offered by the MSU
 *  Computer Science department.  It prints a menu asking the user to specify methods
 *  of sorting and printing the list and prints the sorted list to an output file.
 */

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

int main(int argc, char **argv){

  Class class_array[20];

  int answer=0;

  int size = readFile(class_array); // returns the number of structs in the array.

  // creates a new output file.
  FILE * fP;
  fP = fopen("output.txt", "w");
  fclose(fP);

  do {
      answer = printMenu();

      if (answer == 1){
        // print all classes by CSCI number
        sortClassNumber(class_array, size);
      } else if (answer == 2){
        // print classes by day/time group
        sortWeekday(class_array, size);
      } else if (answer == 3){
        // print classes by time
        sortTime(class_array, size);
      } else if (answer == 4){
        // print classes by availablity per year in school
        sortYear(class_array, size);
      } else if (answer == 5){
        // exit with no errors
        	return 0;
      } else {
        // invalid response
        printf("Sorry that is not a valid response\n");
        exit(0);
      }
  } while(answer != 5);



  // exit with no errors
  return 0;
}

// prints menu and stores user response
int printMenu(){
  int response;

  printf("1) Print all classes in order by CSCI number\n");
  printf("2) Print all classes available on MWF or available on TR ordered by time.\n");
  printf("3) Print the class available at a specific time\n");
  printf("4) Print classes available to freshmen, sophomores, juniors, or seniors\n");
  printf("5) Quit\n");
  printf("Selection [Number]: ");
  scanf("%d", &response);

  return response;
}
