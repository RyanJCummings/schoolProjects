#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum{false, true} bool;

typedef struct {
	int xx;
  int yy;
  int zz;
  int mm;
  char *nickname;
} address_t;

void readIn(FILE *ptr, address_t list_of_addresses[]);
bool compare(address_t list_of_addresses[]);

int main (int argc, char **argv){
  FILE *inFile = fopen("ipaddresses.txt", "r");
  address_t addresses[101];
	readIn(inFile, addresses);
	fclose(inFile);
  return 0; // exit with no errors
}

void readIn(FILE *inFile, address_t list_of_addresses[]){
	int i = 0;
	//char *e = 0;
	char line[101];
	char *tok;

	if(inFile == NULL){
		perror("File not found");
	} else {
		do{
			fgets(line, 100, inFile);
			tok = strtok(line, ".");
			list_of_addresses[i].xx = atoi(tok);
			printf("I've entered the while loop");

			tok = strtok(NULL, ".");
			list_of_addresses[i].yy = atoi(tok);

			tok = strtok(NULL, ".");
			list_of_addresses[i].zz = atoi(tok);

			tok = strtok(NULL, " ");
			list_of_addresses[i].mm = atoi(tok);

			tok = strtok(NULL, " ");
			list_of_addresses[i].nickname = tok;

			i++;
		} while(tok != 0);

		printf("xx: %d\n", list_of_addresses[1].xx);
		printf("yy: %d\n", list_of_addresses[1].yy);
		printf("zz: %d\n", list_of_addresses[1].zz);
		printf("mm: %d\n", list_of_addresses[1].mm);
		printf("Nickname: %s\n", list_of_addresses[1].nickname);
	}
}
