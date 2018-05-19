/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for n4s
*/

#include "ai.h"

int main(int ac, char **av)
{
	char *str = NULL;

	if (ac != 1 || av[1])
		return (84);
	str = exec_cmd("start_simulation");
	if (check_sim(str))
		return (0);
	simulation();
	return (0);
}
