/*
** free.c for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 15:45:49 2017 COQUARD Alexis
** Last update Thu Nov  9 15:45:49 2017 COQUARD Alexis
*/

#include "free.h"
#include "my_string.h"

void free_sector(t_sector *sector)
{
	if (sector != NULL)
	{
		free(sector->ennemy);
		free(sector);
	}
}

void free_container(t_container *container)
{
	t_freight *tmp = container->first;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(container);
}
