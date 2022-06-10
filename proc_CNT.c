#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int id = fork();
	if (id > 0) {
		printf("parent: %d\n", getpid());	
	}
	else if (id == 0) {
		printf("parent: %d\n", getppid());
		printf("child: %d\n", getpid());
	}
	else {
		printf("Error in process creation\n");
		return 1;
	}
	return 0;
}
