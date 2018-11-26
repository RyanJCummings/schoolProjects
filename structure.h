#include <stdio.h>

typedef struct csci_class {
  char[20] course_num;
  char[50] title;
  char[5] day;
  int[15] time;
  int year;
} Class;

void classes_by_number();
void classes_by_day();
void classes_by_time();
void classes_by_year();
