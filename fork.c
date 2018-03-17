#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int fork(void)
{
	pid_t my_pid;
	pid_t child_pid, parent;

	parent = getppid();
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	parent = getppid();
	my_pid = getpid();
	printf("((%u)) (%u) %u \n", parent, my_pid, child_pid);
	return (0);
}
