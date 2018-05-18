/*
** EPITECH PROJECT, 2018
** change_dir.c
** File description:
** change_dir.c
*/

#include "ai.h"

/*float *get_values(char **info_lidar)
{
	float *values = malloc(sizeof(float) * (my_tablen(info_lidar) + 2));
	int i = 0;

	while (info_lidar[i] != NULL) {
		values[i] = atof(info_lidar[i]);
		i = i + 1;
	}
	values[i] = -1;
	return (values);
}*/

void change_dir(char **info_lidar)
{
	float value = atof(info_lidar[3]) - atof(info_lidar[34]);
	float middle = atof(info_lidar[16]);

	get_speed(middle);
	if (value >= 0) {
		to_left(middle);
		return;
	}
	to_right(middle);
}

void to_left(float middle)
{
	if (middle >= 2100) {
		exec_cmd("wheels_dir:0");
		input(0, 1);
		return;
	}
	if (middle >= 1000) {
		exec_cmd("wheels_dir:0.05");
		input(0, 1);
		return;
	}
	if (middle >= 700) {
		exec_cmd("wheels_dir:0.1");
		input(0, 1);
		return;
	}
	if (middle >= 400) {
		exec_cmd("wheels_dir:0.2");
		input(0, 1);
		return;
	}
	if (middle >= 200) {
		exec_cmd("wheels_dir:0.3");
		input(0, 1);
		return;
	}
	exec_cmd("wheels_dir:0.5");
	input(0, 1);
}

void to_right(float middle)
{
	if (middle >= 2100) {
		exec_cmd("wheels_dir:0");
		input(0, 1);
		return;
	}
	if (middle >= 1000) {
		exec_cmd("wheels_dir:-0.05");
		input(0, 1);
		return;
	}
	if (middle >= 700) {
		exec_cmd("wheels_dir:-0.1");
		input(0, 1);
		return;
	}
	if (middle >= 400) {
		exec_cmd("wheels_dir:-0.2");
		input(0, 1);
		return;
	}
	if (middle >= 200) {
		exec_cmd("wheels_dir:-0.3");
		input(0, 1);
		return;
	}
	exec_cmd("wheels_dir:-0.5");
	input(0, 1);
}

void get_speed(float middle)
{

	if (middle >= 2100) {
		exec_cmd("car_forward:1");
		input(0, 1);
		return;
	}
	if (middle >= 1500) {
		exec_cmd("car_forward:0.7");
		input(0, 1);
		return;
	}
	if (middle >= 1000) {
		exec_cmd("car_forward:0.4");
		input(0, 1);
		return;
	}
	if (middle >= 600) {
		exec_cmd("car_forward:0.3");
		input(0, 1);
		return;
	}
	if (middle >= 400) {
		exec_cmd("car_forward:0.2");
		input(0, 1);
		return;
	}
	exec_cmd("car_forward:0.1");
	input(0, 1);
}

int my_tablen(char **tab)
{
	int i = 0;

	while (tab[i] != NULL)
		i = i + 1;
	return (i);
}

int check_front(float *values)
{
	int i = 10;

	while (i < 21) {
		if (values[i] < 600)
			return (1);
		i = i + 1;
	}
	return (0);
}

int check_val(float *values, int min, int max)
{
	int i = min;

	while (i < max) {
		if (values[i] < 450)
			return (1);
		i = i + 1;
	}
	return (0);
}
