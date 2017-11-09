/*
** sector.c for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 17:26:14 2017 COQUARD Alexis
** Last update Thu Nov  9 17:26:14 2017 COQUARD Alexis
*/

#include "sector.h"

static t_ennemy next_ennemy = {20, 10};

void jump_to_next_sector(t_ship *ship)
{
	if (!check_jump_availability(ship))
		return;
	int rand;
	t_sector *sector = malloc(sizeof(t_sector));
	sector->ennemy = NULL;
	sector->freights_found = 0;
	ship->navigation_tools->sector = ship->navigation_tools->sector + 1;
	rand = (random() % 100);
	if (rand < 30)
	{
		t_ennemy *new_ennemy = malloc(sizeof(t_ennemy));
		new_ennemy->hull = next_ennemy.hull;
		new_ennemy->damage = next_ennemy.damage;
		sector->ennemy = new_ennemy;
		my_putstr_color("red", "An ennemy has been detected in this sector !\n");
		display_ennemy_info(new_ennemy);
		next_ennemy.hull *= 1.5;
		next_ennemy.damage *= 1.5;
	}
	set_sector_freights(sector);
	free_sector(ship->current_sector);
	ship->current_sector = sector;
	ship->ftl_drive->energy--;
	display_sector_info(ship);
}

int check_jump_availability(t_ship *ship)
{
	if (ship->current_sector != NULL && ship->current_sector->ennemy != NULL)
	{
		my_putstr_color("red", "You can't jump ! You are still under attack !\n");
		return (0);
	}
	else if (my_strcmp(ship->ftl_drive->system_state, "online") != 0)
	{
		my_putstr_color("red", "You can't jump ! You're engine is offline");
		return (0);
	}
	return (1);
}

void display_sector_info(t_ship *ship)
{
	my_putstr_color("blue", "Jumping to sector ");
	my_put_nbr(ship->navigation_tools->sector);
	my_putstr("\n");
	my_put_nbr(ship->ftl_drive->energy);
	my_putstr_color("yellow", " energy left\n");
}

void set_sector_freights(t_sector *sector)
{
	int i;
	int rand;
	char *bonus[] = {"energy", "attackbonus", "evadebonus"};

	i = 0;
	while (i < 10)
	{
		t_freight *new_freight = malloc(sizeof(t_freight));
		rand = random() % 100;
		if (rand <= 70)
			new_freight->item = my_strdup("scrap");
		else
		{
			rand = random() % 100;
			if (rand == 0)
				new_freight->item = my_strdup("scrap");
			else
			{
				rand = random() % 3;
				new_freight->item = my_strdup(bonus[rand]);
			}
		}
		sector->sector_freights[i] = new_freight;
		i++;
	}
}
