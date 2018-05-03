/*
** EPITECH PROJECT, 2017
** utilities.c
** File description:
** utility functions
*/

#include "ai.h"

int my_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i = i + 1;
	return (i);
}

char *my_strcat(char *str1, char *str2)
{
	char *final = malloc(sizeof(char) *
		(my_strlen(str1) + my_strlen(str2) + 1));
	int x = 0;
	int y = 0;

	while (str1[x]) {
		final[x] = str1[x];
		x = x + 1;
	}
	final[x] = '\0';
	while (str2[y]) {
		final[x] = str2[y];
		x = x + 1;
		y = y + 1;
	}
	final[x] = '\0';
	return (final);
}

int my_strcmp(char *str1, char *str2)
{
	int x = 0;

	while (str2[x]) {
		if (str1[x] == str2[x])
			x = x + 1;
		else
			break;
	}
	if (x == my_strlen(str2))
		return (1);
	else
		return (0);
}

char *my_strdup(char *str)
{
	char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));
	int x = 0;

	while (str[x]) {
		dest[x] = str[x];
		x = x + 1;
	}
	dest[x] = '\0';
	return (dest);
}

char *my_cleanstr(char *str)
{
	int x = 0;
	int y = 0;
	char *dest = malloc(sizeof(char) * my_strlen(str) + 1);

	for (x = 0; str[x]; x = x + 1) {
		if (str[x] == ' ' || str[x] == '\t')
			continue;
		dest[y] = str[x];
		y = y + 1;
	}
	dest[y] = '\0';
	return (dest);
}
