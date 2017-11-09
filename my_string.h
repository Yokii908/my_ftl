/*
** my_string.h for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Wed Nov  8 20:50:51 2017 COQUARD Alexis
** Last update Wed Nov  8 20:50:51 2017 COQUARD Alexis
*/

#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	my_putchar(const char c);
void	my_putstr(const char *str);
void 	my_put_nbr(int n);
char	*my_strcpy(const char *dest, const char *src);
char	*my_strdup(const char *str);
int 	my_strcmp(const char *s1, const char *s2);
char    *readline(void);
void	my_putstr_color(const char *color, const char *str);

#endif
