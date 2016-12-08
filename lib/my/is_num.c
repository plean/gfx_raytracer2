/*
** is_num.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 15 00:17:17 2016 Jean PLANCHER
** Last update Fri Apr 15 00:17:18 2016 Jean PLANCHER
*/


#include "my.h"

int	is_alpha(const char *str, char c)
{
  int	i;

  i = -1;
  if (str == NULL || !str[0])
    return (0);
  if (str[0] == '-' && c != '+')
    i++;
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
    }
  return (1);
}
