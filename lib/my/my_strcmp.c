/*
** my_strcmp.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 15 02:05:32 2016 Jean PLANCHER
** Last update Fri Apr 15 02:05:34 2016 Jean PLANCHER
*/

#include "my.h"

int		my_strcmp(const char *s1, const char *s2)
{
  const char	*s3;
  const char	*s4;

  s3 = s1;
  s4 = s2;
  while (*s3 == *s4)
    {
      s3++;
      s4++;
      if (!*s3)
	return (*s3 - *s4);
    }
  return (*s3 - *s4);
}

int			my_strncmp(const char *s1, const char *s2, size_t n)
{
  register const char	*s3;
  register const char	*s4;

  s3 = s1;
  s4 = s2;
  while (*s3 == *s4 && (unsigned)(s4 - s2) < n)
    {
      s3++;
      s4++;
      if (!*s3)
	return (*s3 - *s4);
    }
  return (*s3 - *s4);
}
