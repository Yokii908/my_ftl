/*
** bonus.c for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 16:20:11 2017 COQUARD Alexis
** Last update Thu Nov  9 16:20:11 2017 COQUARD Alexis
*/

#include "bonus.h"

void attackbonus(t_ship *ship)
{
	my_putstr_color("green", "Upgrading weapon... ! (");
	my_put_nbr(ship->weapon->damage);
	my_putstr(" ~> ");
	ship->weapon->damage += 5;
	my_put_nbr(ship->weapon->damage);
	my_putstr(")\n");
}

void evadebonus(t_ship *ship)
{
	my_putstr_color("green", "Upgrading evading rate... !(");
	my_put_nbr(ship->navigation_tools->evade);
	my_putstr(" ~> ");
	ship->navigation_tools->evade += 3;
	my_put_nbr(ship->navigation_tools->evade);
	my_putstr(")\n");
}

void energy(t_ship *ship)
{
	my_putstr_color("green", "Energy found ! (");
	my_put_nbr(ship->ftl_drive->energy);
	my_putstr(" ~> ");
	ship->ftl_drive->energy += 1;
	my_put_nbr(ship->ftl_drive->energy);
	my_putstr(")\n");
}

void scrap()
{
	my_putstr_color("yellow", "Ew... some scrap again...\n");
}
