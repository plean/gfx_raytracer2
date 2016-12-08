/*
** my_strcpy.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 15 02:05:38 2016 Jean PLANCHER
** Last update Fri Apr 15 02:05:41 2016 Jean PLANCHER
*/

#include "my.h"

char	*my_strcpy(char *dest, const char *src)
{
  char	*s;

  s = dest;
  while ((*s++ = *src++));
  return (dest);
}

char	*my_strncpy(char *dest, const char *src, size_t n)
{
  char	*s;

  s = dest;
  while ((*s++ = *src++) && (unsigned)(s - dest) < n);
  *s = 0;
  return (dest);
}
