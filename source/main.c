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

void simulation(void)
{
	char *str = NULL;

	while(42) {
		exec_cmd("get_info_lidar");
		str = input(0, 1);
	}
}

int main(int ac, char **av)
{
	if (ac != 1 || av[1])
		return (84);
	exec_cmd("start_simulation");
	simulation();
	return (0);
}
