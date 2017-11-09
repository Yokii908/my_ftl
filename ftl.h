/*
** ftl.h for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 11:37:08 2017 COQUARD Alexis
** Last update Thu Nov  9 11:37:08 2017 COQUARD Alexis
*/

#ifndef __FTL_H__
#define __FTL_H__

#include <stdlib.h>

typedef struct s_ennemy
{
	int hull;
	int damage;
} t_ennemy;

typedef struct s_freight
{
	char *item;
	struct s_freight *next;
	struct s_freight *prev;
} t_freight;

typedef struct s_sector
{
	t_ennemy *ennemy;
	t_freight *sector_freights[10];
	int freights_found;
} t_sector;

typedef struct s_container
{
	int nb_elem;
	t_freight *first;
	t_freight *last;
} t_container;

typedef struct s_navigation_tools
{
	int sector;
	int evade;
	char *system_state;
} t_navigation_tools;

typedef struct s_ftl_drive
{
	int energy;
	char *system_state;
} t_ftl_drive;

typedef struct s_weapon
{
	int damage;
	char *system_state;
} t_weapon;

typedef struct s_ship
{
	int hull;
	t_weapon *weapon;
	t_ftl_drive *ftl_drive;
	t_navigation_tools *navigation_tools;
	t_container *container;
	t_sector *current_sector;
} t_ship;

typedef struct s_repair_command
{
	char *command;
	void (*action)(t_ship*);
} t_repair_command;

#endif
