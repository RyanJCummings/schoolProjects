#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"

void readFile(Class class_array[], int size) {

    char line[80];
    char *token;
    int i=0;
    FILE *fP;

    if ((fP = fopen("classes.txt", "r")) == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    while(i<=size) {                        // just using the known number of lines...

        fgets(line, 80, fP);

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

        i++;
    }

    fclose(fP);

}
