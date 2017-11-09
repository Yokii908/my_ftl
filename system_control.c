/*
** system_control.c for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Tue Nov  7 13:41:28 2017 COQUARD Alexis
** Last update Tue Nov  7 13:41:28 2017 COQUARD Alexis
*/

#include "system_control.h"

void ftl_drive_system_check(t_ship *ship)
{
	my_putstr("verification du reacteur en cours...\n");
	if (my_strcmp(ship->ftl_drive->system_state, "online") == 0)
	{
		my_putstr("reacteur OK!\n");
	}
	else
	{
		my_putstr("reacteur hors service!\n");
	}
}

void navigation_tools_system_check(t_ship *ship)
{
	my_putstr("verification du systeme de navigation en cours...\n");
	if (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
	{
		my_putstr("systeme de navigation OK!\n");
	}
	else
	{
		my_putstr("systeme de navigation hors service!\n");
	}
}

void weapon_system_check(t_ship *ship)
{
	my_putstr("verification du systeme d'armement en cours...\n");
	if (my_strcmp(ship->weapon->system_state, "online") == 0)
	{
		my_putstr("systeme d'armement OK!\n");
	}
	else
	{
		my_putstr("systeme d'armement hors service!\n");
	}
}

void system_control(t_ship *ship)
{
	ftl_drive_system_check(ship);
	navigation_tools_system_check(ship);
	weapon_system_check(ship);
}
