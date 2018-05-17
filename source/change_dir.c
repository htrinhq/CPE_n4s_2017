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
	/*if (pos <= 1 && check_front(values)) {
		exec_cmd("wheels_dir:0.6");
		input(0, 1);
		return;
	}*/
	if (/*(pos <= 3 && check_front(values)) || */(check_val(values, 31, 32) && values[0] < values[31])) {
		exec_cmd("wheels_dir:0.25");
		input(0, 1);
		exec_cmd("car_forward:0.3");
		input(0, 1);
		return;
	}
	//if ((pos <= 6 && check_front(values))/* || check_val(values, 31, 32)*/) {
	//	exec_cmd("wheels_dir:0.15");
	//	input(0, 1);
	//	exec_cmd("car_forward:0.4");
	//	input(0, 1);
	//	return;
	//}
	//if ((pos < 8 && check_front(values))/* || check_val(values, 28, 32)*/) {
	//	exec_cmd("wheels_dir:0.1");
	//	input(0, 1);
	//	exec_cmd("car_forward:0.6");
	//	input(0, 1);
	//	return;
	//}
	/*if (pos >= 29 && check_front(values)) {
		exec_cmd("wheels_dir:-0.6");
		input(0, 1);
		return;
	}*/
	if (/*(pos >= 27 && check_front(values)) || */(check_val(values, 0, 1) && values[31] < values[0])) {
		exec_cmd("wheels_dir:-0.25");
		input(0, 1);
		exec_cmd("car_forward:0.3");
		input(0, 1);
		return;
	}
	if ((pos >= 27 && check_front(values))/* || (check_val(values, 0, 1) && values[31] < values[0])*/) {
		exec_cmd("wheels_dir:-0.25");
		input(0, 1);
		exec_cmd("car_forward:0.3");
		input(0, 1);
		return;
	}
	if ((pos <= 3 && check_front(values))/* || (check_val(values, 31, 32) && values[0] < values[31])*/) {
		exec_cmd("wheels_dir:0.25");
		input(0, 1);
		exec_cmd("car_forward:0.3");
		input(0, 1);
		return;
	}
	//if ((pos >= 24 && check_front(values))/* || check_val(values, 0, 1)*/) {
	//	exec_cmd("wheels_dir:-0.15");
	//	input(0, 1);
	//	exec_cmd("car_forward:0.4");
	//	input(0, 1);
	//	return;
	//}
	//if ((pos > 22 && check_front(values))/* || check_val(values, 28, 32)*/) {
	//	exec_cmd("wheels_dir:-0.1");
	//	input(0, 1);
	//	exec_cmd("car_forward:0.6");
	//	input(0, 1);
	//	return;
	//}
	if (pos >= 8 && pos <= 22) {
		exec_cmd("wheels_dir:0");
		input(0, 1);
		exec_cmd("car_forward:0.7");
		input(0, 1);
		return;
	}
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