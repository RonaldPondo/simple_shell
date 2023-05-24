#include "shell.h"

int main(void)
{
	char *prompt = "simple_shell> ";
	char *command;

	while (1)
	{
		printf("%s", prompt);
		fflush(stdout);

		command = getline(NULL, 0, stdin);
		if (command == NULL)
			break;
	}

	if (command[0] == '\n' || command[0] == '\0')
		continue;
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execvp(command, &command) < 0)
		{
			perror("execvp");
			exit(1);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	waitpid(pid, NULL, 0);
	}

	return (0);
}
