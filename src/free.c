/*
** free.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue May 17 13:39:59 2016 Jean PLANCHER
** Last update Tue May 17 13:40:31 2016 Jean PLANCHER
*/

#include "my.h"

void	my_free(void **tmp)
{
  free(*tmp);
}
