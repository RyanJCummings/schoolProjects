#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"

void readFile(Class class_array[], int size) {

    char line[80];
    char *token;
    int i=0;
		FILE *fP;

    printf("i: %d\n", i);


		if ((fP = fopen("classes.txt", "r")) == NULL){
			printf("Error opening file\n");
			exit(1);
		}
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

        /*
        printf("\nThis is the structure: \n");
        printf("------------------------------\n");
        printf("Course: %s\n", class_array[i].course_num);
        printf("Title: %s\n", class_array[i].title);
        printf("Day: %s\n", class_array[i].day);
        printf("Time: %s\n", class_array[i].time);
        printf("Year: %d\n\n", class_array[i].year);

        printf("i: %d\n", i);
        */
        i++;


    }


    fclose(fP);

}
