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
        printf("%d\n", i);
        sscanf(line, "%s %s %s %s %d",class_array[i].course_num, class_array[i].title,
          class_array[i].day, class_array[i].time, &class_array[i].year);

        printf("%s\n", class_array[i].course_num);
        i++;
    }
  }
  free(line);
  return 0;   // exit with no errors
  fclose(in_file);
}
