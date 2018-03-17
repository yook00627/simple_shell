#include "shell.h"

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int test(void)
{
	pid_t child_pid, pid;
	int i = 0, status;
	char *strs[] = {"/bin/ls", "-l", "/tmp/", NULL};

	while (i < 5)
	{
		pid = getpid();
		printf("parrent %u\n", pid);
		child_pid = fork();
		pid = getpid();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("%u\n", pid);
			exec(strs);
			sleep(1);
		}
		else
		{
			wait(&status);
		}
		i++;
	}
	return (0);
}
