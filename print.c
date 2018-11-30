#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"


// sorts input by Class Number.
void sortClassNumber(Class strt[], int size) {

    int i, j;
    char header[160] = "\n\nSorted by Class Number\n----------------------------------\n";

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].course_num, strt[j].course_num) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }
    printFile(strt, size, header, "print");
}

// sorts input by the days on which the class is offered
void sortWeekday(Class strt[], int size) {

    char header[160] = "\n\nSorted by Weekday\n----------------------------------\n";
    char ans[10];
    int i,j;

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].time, strt[j].time) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }

    printf("Show classes on MWF or TR? [MWF/TR]: ");
    scanf("%s", ans);
    if (strcmp(ans, "MWF")== 0 || strcmp(ans, "TR")== 0) {
        printFile(strt, size, header, ans);
    } else {
			printf("Sorry that is not a valid input.\n");
			exit(1);
		}

}

// sorts classes according to time the class is offered
void sortTime(Class strt[], int size) {

    char header[160] = "\n\nClasses for selected start time and day\n----------------------------------\n";
    char time[10];
    char day[10];
    char temp[10];
    char *token;
    int i=0, j, x=0;

    // create file pointer with given filename
    FILE * fp;
    fp = fopen("output.txt", "a");

    // Sorting array first
    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].time, strt[j].time) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }

    // getting user input
    printf("Which start time? [hhmm dd]: ");
    scanf("%s", time);
		scanf("%s", day);

    // adjusting input if day is a number and swap it.
    if (day[0]>48 && day[0]<57) {

        printf("in the if statement...");

        strcpy(temp, day);
        strcpy(day, time);
        strcpy(time, temp);

        printf("day: %s\n", day);
        printf("time: %s\n", time);
    }

    // Printing Header
    fprintf(fp, "%s", header);

    // Printing Data from Array
    for (i=0; i<size; i++) {

        token = strtok(strt[i].time, "-");

        if (strcmp(token, time)==0 && strcmp(strt[i].day, day)==0) {
            print(&strt[i], fp, 0);
            x = 1;
        }

    }
    // If no match, print this message
    if (x==0) {
        printf("%s", "Could not find selected day or time.\n");
				exit(1);
    }

    fclose(fp);
}

// sorts classes by year in school
void sortYear(Class strt[], int size) {

    char header[160] = "\n\nClasses for \n----------------------------------\n";
    char ans[10];

    // getting user input and select compatible header
    printf("Which year? [Freshman, Sophomore, Junior, senioR (f,s,j,r)]: ");
    scanf("%s", ans);
	    if (strcmp(ans, "f")==0) {
                strcpy(header, "\n\nClasses available for Freshman\n----------------------------------\n");
	    } else if (strcmp(ans, "s")==0) {
                strcpy(header, "\n\nClasses available for Sophomore\n----------------------------------\n");
	    } else if (strcmp(ans, "j")==0) {
                strcpy(header, "\n\nClasses available for Junior\n----------------------------------\n");
	    } else if (strcmp(ans, "r")==0) {
                strcpy(header, "\n\nClasses available for Senior\n----------------------------------\n");
	    } else {
					printf("Sorry that response is invalid\n");
					exit(1);
	    }

            // print into file with print function
	    printFile(strt, size, header, ans);
}

// function for printing the structure
void printFile(Class strt[], int size, char header[], char days[]) {

    int i;
    char *token1, *token2;

    // create file pointer with given filename
    FILE * fp;
    fp = fopen("output.txt", "a");

    // Printing Header
    fprintf(fp, "%s", header);

    if (strcmp(days, "print")==0)  {

        // printing in file with for loop
        for (i=0; i<size; i++) {
            print(strt, fp, i);
        }

    // print selections
    } else if (strcmp(days, "f")==0) {

        for (i=0; i<size; i++) {
            if(strt[i].year == 1) {
                print(strt, fp, i);
            }

        }

    } else if (strcmp(days, "s")==0) {

        for (i=0; i<size; i++) {
            if(strt[i].year == 2) {
                print(strt, fp, i);
            }

        }

    } else if (strcmp(days, "j")==0) {

        for (i=0; i<size; i++) {
            if(strt[i].year == 3) {
                print(strt, fp, i);
            }

        }

    } else if (strcmp(days, "r")==0) {

        for (i=0; i<size; i++) {
            if(strt[i].year == 4) {
                print(strt, fp, i);
            }

        }

    // printing selected days
    } else if (strcmp(days, "MWF") == 0 || (strcmp(days, "TR") == 0)) {

        for (i=0; i<size; i++) {
            if(strcmp(strt[i].day, days) == 0) {
                print(strt, fp, i);
            }

        }

    // printing times
    } else {

        token1 = strtok(days, "-");

        for (i=0; i<size; i++) {
            token2 = strtok(strt[i].time, "-");

            if(strcmp(token1, token2)==0) {
                print(strt, fp, i);
            }
        }
    }

    // close file after writing
    fclose(fp);
}

//function to swap two structures
void Swap(Class *a, Class *b) {

    Class temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// function for printing data
void print(Class strt[], FILE *fp, int i) {
    char yearText[30];

    // formatted priting to file
    fprintf(fp, "%-47s", strt[i].title);
    fprintf(fp, "%-9s", strt[i].course_num);

    switch (strt[i].year) {
        case 1:
            strcpy(yearText, "Freshman");
            break;
        case 2:
            strcpy(yearText, "Sophomore");
            break;
        case 3:
            strcpy(yearText, "Junior");
            break;
        case 4:
            strcpy(yearText, "Senior");
            break;
        default:
            strcpy(yearText, "No year...");
    }

    fprintf(fp, "%-10s", yearText);
    fprintf(fp, "%-4s", strt[i].day);
    fprintf(fp, "%2s", strt[i].time);
    fprintf(fp, "\n");
}
