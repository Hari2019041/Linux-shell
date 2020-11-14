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

int main(int argc, char *argv[]) {
	
	char * flag = argv[1];
	char * output = argv[2];

	int no_flag = strcmp(flag, "  ");
	int n_flag = strcmp(flag, "-n");

	if (no_flag == 0) {
		printf("%s\n", output);
	}
	else if (n_flag == 0){
		printf("%s", output);
	}

	return 0;
}