#include <stdio.h>

typedef struct csci_class {
  char course_num[20];
  char title[50];
  char day[5];
  int time[15];
  int year;
} Class;

void classes_by_number();
void classes_by_day();
void classes_by_time();
void classes_by_year();
int printMenu();

void test();
