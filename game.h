/*
** game.h for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 11:45:22 2017 COQUARD Alexis
** Last update Thu Nov  9 11:45:22 2017 COQUARD Alexis
*/

#ifndef __GAME_H__
#define __GAME_H__

#include "air_shed.h"
#include "container.h"
#include "system_repair.h"
#include "commands.h"
#include "sector.h"

void start_game();
void ask_command(t_ship *ship);
void check_for_victory(t_ship *ship);
void free_ship(t_ship *ship);

#endif
