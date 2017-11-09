/*
** air_shed.c for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 17:38:34 2017 COQUARD Alexis
** Last update Thu Nov  9 17:38:34 2017 COQUARD Alexis
*/

#include "air_shed.h"

t_ship* create_ship()
{
	t_ship *ship = malloc(sizeof(t_ship));
	my_putstr("construction du vaisseau en cours...\n");
	if (ship == NULL)
	{
		my_putstr("le vaisseau n'a pas pu etre construit par manque de materiaux\n");
		return (0);
	}
	my_putstr("amelioration du vaisseau termine!\n");
	ship->hull = 50;
	ship->weapon = NULL;
	ship->ftl_drive = NULL;
	ship->navigation_tools = NULL;
	ship->container = NULL;
	ship->current_sector = NULL;
	return (ship);
}

int add_navigation_tools_to_ship(t_ship *ship)
{
	my_putstr("ajout des outils de navigations...\n");
	t_navigation_tools *navigation_tools = malloc(sizeof(t_navigation_tools));
	if (navigation_tools == NULL)
	{
		my_putstr("votre vaisseau a explosé");
		my_putstr("lorsque vous avez pose les outils de navigations\n");
		return (0);
	}
	navigation_tools->evade = 25;
	navigation_tools->sector = -1;
	navigation_tools->system_state = my_strdup("online");
	ship->navigation_tools = navigation_tools;
	my_putstr("les outils de navigations ont ete ajoutes avec succes!\n");
	return (1);
}

int add_weapon_to_ship(t_ship *ship)
{
	my_putstr("ajout des armes en cours...\n");
	t_weapon *weapon = malloc(sizeof(t_weapon));
	if (weapon == NULL)
	{
		my_putstr("votre vaisseau a explosé");
		my_putstr("quand vous avez tente d'ajouter les armes\n");
		return (0);
	}
	weapon->damage = 10;
	weapon->system_state = my_strdup("online");
	ship->weapon = weapon;
	my_putstr("les armes on ete ajoutes avec succes!\n");
	return (1);
}

int add_ftl_drive_to_ship(t_ship *ship)
{
	my_putstr("ajout du reacteur en cours...\n");
	t_ftl_drive *ftl_drive = malloc(sizeof(t_ftl_drive));
	if (ftl_drive == NULL)
	{
		my_putstr("votre vaisseau a explose lorsque vous avez pose le reacteur\n");
		return (0);
	}
	ftl_drive->energy = 10 + 1;
	ftl_drive->system_state = my_strdup("online");
	ship->ftl_drive = ftl_drive;
	my_putstr("le reacteur a ete ajoute avec succes!\n");
	return (1);
}
