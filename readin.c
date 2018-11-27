#include <stdio.h>
#include "structure.h"

void read_file(FILE *in_file){
  in_file = fopen("classes.txt", "r");



  fclose(in_file);
}
