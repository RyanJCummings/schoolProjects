#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

void sortClassNumber(Class strt[], int size) {

    int i, j;

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].course_num, strt[j].course_num) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }
}

void sortWeekday(Class strt[], int size) {

    int i, j;

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(strt[i].day , strt[j].day) > 0) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }
}


void sortTime(Class strt[], int size) {

    int i, j;

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strt[i].time > strt[j].time) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }
}


void sortYear(Class strt[], int size) {

    int i, j;

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strt[i].year > strt[j].year) {
                Swap(&strt[i], &strt[j]);
            }
        }
    }
}


//function to swap two variables
void Swap(Class *a, Class *b) {

    Class temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

