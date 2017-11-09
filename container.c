/*
** container.c for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 10:48:37 2017 COQUARD Alexis
** Last update Thu Nov  9 10:48:37 2017 COQUARD Alexis
*/

#include <stdio.h>
#include "container.h"
#include "bonus.h"

static const t_bonus g_bonus[] =
{
	{"attackbonus", attackbonus},
	{"evadebonus", evadebonus},
	{"energy", energy},
	{"scrap", scrap},
	{NULL, NULL}
};

int add_container_to_ship(t_ship *ship)
{
	my_putstr("ajout du container en cours...\n");
	t_container *container = malloc(sizeof(t_container));
	if (container == NULL)
	{
		my_putstr("votre vaisseau a explose lorsque vous avez pose le container\n");
		return (0);
	}
	container->first = NULL;
	container->last = NULL;
	container->nb_elem = 0;
	ship->container = container;
	my_putstr("le container a ete ajoute avec succes!\n");
	return (1);
}

void add_freight_to_container(t_ship *ship, t_freight *freight)
{
	freight->next = NULL;
	freight->prev = NULL;
	if (ship->container->last == NULL)
	{
		ship->container->first = freight;
	}
	else
	{
		freight->prev = ship->container->last;
		ship->container->last->next = freight;
	}
	ship->container->last = freight;
	ship->container->nb_elem++;
}

void del_freight_to_container(t_ship *ship, t_freight *freight)
{
	if (freight->prev != NULL)
		freight->prev->next = freight->next;
	else
		ship->container->first = freight->next;
	if (freight->next != NULL)
		freight->next->prev = freight->prev;
	else
		ship->container->last = freight->prev;
	free(freight->item);
	free(freight);
	ship->container->nb_elem--;
}

void get_bonus(t_ship *ship)
{
	int i;
	t_freight *tmp = ship->container->first;

	i = 0;
	while (tmp != NULL)
	{
		while (g_bonus[i].bonus_name != NULL &&
			my_strcmp(g_bonus[i].bonus_name, tmp->item) != 0)
		{
			i++;
		}
		if (g_bonus[i].affect_bonus != NULL)
		{
			g_bonus[i].affect_bonus(ship);
			del_freight_to_container(ship, tmp);
		}
		i = 0;
		tmp = tmp->next;
	}
}
