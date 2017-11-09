/*
** attack.h for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 16:50:14 2017 COQUARD Alexis
** Last update Thu Nov  9 16:50:14 2017 COQUARD Alexis
*/

#ifndef __ATTACK_H__
#define __ATTACK_H__

#include "ftl.h"
#include "my_string.h"

void attack(t_ship *ship);
void ennemy_attack(t_ship *ship);
void display_ennemy_info(t_ennemy *ennemy);
int check_attack_availability(t_ship *ship);
void randomly_damage_system(t_ship *ship);

#endif
