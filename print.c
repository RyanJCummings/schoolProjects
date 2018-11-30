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

    //int size = (sizeof(strt) / sizeof(strt[0]));
    char header[160] = "\n\nClasses for selected start time\n----------------------------------\n";
    char time[10];

    printf("Which start time? [hhmm]: ");
		scanf("%s", time);
		if (strcmp(time,"0900") == 0 || strcmp(time,"1000") == 0 || strcmp(time,"1100") == 0
			|| strcmp(time,"1200") == 0 || strcmp(time,"1300") == 0 || strcmp(time,"1400") == 0
			|| strcmp(time,"1500") == 0){

				printFile(strt, size, header, time);

		} else {
				printf ("Sorry that response is invalid\n");
				exit(1);
		}
}

// sorts classes by year in school
void sortYear(Class strt[], int size) {

    char header[160] = "\n\nClasses for \n----------------------------------\n";
    char ans[10];

    printf("Which year? [Freshman, Sophomore, Junior, senioR (f,s,j,r)]: ");
    scanf("%s", ans);
	    if (strcmp(ans, "f")==0) {
	        strcpy(header, "\n\nClasses for Freshman\n----------------------------------\n");
	    } else if (strcmp(ans, "s")==0) {
	        strcpy(header, "\n\nClasses for Sophomore\n----------------------------------\n");
	    } else if (strcmp(ans, "j")==0) {
	        strcpy(header, "\n\nClasses for Junior\n----------------------------------\n");
	    } else if (strcmp(ans, "r")==0) {
	        strcpy(header, "\n\nClasses for Senior\n----------------------------------\n");
	    } else {
					printf("Sorry that response is invalid\n");
					exit(1);
	    }

	    printFile(strt, size, header, ans);
}

// function for printing the structure
void printFile(Class strt[], int size, char header[], char days[]) {

    int i;
    char *token1, *token2;

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

    } else if (strcmp(days, "MWF") == 0 || (strcmp(days, "TR") == 0)) {

        for (i=0; i<size; i++) {
            if(strcmp(strt[i].day, days) == 0) {
                print(strt, fP, i);
            }

        }

    } else {

        token1 = strtok(days, "-");

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
    char yearText[30];

    fprintf(fP, "%-47s", strt[i].title);
    //fprintf(fP, "%s", " ");
    fprintf(fP, "%-9s", strt[i].course_num);
    //fprintf(fP, "%s", " ");

    switch (strt[i].year) {
        case 1:
            strcpy(yearText, "avialable for Freshman");
            break;
        case 2:
            strcpy(yearText, "avialable for Sophomore");
            break;
        case 3:
            strcpy(yearText, "avialable for Junior");
            break;
        case 4:
            strcpy(yearText, "avialable for Senior");
            break;
        default:
            strcpy(yearText, "No year...");
            printf("yearText is: %s\n", yearText);
            printf("strt.year is: ->%d<-\n", strt[i].year);
    }

    fprintf(fP, "%-25s", yearText);
    //fprintf(fP, "%s", " ");
    fprintf(fP, "%-4s", strt[i].day);
    //fprintf(fP, "%s", " ");
    fprintf(fP, "%2s", strt[i].time);
    fprintf(fP, "\n");
}
