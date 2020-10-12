#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	long n1 = strtol(argv[1], 0, 0);
	long n2 = strtol(argv[2], 0, 0);
	printf("%s\n", argv[1]);
	printf("%ld\n", n1+n2);
	return 0;
}