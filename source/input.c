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
	check_end(usr_cmd);
	return (usr_cmd);
}

void check_end(char *resp)
{
	int i = 0;
	int j = 0;
	char *info = malloc(sizeof(char) * strlen(resp));

	if (resp[0] == '1')
		j = 3;
	else if (resp[0] == '2' || resp[0] == '3' || resp[0] == '4')
		j = 4;
	while (j > 0) {
		if (resp[i] == ':')
			j = j - 1;
		i = i + 1;
	}
	while (resp[i] != '\0') {
		info[j] = resp[i];
		i = i + 1;
		j = j + 1;
	}
	info[j] = '\0';
	check_info(info);
}

void check_info(char *info)
{
	if (strncmp(info, "Track Cleared", 13) == 0) {
		exec_cmd("car_forward:0");
		input(0, 1);
		exec_cmd("stop_simulation");
		input(0, 1);
	}
}
