/*
** system_control.h for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Wed Nov  8 16:37:02 2017 COQUARD Alexis
** Last update Wed Nov  8 16:37:02 2017 COQUARD Alexis
*/

#ifndef __SYSTEM_CONTROL_H__
#define __SYSTEM_CONTROL_H__

#include "ftl.h"
#include "my_string.h"

void ftl_drive_system_check(t_ship *ship);
void navigation_tools_system_check(t_ship *ship);
void weapon_system_check(t_ship *ship);
void system_control(t_ship *ship);

#endif
