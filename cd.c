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

	char * directory = argv[1];

	int valid = chdir(directory);
	printf("%d\n", valid);

	// int t = chdir(input);
	// int no_flag = strcmp(flag, "  ");
	// int help_flag = strcmp(input,  "--help");

	// if (t) {
	// 	strcat(home, input);
	// 	if (help_flag == 0) {
	// 		int fd, sz;
	// 		char *c = (char  *) calloc(10000, sizeof(char));
	// 		fd = open("cd_help.txt", O_RDONLY);
	// 		sz = read(fd, c, 10000);
	// 	 	c[sz] = '\0';
	// 	 	printf("%s\n",c );
	// 	 	return;
	// 	}

	// 	if (strcmp(input,".") != 0 || strcmp(input, "..") !=0){
	// 		strcat(home, "/");
	// 	}
	// }
	// else {
	// 	printf("bash: cd: %s: No such file or directory\n", input );
	// 	return;
	// }

	return 0;
}

