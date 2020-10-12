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

char home[PATH_MAX] = "/home/hari/OS/Assignments/Assignment 1/Q2/";

// External Commands
void ls_function(char * flag, char * input) {
	int status;
	char *args[] = {"./ls", flag, input , NULL};
	if (fork() == 0) {
		execvp(args[0], args);
		exit(0);
	}
	else {
		waitpid(-1, &status, 0);
	}
}

void cat_function(char * flag, char * input) {
	int status;
	char *args4[] = {"./cat", flag, input, NULL};
	if (fork() == 0) {
		execvp(args4[0], args4);
		exit(0);
	}
	else {
		waitpid(-1, &status, 0);
	}
}

void date_function(char * flag, char * input) {
	int status;
	char *args1[] = {"./date", flag, input, NULL};
	if (fork() == 0) {
		execvp(args1[0], args1);
		exit(0);
	} else {
		waitpid(-1, &status, 0);
	}
}

void remove_function(char * flag, char * input) {
	int status;
	char *args2[] = {"./rm", flag, input, NULL};
	if (fork() == 0) {
		execvp(args2[0], args2);
		exit(0);
	}
	else {
		waitpid(-1, &status, 0);
	}
}

void mkdir_function(char * flag, char * input) {
	int status;
	char *args3[] = {"./mkdir", flag, input, NULL};
	if (fork() == 0) {
		execvp(args3[0], args3);
		exit(0);
	}
	else {
		waitpid(-1, &status, 0);
	}
}

// Internal Commands
void pwd_function(char * flag, char *options) {
	int no_flag = strcmp(flag, "  ");
	int p_flag = strcmp(flag, "-P");
	int help_flag = strcmp(options, "--help");
	if (help_flag == 0) {		
		int fd, sz;
		char *c = (char  *) calloc(10000, sizeof(char));
		fd = open("pwd_help.txt", O_RDONLY);
		sz = read(fd, c, 10000);
	 	c[sz] = '\0';
	 	printf("%s\n", c );
		return;
	}
	if (p_flag == 0 || no_flag == 0) {
		printf("%s ", home);		
	}
}

void cd_function(char * flag, char * input) {
	int t = chdir(input);
	int no_flag = strcmp(flag, "  ");
	int help_flag = strcmp(input,  "--help");

	if (t) {
		strcat(home, input);
		if (help_flag == 0) {
			int fd, sz;
			char *c = (char  *) calloc(10000, sizeof(char));
			fd = open("cd_help.txt", O_RDONLY);
			sz = read(fd, c, 10000);
		 	c[sz] = '\0';
		 	printf("%s\n",c );
		 	return;
		}

		if (strcmp(input,".") != 0 || strcmp(input, "..") !=0){
			strcat(home, "/");
		}
	}
	else {
		printf("bash: cd: %s: No such file or directory\n", input );
		return;
	}
}

void echo_function(char * flag, char * output) {
	int no_flag = strcmp(flag, "  ");
	int n_flag = strcmp(flag, "-n");

	if (no_flag == 0) {
		printf("%s\n", output);
	}
	else if (n_flag == 0){
		printf("%s", output);
	}
}

void history_function(char * flag) {
	int help_flag = strcmp(flag, "--help");

	if (help_flag == 0) {
		int fd, sz;
		char *c = (char  *) calloc(10000, sizeof(char));
		fd = open("cd_help.txt", O_RDONLY);
		sz = read(fd, c, 10000);
	 	c[sz] = '\0';
	 	printf("%s\n",c );
	 	return;
	}

	int fd, sz;
	char *c = (char  *) calloc(10000, sizeof(char));
	fd = open("history.txt", O_RDONLY);
	sz = read(fd, c, 10000);
 	c[sz] = '\0';
 	printf("%s\n", c );
}

int main(void) {
	printf("%s\n", "" );

	FILE *history;
	history = fopen("history.txt", "w+");
	
	char * input = (char *) calloc(1024, sizeof(char));

	int command_no = 0;

	char * command;
	char * flag ;
	char * options;
	char * temp;

	int fd, sz;
	char *c = (char  *) calloc(10000, sizeof(char));

	fd = open("history.txt", O_RDONLY);
	sz = read(fd, c, 10000);
 	c[sz] = '\0';

	command = NULL;
	flag = NULL;
	options = NULL;

	while (1) {
		command_no++;
		pwd_function("  ", "  ");
		fgets(input, 1024, stdin);

		if (strcmp(input, "\n") == 0){
			continue;
		}
		input = strtok(input, "\n");
		if (strcmp(input, "exit") ==0 ) {
			return 0;
		}
		fprintf(history, "%d %s\n", command_no, input);
		
		int no = 1;
		
		char * history_text;

		command = strtok(input, " ");
		temp = command;
		while (temp != NULL) {
			temp = strtok(NULL, " ");
			if (no == 1) {
				flag = temp;
				no++;
			}
			else if (no == 2) {
				options = temp;
				no++;
			}
		}	

		if (flag == NULL) {
			flag = "  ";
		}

		if (options == NULL) {
			options = flag;
			flag = "  ";
		}

		if (strcmp(command, "cd") == 0) {
			cd_function(flag, options);
		}
		else if (strcmp(command, "echo") == 0) {
			echo_function(flag, options);
		}
		else if (strcmp(command, "history") == 0) {
			fclose(history);
			history_function(options);
			fopen("history.txt", "w+");
		}
		else if (strcmp(command, "pwd") == 0) {
			pwd_function(flag, options);
			printf("\n");
		}
		else if(strcmp(command, "ls") == 0) {
			ls_function(flag, options);
		}
		else if (strcmp(command, "cat") == 0) {
			cat_function(flag, options);
		}
		else if (strcmp(command, "date") == 0) {
			date_function(flag, options);
		}
		else if (strcmp(command, "rm") == 0) {
			remove_function(flag, options);
		}
		else if(strcmp(command, "mkdir") == 0) {
			mkdir_function(flag, options);
		}
		else {
			printf("%s: command not found\n", command);
		}
	}

	printf("End\n");
	return 1;
}