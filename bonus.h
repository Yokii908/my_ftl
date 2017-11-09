/*
** bonus.h for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Wed Nov  8 16:35:43 2017 COQUARD Alexis
** Last update Wed Nov  8 16:35:43 2017 COQUARD Alexis
*/

#ifndef __BONUS_H__
#define __BONUS_H__

#include "ftl.h"
#include "my_string.h"

void attackbonus(t_ship *ship);
void evadebonus(t_ship *ship);
void energy(t_ship *ship);
void scrap(t_ship *ship);

typedef struct s_bonus
{
	char *bonus_name;
	void (*affect_bonus)(t_ship*);
} t_bonus;

#endif
