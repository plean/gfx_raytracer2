/*
** my_memcpy.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 15 02:05:25 2016 Jean PLANCHER
** Last update Fri Apr 15 02:05:26 2016 Jean PLANCHER
*/

#include "my.h"

void		*my_memcpy(void *dest, const void *src, size_t n)
{
  size_t	i;
  char		*s1;
  char		*s2;

  i = 0;
  s1 = (char *)dest;
  s2 = (char *)src;
  while (i < n)
    {
      s1[i] = s2[i];
      i += 1;
    }
  return (s1);;
}
