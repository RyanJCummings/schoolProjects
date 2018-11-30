#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"


// Reads the input file and parses line by line into an array of Class structs
int readFile(Class class_array[]) {

    char line[80];
    char *token;
    int i = 0;
    FILE *fp;

    if ((fp = fopen("classes.txt", "r")) == NULL){
        printf("Error opening file\n");
        exit(1);
    } else {

    while(fgets(line, 79, fp) != NULL) {
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
	}

    fclose(fp);
		return i;
}
