/*
** EPITECH PROJECT, 2017
** ia.h
** File description:
** ia.h for n4s
*/

#ifndef AI_H
#define AI_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *input(int fd, int error);
char *my_strcat(char *str1, char *str2);
char **my_str_to_word_array(char *str, char separator, char other_sep);
int my_tablen(char **tab);
void change_dir(char **info_lidar);
float *get_values(char **info_lidar);
void get_dir(float *values, int pos);
int check_val(float *values, int min, int max);
int check_front(float *values);
void check_end(char *resp);
void check_info(char *info);
void get_speed(float middle);
void to_left(float middle);
void to_right(float middle);
char *exec_cmd(char *str);
int check_dead_end(char **info_lidar);
int check_sim(char *str);
void simulation(void);

#endif
