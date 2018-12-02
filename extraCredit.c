#include <stdio.h>
#include <string.h>

typedef enum {False, True} bool;

typedef struct {
	int xx;
  int yy;
  int zz;
  int mm;
  char nickname[20];
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
	char *e = 0;
	char line[100];
	char *tok;

	if(inFile == NULL){
		perror("File not found");
	} else {
		while(e != NULL){
			e = fgets(line, 100, inFile);
			printf("%s\n", e);
			tok = strtok(line, ".");
			printf("%s\n", tok);
			list_of_addresses[i].xx = (int)*tok;

			tok = strtok(line, ".");
			list_of_addresses[i].yy = (int)*tok;
			tok = strtok(line, ".");
			list_of_addresses[i].zz = (int)*tok;
			tok = strtok(line, ".");
			list_of_addresses[i].mm = (int)*tok;
			char *str = strtok(line, " ");
			strcpy(list_of_addresses[i].nickname, str);
			i++;
		}
		printf("xx: %d\n", list_of_addresses[1].xx);
		printf("yy: %d\n", list_of_addresses[1].yy);
		printf("zz: %d\n", list_of_addresses[1].zz);
		printf("mm: %d\n", list_of_addresses[1].mm);
		printf("Nickname: %s\n", list_of_addresses[1].nickname);
	}
}
