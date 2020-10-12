#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>

void date(char * flag, char * options) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int no_flag = strcmp(flag, "  ");
	int help_flag = strcmp(options, "--help");
	int d_flag = strcmp(flag, "-d");
	
	if (help_flag == 0) {
		int fd, sz;
		char *c = (char  *) calloc(10000, sizeof(char));
		fd = open("date_help.txt", O_RDONLY);
		sz = read(fd, c, 10000);
	 	c[sz] = '\0';
	 	printf("%s\n", c);
	 	return;
	}
	if (no_flag == 0) {
		printf("now: %d-%02d-%02d %02d:%02d:%02d IST \n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	}
}

int main(int argc, char *argv[])
{
	char * flag = argv[1];
	char * input = argv[2];
	date(flag, input);

	exit(-1);
	return 0;
}