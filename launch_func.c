#include "shell_inc.h"

/**
 * func_launch - Launch a program and wait for it to terminate.
 * @args: Null terminated list of arguments (including program).
 *
 * Return: 1
 */
int func_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error");
	}
	else
	{
		do {
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
