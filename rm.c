#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>
#include <dirent.h>

void function(char * flag, char * input) {
	int no_flag = strcmp(flag, "  ");
	int force_flag = strcmp(flag, "--force") || strcmp(flag, "-f");
	int i_flag = strcmp(flag, "-i");
	int help_flag = strcmp(input, "--help");

	if (help_flag == 0) {
		int fd, sz;
		char *c = (char  *) calloc(10000, sizeof(char));
		fd = open("rm_help.txt", O_RDONLY);
		sz = read(fd, c, 10000);
	 	c[sz] = '\0';
	 	printf("%s\n", c );
	 	return;
	}
	
	int valid;
	if (no_flag == 0) {
		valid = remove(input);
		if (valid != 0){
			printf("rm: cannot remove '%s': No such file or directory\n", input);
		}
	}
	else if(force_flag == 0) {
		valid = remove(input);
	}
	else if (i_flag == 0) {
		printf("rm: cannot remove '%s': No such file or directory\n", input);
		
		printf("rm: remove regular file '%s'? \n", input);
		char y[100];
		scanf("%[^\n]%*c", y);
		if (strcmp(y, "y") == 0) {
			valid = remove(input);
		}
	}
}

int main(int argc, char *argv[]) {
	char * flag = argv[1];
	char * input = argv[2];

	function(flag, input);
	return 0;
}