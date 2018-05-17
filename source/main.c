/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for n4s
*/

#include "ai.h"

void exec_cmd(char *str)
{
	write(1, str, strlen(str));
	write(1, "\n", 1);
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
		exec_cmd("get_info_lidar");
		str = input(0, 1);
		info = my_str_to_word_array(str, ':', ':');
		change_dir(info);
		/*if (!strcmp(info[15], "3010.0")) {
			exec_cmd("car_forward:1");
			input(0, 1);
		}
		else {
			exec_cmd("car_forward:0.6");
			input(0, 1);
		}*/
		frees(str, info);
	}
	exec_cmd("stop_simulation");
	input(0, 1);
}

int main(int ac, char **av)
{
	if (ac != 1 || av[1])
		return (84);
	exec_cmd("start_simulation");
	input(0, 1);
	simulation();
	return (0);
}
