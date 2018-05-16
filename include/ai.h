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

#endif
