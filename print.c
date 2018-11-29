#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

// sorting array for Class Number using swap function to swap pointer
void sortClassNumber(Class strt[], int size) {

    int i, j;
    char header[160] = "\n\nSortet bei Class Number\n----------------------------------\n";

    //int size = (sizeof(strt) / sizeof(strt[0]));

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].course_num, strt[j].course_num) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }

    printFile(strt, size, header);
}

// sorting array for weekday using swap function to swap pointer
void sortWeekday(Class strt[], int size) {

    int i, j;
    //int size = (sizeof(strt) / sizeof(strt[0]));
    char header[160] = "\n\nSortet bei Weekday\n----------------------------------\n";
    char ans[10];

    scanf("Show classes on MWF or TR? [MWF/TR] %s\n", ans);

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].day , strt[j].day) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }

    printFile(strt, size, header);
}

// sorting array for time using swap function to swap pointer
void sortTime(Class strt[], int size) {

    int i, j;
    //int size = (sizeof(strt) / sizeof(strt[0]));
    char header[160] = "\n\nSortet bei time\n----------------------------------\n";

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].time , strt[j].time) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }

    printFile(strt, size, header);
}

// sorting array for year using swap function to swap pointer
void sortYear(Class strt[], int size) {

    int i, j;
    //int size = (sizeof(strt) / sizeof(strt[0]));
    char header[160] = "\n\nSortet bei year\n----------------------------------\n";

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strt[i].year > strt[j].year) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }

    printFile(strt, size, header);
}

// function for printing the structure
void printFile(Class strt[], int size, char header[]) {

    int i;
    //int size = (sizeof(strt) / sizeof(strt[0]));

    // create file pointer with given filename
    FILE * fP;
    fP = fopen("output.txt", "a");

    // Printing Header
    fprintf(fP, "%s", header);

    // printing in file with for loop
    for (i=0; i<size; i++) {
        fprintf(fP, "%s", strt[i].course_num);
        fprintf(fP, "%s", " ");
        fprintf(fP, "%s", strt[i].title);
        fprintf(fP, "%s", " ");
        fprintf(fP, "%s", strt[i].day);
        fprintf(fP, "%s", " ");
        fprintf(fP, "%s", strt[i].time);
        fprintf(fP, "%s", " ");
        fprintf(fP, "%d", strt[i].year);
        fprintf(fP, "\n");
    }

    // close file after writing
    fclose(fP);
}


//function to swap two variables
void Swap(Class *a, Class *b) {

    Class temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

