#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"

int read_file(FILE *in_file, Class class_array[]){
  printf("Testing\n");
  char *line = malloc(sizeof(char) * 101);
  int i = 0;
  in_file = fopen("classes.txt", "r");

  if (in_file == NULL){          // error handling
    printf("in the 'if' statement\n");
    perror("Error opening file");
    return(-1);
  } else {
    printf("in the 'else' statement\n");
      while(fgets(line, 100, in_file) != NULL){
        //printf("%d\n", i);
        sscanf(line, "%s %s %s %s %d",class_array[i].course_num, class_array[i].title,
          class_array[i].day, class_array[i].time, &class_array[i].year);

        printf("%s\n", class_array[i].course_num);
				printf("%s\n", class_array[i].title);
				printf("%s\n", class_array[i].day);
				printf("%d\n", class_array[i].year);
        i++;
    }
  }
  free(line);
  fclose(in_file);
  return 0;   // exit with no errors
}


void readFileTest(Class class_array[], int size) {

    char line[80];
    char *token;
    int i=0;

    printf("i: %d\n", i);

    FILE * fP;
    fP = fopen("classes.txt", "r");

    //while(!feof(fP)) {                    // This gave me a crash
    //while(fgets(line, 80, fP)!=NULL) {    // and this stoped at line 7...

    while(i<=size) {                        // just using the known number of lines...

        fgets(line, 80, fP);
        printf("%s", line);

        // first token
        token = strtok(line, " ");
        strcpy(class_array[i].course_num, token);

        // second token
        token = strtok(NULL, ":");
        strcpy(class_array[i].title, token);

        // third token
        token = strtok(NULL, " ");
        strcpy(class_array[i].day, token);

        // fourth token
        token = strtok(NULL, " ");
        strcpy(class_array[i].time, token);


        // fifth token
        token = strtok(NULL, " ");
        class_array[i].year = (int)*token -48;

        printf("\nThis is the structure: \n");
        printf("------------------------------\n");
        printf("Course: %s\n", class_array[i].course_num);
        printf("Title: %s\n", class_array[i].title);
        printf("Day: %s\n", class_array[i].day);
        printf("Time: %s\n", class_array[i].time);
        printf("Year: %d\n\n", class_array[i].year);

        printf("i: %d\n", i);
        i++;


    }


    fclose(fP);

}


