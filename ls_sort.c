#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t pid;
	int fd[2]; // fd[0] => read end, fd[1] => write end
	char buff[10];
	if (pipe(fd) < 0) {
		printf("error\n");
		return 1;
	}
	pid = fork();
	if (pid < 0) {
		printf("error\n");
		return 1;
	}
	else if (pid == 0) {
		close(1);
		dup(fd[1]);
		close(fd[0]);
		execlp("ls", "ls", NULL);
	}
	else {
		close(0);
		dup(fd[0]);
		close(fd[1]);
		execlp("sort", "sort", NULL);
	}
	return 0;
}
