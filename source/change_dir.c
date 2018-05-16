/*
** EPITECH PROJECT, 2018
** change_dir.c
** File description:
** change_dir.c
*/

#include "ai.h"

float *get_values(char **info_lidar)
{
	float *values = malloc(sizeof(float) * (my_tablen(info_lidar) + 2));
	int i = 0;

	while (info_lidar[i] != NULL) {
		values[i] = atof(info_lidar[i]);
		i = i + 1;
	}
	values[i] = -1;
	return (values);
}

void change_dir(char **info_lidar)
{
	float *values = get_values(info_lidar);
	int i = 0;
	int pos = 0;

	while (values[i] != -1) {
		if (values[i] > values[pos])
			pos = i;
		i = i + 1;
	}
	get_dir(values, pos);
}

void get_dir(float *values, int pos)
{
	int prev_pos = stock_pos(0, 0);

	if (pos <= 1) {
		exec_cmd("wheels_dir:0.8");
		input(0, 1);
		return;
	}
	if (pos <= 3) {
		exec_cmd("wheels_dir:0.6");
		input(0, 1);
		return;
	}
	if (pos <= 6) {
		exec_cmd("wheels_dir:0.4");
		input(0, 1);
		return;
	}
	/*if (pos < 10) {
		exec_cmd("wheels_dir:0.2");
		input(0, 1);
		return;
	}*/
	if (pos > 6 && pos < 24) {
		exec_cmd("wheels_dir:0");
		input(0, 1);
		return;
	}
	if (pos >= 29) {
		exec_cmd("wheels_dir:-0.8");
		input(0, 1);
		return;
	}
	if (pos >= 27) {
		exec_cmd("wheels_dir:-0.6");
		input(0, 1);
		return;
	}
	if (pos >= 24) {
		exec_cmd("wheels_dir:-0.4");
		input(0, 1);
		return;
	}
	/*if (pos > 20) {
		exec_cmd("wheels_dir:-0.2");
		input(0, 1);
		return;
	}*/
}

int my_tablen(char **tab)
{
	int i = 0;

	while (tab[i] != NULL)
		i = i + 1;
	return (i);
}

int stock_pos(int bo, int pos)
{
	static int buf = 0;

	if (bo == 1)
		buf = pos;
	return (buf);
}