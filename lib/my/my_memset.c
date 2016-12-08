/*
** my_memset.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 15 02:05:18 2016 Jean PLANCHER
** Last update Fri Apr 15 02:05:20 2016 Jean PLANCHER
*/

#include "my.h"

void            *my_memset(void *s, int c, size_t n)
{
  unsigned int  ch;
  unsigned char *dest;
  unsigned int  count;

  dest = s;
  count = 0;
  ch = c;
  ch = (ch << 8) | ch;
  ch = (ch << 16) | ch;
  while (count + INT_SIZE <= n)
    {
      *(unsigned int *)dest = ch;
      dest += INT_SIZE;
      count += INT_SIZE;
    }
  while (count < n)
    {
      *dest++ = c;
      count += 1;
    }
  return (s);
}
