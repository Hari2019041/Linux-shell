#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	char *args[] = {"./callee", "4", "5", NULL};
	int status;
	if (fork() == 0)
	{
		execvp(args[0], args);
	}
	else {
		waitpid(-1, &status, 0);	
	}
	return 1;

}