#include "shell.h"

/**
 * pid - PID
 *
 * Return: Always 0.
 */
int pid(void)
{
	pid_t my_pid;
	my_pid = getpid();
	printf("current pid %u\n", my_pid);
	my_pid = getppid();
	printf("parent pid %u\n", my_pid);
	return (0);
}
