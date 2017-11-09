/*
** attack.c for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 17:27:55 2017 COQUARD Alexis
** Last update Thu Nov  9 17:27:55 2017 COQUARD Alexis
*/

#include "attack.h"

void attack(t_ship *ship)
{
	if (!check_attack_availability(ship))
		return;
	ship->current_sector->ennemy->hull -= ship->weapon->damage;
	if (ship->current_sector->ennemy->hull <= 0)
	{
		my_putstr_color("green", "You destroyed the ennemy\n");
		free(ship->current_sector->ennemy);
		ship->current_sector->ennemy = NULL;
		if ((random() % 2) == 0)
		{
			my_putstr_color("yellow", "You lose 1 energy\n");
			ship->ftl_drive->energy--;
		}
	}
	else
	{
		display_ennemy_info(ship->current_sector->ennemy);
		ennemy_attack(ship);
	}
}

int check_attack_availability(t_ship *ship)
{
	if (my_strcmp(ship->weapon->system_state, "online") != 0)
	{
		my_putstr_color("yellow", "You can't attack because your weapon is offline");
		return (0);
	}
	if (ship->current_sector->ennemy == NULL)
	{
		my_putstr_color("yellow", "You can't attack !");
		my_putstr_color("yellow", "There is no one around you !\n");
		return (0);
	}
	return (1);
}

void ennemy_attack(t_ship *ship)
{
	int rand;

	my_putstr_color("red", "Ennemy shots back...\n");
	rand = random() % 100;
	if (rand < ship->navigation_tools->evade)
	{
		my_putstr_color("yellow", "You managed to dodge the attack\n");
	}
	else
	{
		ship->hull -= ship->current_sector->ennemy->damage;
		if (ship->hull < 0)
			ship->hull = 0;
		my_putstr_color("red", "You've been hit !\n");
		my_putstr_color("yellow", "Hull integrity is now ");
		my_put_nbr(ship->hull);
		my_putstr_color("yellow", "%\n");
		if ((random() % 100) < 20)
		{
			randomly_damage_system(ship);
		}
	}
}

void randomly_damage_system(t_ship *ship)
{
	int rand;

	rand = random() % 10;
	if (rand < 2)
	{
		rand = random() % 3;
		if (rand == 0)
		{
			my_putstr_color("yellow", "Your weapon system broke down\n");
			free(ship->weapon->system_state);
			ship->weapon->system_state = my_strdup("offline");
		}
		else if (rand == 1)
		{
			my_putstr_color("yellow", "Your navigation system broke down\n");
			free(ship->navigation_tools->system_state);
			ship->navigation_tools->system_state = my_strdup("offline");
		}
		else
		{
			my_putstr_color("yellow", "Your weapon system broke down\n");
			free(ship->ftl_drive->system_state);
			ship->ftl_drive->system_state = my_strdup("offline");
		}
	}
}

void display_ennemy_info(t_ennemy *ennemy)
{
	my_putstr("Ennemy's stats\n");
	my_putstr("Hull : ");
	my_put_nbr(ennemy->hull);
	my_putstr("\nDamage : ");
	my_put_nbr(ennemy->damage);
	my_putstr("\n");
}
