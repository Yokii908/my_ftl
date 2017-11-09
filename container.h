/*
** container.h for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
**
** Made by COQUARD Alexis
** Login   <coquar_a@etna-alternance.net>
**
** Started on  Thu Nov  9 11:17:26 2017 COQUARD Alexis
** Last update Thu Nov  9 11:17:26 2017 COQUARD Alexis
*/

#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "ftl.h"
#include "my_string.h"

int add_container_to_ship(t_ship *ship);
void add_freight_to_container(t_ship *ship, t_freight *freight);
void del_freight_to_container(t_ship *ship, t_freight *freight);
void count(t_ship *ship);
void get_bonus(t_ship *ship);

#endif
