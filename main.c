#include "main.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char **argv)
{
	int fd = 0;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				fprintf(stderr, "%s: 0: Can't open %s\n", argv[0], argv[1]);
				exit(127);
			} else
				exit(EXIT_FAILURE);
		}
	} else
		fd = 0;

	while (1)
	{
		char line[1024];

		fgets(line, sizeof(line), fd);

		if (feof(fd))
			break;

		char *command = strtok(line, " ");

		if (command == NULL)
			continue;

		int status = system(command);

		if (status != 0)
			printf("Command '%s' failed with status %d\n", command, status);
	}

	return (EXIT_SUCCESS);
}
