#include <stdio.h>

typedef struct {
  char course_num[20];
  char title[50];
  char day[5];
  char time[15];
  int year;
} Class;

void classes_by_number();
void classes_by_day();
void classes_by_time();
void classes_by_year();
int printMenu();
int read_file(FILE *in_file, Class class_array[]);

void sortClassNumber(Class strt[]);
void sortWeekday(Class str[]);
void sortTime(Class strt[]);
void sortYear(Class strt[]);
void Swap(Class *a, Class *b);
void printFile(Class strt[], char *filename);
