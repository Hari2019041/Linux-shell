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

void ls_function(char * flag, char * options) {
	int status;
	char *args[] = {"./ls", flag, options , NULL};
	if (fork() == 0) {
		execvp(args[0], args);
		exit(0);
	}
	else {
		waitpid(-1, &status, 0);
	}
}

void cat_function(char * flag, char * options) {
	int status;
	char *args4[] = {"./cat", flag, options, NULL};
	if (fork() == 0) {
		execvp(args4[0], args4);
		exit(0);
	}
	else {
		waitpid(-1, &status, 0);
	}
}

void date_function(char * flag, char * options) {
	int status;
	char *args1[] = {"./date", flag, options, NULL};
	if (fork() == 0) {
		execvp(args1[0], args1);
		exit(0);
	} else {
		waitpid(-1, &status, 0);
	}
}

void remove_function(char * flag, char * options) {
	int status;
	char *args2[] = {"./rm", flag, options, NULL};
	if (fork() == 0) {
		execvp(args2[0], args2);
		exit(0);
	}
	else {
		waitpid(-1, &status, 0);
	}
}

void mkdir_function(char * flag, char * options) {
	int status;
	char *args3[] = {"./mkdir", flag, options, NULL};
	if (fork() == 0) {
		execvp(args3[0], args3);
		exit(0);
	}
	else {
		waitpid(-1, &status, 0);
	}
}

void pwd_function(char * flag) {
	int status;
	char *args5[] = {"./pwd", flag, NULL};
	if (fork() == 0) {
		execvp(args5[0], args5);
		exit(0);
	}
	else {
		waitpid(-1, &status, 0);
	}
}

void cd_function(char * flag, char * options) {
	int status;
	char *args6[] = {"./cd", flag, options, NULL};
	if (fork() == 0) {
		execvp(args6[0], args6);
		exit(0);
	}
	else {
		waitpid(-1, &status, 0);
	}
}

void echo_function(char * flag, char * output) {
	int status;
	char *args7[] = {"./echo", flag, output, NULL};
	if (fork() == 0) {
		execvp(args7[0], args7);
		exit(0);
	}
	else {
		waitpid(-1, &status, 0);
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
	FILE *history;
	history = fopen("history.txt", "w+");
	
	char * input = (char *) calloc(1024, sizeof(char));

	int command_no = 0;

	char * command;
	char * flag; 
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
		pwd_function("  ");
		fgets(input, 1024, stdin);

		if (strcmp(input, "\n") == 0){
			continue;
		}
		input = strtok(input, "\n");
		if (strcmp(input, "exit") == 0) {
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
			pwd_function(flag);
			// printf("\n");
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

	return 1;
}