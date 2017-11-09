/*
** commands.c for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 16:27:24 2017 COQUARD Alexis
** Last update Thu Nov  9 16:27:24 2017 COQUARD Alexis
*/

#include "commands.h"

void stat(t_ship *ship)
{
	my_putstr("Stats\n\n");
	my_putstr("Hull : ");
	my_put_nbr(ship->hull);
	my_putstr("\nWeapon : ");
	my_putstr("\nDamage : ");
	my_put_nbr(ship->weapon->damage);
	my_putstr("\n\nNavigation : ");
	my_putstr("\nEvade : ");
	my_put_nbr(ship->navigation_tools->evade);
	my_putstr("\n\nDrive : ");
	my_putstr("\nEnergy : ");
	my_put_nbr(ship->ftl_drive->energy);
	my_putstr("\n");
}

void control_system(t_ship *ship)
{
	char *weapon_color;
	char *nav_color;
	char *drive_color;

	weapon_color = (my_strcmp(ship->weapon->system_state, "online") == 0)
	? "green" : "red";
	nav_color = (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
	? "green" : "red";
	drive_color = (my_strcmp(ship->ftl_drive->system_state, "online") == 0)
	? "green" : "red";
	my_putstr("Systems state\n");
	my_putstr("\nWeapon : ");
	my_putstr_color(weapon_color, ship->weapon->system_state);
	my_putstr("\nNavigation : ");
	my_putstr_color(nav_color, ship->navigation_tools->system_state);
	my_putstr("\nDrive : ");
	my_putstr_color(drive_color, ship->ftl_drive->system_state);
	my_putstr("\n");
}
