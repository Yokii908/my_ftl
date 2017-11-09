/*
** air_shed.h for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Tue Nov  7 12:56:45 2017 COQUARD Alexis
** Last update Tue Nov  7 12:56:45 2017 COQUARD Alexis
*/

#ifndef __AIR_SHRED_H__
#define __AIR_SHRED_H__

#include "ftl.h"
#include "my_string.h"

t_ship* create_ship();
int add_navigation_tools_to_ship(t_ship *ship);
int add_weapon_to_ship(t_ship *ship);
int add_ftl_drive_to_ship(t_ship *ship);

#endif
