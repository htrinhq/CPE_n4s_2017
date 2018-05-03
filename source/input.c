/*
** EPITECH PROJECT, 2017
** input.c
** File description:
** input function
*/

#include "ai.h"

void is_at_ty(int error)
{
	if (isatty(0) == 1)
		write(1, "exit\n", 5);
	exit(error);
}

char *input(int fd, int error)
{
	char *command = malloc(sizeof(char) + 1);
	char *usr_cmd = malloc(sizeof(char) + 1);

	usr_cmd[0] = '\0';
	command[0] = '\0';
	while (command[0] != '\n') {
		command = malloc(sizeof(char) + 1);
		read(fd, command, 1);
		if (command[0] == '\0')
			is_at_ty(error);
		command[1] = '\0';
		if (command[0] != '\n')
			usr_cmd = my_strcat(usr_cmd, command);
	}
	return (usr_cmd);
}
