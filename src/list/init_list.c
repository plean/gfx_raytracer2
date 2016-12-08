/*
** init_list.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/src/list/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 15 17:33:58 2016 Jean PLANCHER
** Last update Mon May  9 14:32:55 2016 Jean PLANCHER
*/

#include "my.h"

t_list		*my_list(void *tmp)
{
  static t_list	*list = NULL;

  if (tmp == NULL)
    return (list);
  if (list == NULL)
    list = create_list();
  add_end(&list, tmp);
  return (NULL);
}
