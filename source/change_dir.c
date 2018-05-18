/*
** EPITECH PROJECT, 2018
** change_dir.c
** File description:
** change_dir.c
*/

#include "ai.h"

void change_dir(char **info_lidar)
{
	float value = atof(info_lidar[3]) - atof(info_lidar[34]);
	float middle = atof(info_lidar[17]);

	get_speed(middle);
	if (value >= 0) {
		to_left(middle);
		return;
	}
	to_right(middle);
}

void to_left(float middle)
{
	if (middle >= 2100)
		exec_cmd("wheels_dir:0");
	if (middle >= 1000 && middle < 2100)
		exec_cmd("wheels_dir:0.05");
	if (middle >= 700 && middle < 1000)
		exec_cmd("wheels_dir:0.1");
	if (middle >= 400 && middle < 700)
		exec_cmd("wheels_dir:0.2");
	if (middle >= 200 && middle < 400)
		exec_cmd("wheels_dir:0.3");
	if (middle < 200)
		exec_cmd("wheels_dir:0.5");
}

void to_right(float middle)
{
	if (middle >= 2100)
		exec_cmd("wheels_dir:0");
	if (middle >= 1000 && middle < 2100)
		exec_cmd("wheels_dir:-0.05");
	if (middle >= 700 && middle < 1000)
		exec_cmd("wheels_dir:-0.1");
	if (middle >= 400 && middle < 700)
		exec_cmd("wheels_dir:-0.2");
	if (middle >= 200 && middle < 400)
		exec_cmd("wheels_dir:-0.3");
	if (middle < 200)
		exec_cmd("wheels_dir:-0.5");
}

void get_speed(float middle)
{

	if (middle >= 2100)
		exec_cmd("car_forward:1");
	if (middle >= 1500 && middle < 2100)
		exec_cmd("car_forward:0.8");
	if (middle >= 1000 && middle < 1500)
		exec_cmd("car_forward:0.4");
	if (middle >= 600 && middle < 1000)
		exec_cmd("car_forward:0.3");
	if (middle >= 400 && middle < 600)
		exec_cmd("car_forward:0.2");
	if (middle < 400)
		exec_cmd("car_forward:0.1");
}

int my_tablen(char **tab)
{
	int i = 0;

	while (tab[i] != NULL)
		i = i + 1;
	return (i);
}
