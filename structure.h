//  Header file containing the struct and all the functions used in the program

#include <stdio.h>


typedef struct {
  char course_num[20];
  char title[50];
  char day[5];
  char time[15];
  int year;
} Class;

int printMenu();
int readFile(Class class_array[]);
void sortClassNumber(Class strt[], int size);
void sortWeekday(Class str[], int size);
void sortTime(Class strt[], int size);
void sortYear(Class strt[], int size);
void Swap(Class *a, Class *b);
void printFile(Class strt[], int size, char header[], char days[]);
void print(Class strt[], FILE *fP, int i);
