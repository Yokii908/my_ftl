/*
** detect.c for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 16:31:50 2017 COQUARD Alexis
** Last update Thu Nov  9 16:31:50 2017 COQUARD Alexis
*/

#include "detect.h"

void detect(t_ship *ship)
{
	int i;

	if (my_strcmp(ship->navigation_tools->system_state, "online") != 0)
	{
		my_putstr_color("yellow", "You can't detect");
		my_putstr_color("yellow", "because your navigation tools are offline\n");
		return;
	}
	if (ship->current_sector->freights_found != 0)
		my_putstr_color("yellow", "No freights left in this sector\n");
	else
	{
		i = 0;
		while (i < 10)
		{
			add_freight_to_container(ship, ship->current_sector->sector_freights[i]);
			i++;
		}
		my_putstr_color("green", "10 freights have been found !\n");
		ship->current_sector->freights_found = 1;
	}
}
