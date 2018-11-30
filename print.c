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

    printFile(strt, size, header, "print");
}

// sorting array for weekday using swap function to swap pointer
void sortWeekday(Class strt[], int size) {

    int i, j;
    //int size = (sizeof(strt) / sizeof(strt[0]));
    char header[160] = "\n\nSortet bei Weekday\n----------------------------------\n";
    char ans[10];

    printf("Show classes on MWF or TR? [MWF/TR]: ");
    scanf("%s", ans);
    printf("Answer: %s\n", ans);

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].day , strt[j].day) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }

    printFile(strt, size, header, ans);
}

// sorting array for time using swap function to swap pointer
void sortTime(Class strt[], int size) {

    int i, j;
    //int size = (sizeof(strt) / sizeof(strt[0]));
    char header[160] = "\n\nClasses for selected starttime\n----------------------------------\n";
    char time[10];

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].time , strt[j].time) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }

    printf("Which starttime? [hhmm]: ");
    scanf("%s", time);
    printf("Answer: %s\n", time);

    printFile(strt, size, header, time);
}

// sorting array for year using swap function to swap pointer
void sortYear(Class strt[], int size) {

    int i, j;
    //int size = (sizeof(strt) / sizeof(strt[0]));
    char header[160] = "\n\nClasses for \n----------------------------------\n";
    char ans[10];

    printf("Which year? [Freshman, Sophomore, Junior, senioR (f,s,j,r)]: ");
    scanf("%s", ans);
    printf("Answer: %s\n", ans);

    if (strcmp(ans, "f")==0) {
        strcpy(header, "\n\nClasses for Freshman\n----------------------------------\n");
    } else if (strcmp(ans, "s")==0) {
        strcpy(header, "\n\nClasses for Sophomore\n----------------------------------\n");
    } else if (strcmp(ans, "j")==0) {
        strcpy(header, "\n\nClasses for Junior\n----------------------------------\n");
    } else if (strcmp(ans, "r")==0) {
        strcpy(header, "\n\nClasses for Senior\n----------------------------------\n");
    } else {
         strcpy(header, "\n\nWrong selection\n----------------------------------\n");
    }

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strt[i].year > strt[j].year) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }

    printFile(strt, size, header, ans);
}

// function for printing the structure
void printFile(Class strt[], int size, char header[], char days[]) {

    int i;
    char *token1, *token2;
    //int size = (sizeof(strt) / sizeof(strt[0]));

    // create file pointer with given filename
    FILE * fP;
    fP = fopen("output.txt", "a");

    // Printing Header
    fprintf(fP, "%s", header);

    if (strcmp(days, "print")==0)  {

        // printing in file with for loop
        for (i=0; i<size; i++) {
            print(strt, fP, i);
        }

    } else if (strcmp(days, "f")==0) {

        for (i=0; i<size; i++) {
            if(strt[i].year == 1) {
                print(strt, fP, i);
            }

        }

    } else if (strcmp(days, "s")==0) {

        for (i=0; i<size; i++) {
            if(strt[i].year == 2) {
                print(strt, fP, i);
            }

        }

    } else if (strcmp(days, "j")==0) {

        for (i=0; i<size; i++) {
            if(strt[i].year == 3) {
                print(strt, fP, i);
            }

        }

    } else if (strcmp(days, "r")==0) {

        for (i=0; i<size; i++) {
            if(strt[i].year == 4) {
                print(strt, fP, i);
            }

        }

    } else if (strcmp(days, "MWF")==0 || (strcmp(days, "TR")==0)) {

        for (i=0; i<size; i++) {
            if(strcmp(strt[i].day, days)) {
                print(strt, fP, i);
            }

        }

    } else {

        token1 = strtok(days, "-");
        printf("Token1 is: %s\n", token1);

        for (i=0; i<size; i++) {       
            token2 = strtok(strt[i].time, "-");

            if(strcmp(token1, token2)==0) {
                print(strt, fP, i);
            }
        }
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

// function for printing data
void print(Class strt[], FILE *fP, int i) {
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

