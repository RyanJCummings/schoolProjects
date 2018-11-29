#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

typedef enum {false, true} Bool;

int main(int argc, char **argv){

  char *filename = argv[1];

  FILE *in_file;                 //
  Class class_array[20];

  int answer;
  int size = 13;

  readFileTest(class_array, size);
  //printFile(class_array, size);

  //read_file(in_file, class_array);
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
  scanf("%d", &response);

  return response;
}
