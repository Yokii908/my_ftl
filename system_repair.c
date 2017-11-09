/*
** system_repair.c for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Tue Nov  7 16:47:54 2017 COQUARD Alexis
** Last update Tue Nov  7 16:47:54 2017 COQUARD Alexis
*/

#include "system_repair.h"

static const t_repair_command g_repair_command[] =
{
	{"ftl_drive", ftl_drive_system_repair},
	{"navigation_tools", navigation_tools_system_repair},
	{"weapon", weapon_system_repair},
	{NULL, NULL}
};

void ftl_drive_system_repair(t_ship *ship)
{
	my_putstr("reparation du reacteur en cours...\n");
	free(ship->ftl_drive->system_state);
	ship->ftl_drive->system_state = my_strdup("online");
	if (ship->ftl_drive->system_state == NULL)
	{
		my_putstr("les reparations du reacteur ont echoue\n");
	}
	else
	{
		my_putstr("reparation termine! systeme reacteur OK!\n");
	}
}

void navigation_tools_system_repair(t_ship *ship)
{
	my_putstr("reparation du systeme de navigation en cours...\n");
	free(ship->navigation_tools->system_state);
	ship->navigation_tools->system_state = my_strdup("online");
	if (ship->navigation_tools->system_state == NULL)
	{
		my_putstr("les reparations des outils de navigations ont echoue\n");
	}
	else
	{
		my_putstr("reparation termine! systeme de navigation OK!\n");
	}
}

void weapon_system_repair(t_ship *ship)
{
	my_putstr("reparation du systeme d'armement en cours...\n");
	free(ship->weapon->system_state);
	ship->weapon->system_state = my_strdup("online");
	if (ship->weapon->system_state == NULL)
	{
		my_putstr("les reparations du systeme d'armement ont echoue\n");
	}
	else
	{
		my_putstr("reparation termine! systeme d'armement OK!\n");
	}
}

void system_repair(t_ship *ship)
{
	int i;

	i = 0;
	my_putstr("repair_system~>");
	char *command = readline();
	if (command == NULL)
		my_putstr("[SYSTEM FAILURE] : le lecteur de commande est bloque\n");
	else
	{
		while (g_repair_command[i].command != NULL
			&& my_strcmp(command, g_repair_command[i].command) != 0)
		{
			i++;
		}
		if (g_repair_command[i].action != NULL)
		{
			g_repair_command[i].action(ship);
			free(command);
		}
		else
		{
			my_putstr("[SYSTEM FAILURE] : commande inconnue\n");
		}
	}
}
