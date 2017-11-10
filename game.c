/*
** game.c for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 17:30:54 2017 COQUARD Alexis
** Last update Thu Nov  9 17:30:54 2017 COQUARD Alexis
*/

#include "game.h"

static const t_action g_action[] =
{
	{"stat", stat},
	{"control_system", control_system},
	{"repair_system", system_repair},
	{"jump", jump_to_next_sector},
	{"attack", attack},
	{"detect", detect},
	{"getbonus", get_bonus},
	{NULL, NULL}
};

void start_game()
{
	t_ship *ship = create_ship();
	add_weapon_to_ship(ship);
	add_ftl_drive_to_ship(ship);
	add_navigation_tools_to_ship(ship);
	add_container_to_ship(ship);
	jump_to_next_sector(ship);
	while (ship->hull > 0 && ship->ftl_drive->energy > 0
		&& ship->navigation_tools->sector < 10)
	{
		ask_command(ship);
	}
	check_for_victory(ship);
	free_ship(ship);
}

void free_ship(t_ship *ship)
{
	free(ship->weapon->system_state);
	free(ship->ftl_drive->system_state);
	free(ship->navigation_tools->system_state);
	free(ship->weapon);
	free(ship->ftl_drive);
	free(ship->navigation_tools);
	free_sector(ship->current_sector);
	free_container(ship->container);
}

void ask_command(t_ship *ship)
{
	int i;

	i = 0;
	my_putstr("~>");
	char *user_command = readline();
	if (user_command == NULL)
	{
		my_putstr_color("red", "[SYSTEM FAILURE]");
		my_putstr_color("red", " : le lecteur de commande est bloquée\n");
	}
	else
	{
		while (g_action[i].command != NULL
			&& my_strcmp(user_command, g_action[i].command) != 0)
			i++;
		if (g_action[i].execute != NULL)
		{
			g_action[i].execute(ship);
			free(user_command);
		}
		else
		{
			my_putstr_color("red", "[SYSTEM FAILURE] : commande inconnue\n");
		}
	}
}

void check_for_victory(t_ship *ship)
{
	if (ship->hull <= 0)
		my_putstr_color("red", "Your ship exploded.\n");
	else if (ship->ftl_drive->energy <= 0
		&& ship->navigation_tools->sector != 10)
		my_putstr_color("red", "You have no energy left and are lost in space.\n");
	else
		my_putstr_color("green", "Congratulations ! You reached 10th sector !\n");
}
