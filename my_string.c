/*
** my_string.h for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Wed Nov  8 20:50:51 2017 COQUARD Alexis
** Last update Wed Nov  8 20:50:51 2017 COQUARD Alexis
*/

#include "my_string.h"

const char		*reset_color = "\033[0m";

typedef			struct s_color	t_color;

struct			s_color
{
  char			*color;
  char			*unicode;
};

static const t_color	g_color[] =
  {
    {"clear", "\033[H\033[2J"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {NULL, NULL}
  };

void			my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}

int			my_strcmp(const char *s1, const char *s2)
{
  int			i;

  if (s1 == NULL || s2 == NULL)
    return (-2);
  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (1);
      else if (s1[i] < s2[i])
	return (-1);
      i++;
    }
  if (s2[i] != '\0')
    return (-1);
  return (0);
}

char			*my_strdup(const char *str)
{
  int			i;
  char			*copy;

  i = 0;
  copy = NULL;
  if ((copy = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      copy[i] = str[i];
      i++;
    }
  copy[i] = '\0';
  return (copy);
}

void			my_putstr_color(const char *color, const char *str)
{
  int			i;

  i = 0;
  while (g_color[i].color != NULL && (my_strcmp(g_color[i].color, color) != 0))
    i++;
  if (g_color[i].color == NULL)
    {
      my_putstr(str);
      return ;
    }
  my_putstr(g_color[i].unicode);
  my_putstr(str);
  my_putstr(reset_color);
}

char    *readline(void)
{
  ssize_t ret;
  char    *buff;

  if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  free(buff);
  return (NULL);
}

void  my_put_nbr(int n)
{
  int res;
  res = 0;
  if (n == -2147483648)
    {
      my_putstr("-2147483648");
    }
  else
    {
      if (n < 0)
    {
      my_putchar('-');
      n *= -1;
    }

      if (n >= 10)
    {
      res = (n % 10);
      n = (n - res) / 10;
      my_put_nbr(n);
      my_putchar(res + 48);
    }
      else
  my_putchar(n % 10 + 48);
    }
}
