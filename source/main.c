/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for n4s
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

int main(int ac, char **av)
{
	if (ac != 1 || av[1])
		return (84);
	exec_cmd("start_simulation");
	simulation();
	return (0);
}
