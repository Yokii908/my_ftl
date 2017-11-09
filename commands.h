/*
** commands.h for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Wed Nov  8 22:29:36 2017 COQUARD Alexis
** Last update Wed Nov  8 22:29:36 2017 COQUARD Alexis
*/

#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "ftl.h"
#include "my_string.h"
#include "sector.h"

void stat(t_ship *ship);
void control_system(t_ship *ship);
void attack(t_ship *ship);
void ennemy_attack(t_ship *ship);
void detect(t_ship *ship);

typedef struct s_action
{
	char *command;
	void (*execute)(t_ship*);
} t_action;

#endif
