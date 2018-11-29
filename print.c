#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

// sorting array for Class Number using swap function to swap pointer
void sortClassNumber(Class strt[]) {

    int i, j;
    int size = (sizeof(strt) / sizeof(strt[0]));

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].course_num, strt[j].course_num) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }
}

// sorting array for weekday using swap function to swap pointer
void sortWeekday(Class strt[]) {

    int i, j;
    int size = (sizeof(strt) / sizeof(strt[0]));

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].day , strt[j].day) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }
}

// sorting array for time using swap function to swap pointer
void sortTime(Class strt[]) {

    int i, j;
    int size = (sizeof(strt) / sizeof(strt[0]));

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strt[i].time > strt[j].time) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }
}

// sorting array for year using swap function to swap pointer
void sortYear(Class strt[]) {

    int i, j;
    int size = (sizeof(strt) / sizeof(strt[0]));

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strt[i].year > strt[j].year) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }
}

// function for printing the structure
void printFile(Class strt[], char *filename) {

    int i;
    int size = (sizeof(strt) / sizeof(strt[0]));

    // create file pointer with given filename
    FILE *fp = fopen(filename, "w+");

    // printing in file with for loop
    for (i=0; i<size; i++) {
        fprintf(fp, strt[i].course_num, strt[i].title, strt[i].day, strt[i].time, strt[i].year);
    }

    // close file after writing
    fclose(fp);
}


//function to swap two variables
void Swap(Class *a, Class *b) {

    Class temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

