#include "display.h"

void			my_putchar(const char c)
{
  write(1, &c, 1);
}

int			my_strlen(const char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
