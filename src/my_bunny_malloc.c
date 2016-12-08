/*
** my_bunny_malloc.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/src/list/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon May 16 15:56:39 2016 Jean PLANCHER
** Last update Tue May 31 16:17:21 2016 Jean PLANCHER
*/

#include "my.h"

void	*my_malloc(size_t nb)
{
  void	*tmp;

  if ((tmp = malloc(nb)) == NULL)
    {
      write(2, "Error: Malloc Failed\n", 21);
      my_exit(42);
    }
  return (tmp);
}

void	*my_bunny_malloc(size_t nb)
{
  void	*tmp;

  if ((tmp = bunny_malloc(nb)) == NULL)
    {
      write(2, "Error: Malloc Failed\n", 21);
      my_exit(42);
    }
  return (tmp);
}
