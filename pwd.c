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
	char cwd[PATH_MAX];
	char * flag  = argv[1];

	printf("%s$ ", getcwd(cwd, sizeof(cwd)));

	printf("%s\n",flag );

	// int no_flag = strcmp(flag, "  ");
	// int p_flag = strcmp(flag, "-P");
	// int help_flag = strcmp(options, "--help");
	// if (help_flag == 0) {		
	// 	int fd, sz;
	// 	char *c = (char  *) calloc(10000, sizeof(char));
	// 	fd = open("pwd_help.txt", O_RDONLY);
	// 	sz = read(fd, c, 10000);
	//  	c[sz] = '\0';
	//  	printf("%s\n", c );
	// 	return;
	// }
	// if (p_flag == 0 || no_flag == 0) {
	// 	printf("%s ", home);		
	// }
	return 0;
}