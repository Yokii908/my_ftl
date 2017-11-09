/*
** sector.h for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 16:30:51 2017 COQUARD Alexis
** Last update Thu Nov  9 16:30:51 2017 COQUARD Alexis
*/

#ifndef __SECTOR_H__
#define __SECTOR_H__

#include <time.h>
#include <stdlib.h>
#include "ftl.h"
#include "my_string.h"
#include "container.h"
#include "free.h"
#include "attack.h"

void jump_to_next_sector(t_ship *ship);
void display_sector_info(t_ship *ship);
int check_jump_availability(t_ship *ship);
void set_sector_freights(t_sector *sector);

#endif
