/*
** EPITECH PROJECT, 2018
** simulation.c
** File description:
** simulation.c
*/

#include "ai.h"

char *exec_cmd(char *str)
{
	write(1, str, strlen(str));
	write(1, "\n", 1);
	return (input(0, 1));
}

void frees(char *str, char **info)
{
	int x = 0;

	free(str);
	for (x = 0; info[x]; x = x + 1)
		free(info[x]);
	free(info);
}

void simulation(void)
{
	char *str = NULL;
	char **info = NULL;

	while (42) {
		str = exec_cmd("get_info_lidar");
		info = my_str_to_word_array(str, ':', ':');
		change_dir(info);
		frees(str, info);
	}
	exec_cmd("stop_simulation");
}

int check_sim(char *str)
{
	int i = 0;

	if (strlen(str) < 2)
		return (1);
	while (str[i] != '\0' && str[i] != ':')
		i = i + 1;
	if (str[i + 1] == 'K' && str[i + 2] == 'O')
		return (1);
	return (0);
}

int check_status(char *str)
{
	unsigned int i = 0;

	if (str == NULL)
		return (1);
	while (str[i] != '\0' && str[i] != ':')
		i = i + 1;
	if (i + 2 >= strlen(str))
		return (1);
	else if (str[i + 1] != 'O' && str[i + 2] != 'K')
		return (1);
	return (0);
}