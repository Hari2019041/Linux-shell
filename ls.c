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
	DIR *d;
	struct dirent *dir;

	int no_flag = strcmp(flag, "  ");
	int flag_1 = strcmp(flag, "-1");
	int a_flag = strcmp(flag, "-a");
	int help_flag = strcmp(flag, "--help");

	int hh = strcmp(input, "  ");

	if (help_flag == 0) {
		int fd, sz;
		char *c = (char  *) calloc(10000, sizeof(char));
		fd = open("ls_help.txt", O_RDONLY);
		sz = read(fd, c, 10000);
	 	c[sz] = '\0';
	 	printf("%s\n", c);
	 	return;
	}
	d = opendir(input);
	char * name;

	if (d) {
		while((dir = readdir(d)) != NULL) {
			name = dir->d_name;
			if (no_flag == 0) {
				if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
					continue;
				}
				printf("%s    ", name);
			}
			else if (flag_1 == 0) {
				if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
					continue;
				}
				printf("%s\n", name);
			}
			else if (a_flag == 0) {
				printf("%s  ", name);
			}
		}
		printf("%s\n", "" );
		closedir(d);
	}
	else {
		printf("ls: cannot access '%s': No such file or directory\n", input);
	}
}

int main(int argc, char *argv[]) {
	char * flag  = argv[1];
	char * input = argv[2];

	function(flag, input);

	exit(-1);
	return 0;
}