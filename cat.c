#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

void function(char * flag, char * input) {
	int no_flag = strcmp(flag, "  ");
	int n_flag = strcmp(flag, "-n");
	int E_flag = strcmp(flag, "-E");
	int help_flag = strcmp(input, "--help");

	int fd, sz;
	char *c = (char  *) calloc(10000, sizeof(char));
	fd = open(input, O_RDONLY);
	sz = read(fd, c, 10000);
 	c[sz] = '\0';

 	int no  = 1;
	if (fd != -1) {	
		if (help_flag == 0) {
			fd = open("cat_help.txt", O_RDONLY);
			sz = read(fd, c, 10000);
			c[sz] = '\0';
			printf("%s\n", c);
			return;
		}

		if (no_flag == 0) {
			printf("%s\n", c );
			return;
		}
		char* line = strtok(c, "\n");
		if (n_flag == 0) {
			while (line != NULL) {
				printf("%d  %s\n", no, line );
				line = strtok(NULL, "\n");
				no++;
			} 		
		}
		else if (E_flag == 0) {
			while (line != NULL) {
				printf("%s$\n", line );
				line = strtok(NULL, "\n");
				no++;
			} 		
		}
	}
	else {
		printf("cat: %s: No such file or directory", input);
	}
	printf("\n");
} 

int main(int argc, char *argv[]) {
	char * flag = argv[1];
	char * input = argv[2];

	function(flag, input);

	return 0;
}