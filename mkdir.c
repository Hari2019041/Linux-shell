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
	int check;
	int no_flag = strcmp(flag, "  ");
	int v_flag = strcmp(flag, "-v");
	int p_flag = strcmp(flag, "-p");
	int help_flag = strcmp(input, "--help");

	if (help_flag == 0){		
		int fd, sz;
		char *c = (char  *) calloc(10000, sizeof(char));
		fd = open("mkdir_help.txt", O_RDONLY);
		sz = read(fd, c, 10000);
	 	c[sz] = '\0';
	 	printf("%s\n",c );
	 	return;
	}

	check = mkdir(input, 0777);
	if (no_flag == 0) {
		if (check) {
			printf("mkdir: cannot create directory '%s': File exists\n", input);
		}
	}
	else if (v_flag == 0) {
		if (!check) {
			printf("mkdir: created directory '%s'\n", input );
		}
		else {
			printf("mkdir: cannot create directory '%s': File exists\n", input);			
		}
	}
	else if (p_flag == 0) {
	}
		
}

int main(int argc, char *argv[]) {
	char * flag  = argv[1];
	char * input = argv[2];

	function(flag, input);

	return 0;
}