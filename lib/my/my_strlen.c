/*
** my_strlen.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 15 02:05:46 2016 Jean PLANCHER
** Last update Wed May 18 17:38:30 2016 Jean PLANCHER
*/

#include "my.h"

size_t			my_strlen(const char *s)
{
  register const char	*str;

  if (!s || !*s)
    return (0);
  str = s;
  while (*++str);
  return (str - s);
}
