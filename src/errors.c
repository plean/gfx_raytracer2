/*
** errors.c for  in /home/planch_j/rendu/Info/gfx_raytracer1/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Wed Feb 24 14:37:57 2016 Jean PLANCHER
** Last update Wed May 11 17:56:39 2016 Jean PLANCHER
*/

#include "my.h"

int     file_errors(const char **av)
{
  int   test;

  if ((test = open(av[1], O_DIRECTORY)) != -1)
    {
      write(2, av[0], my_strlen(av[0]));
      write(2, ": ", 2);
      write(2, av[1], my_strlen(av[1]));
      write(2, ": Is a directory.\n", 18);
      return (1);
    }
  close(test);
  if ((test = open(av[1], O_RDONLY)) == -1)
    {
      write(2, av[0], my_strlen(av[0]));
      write(2, ": ", 2);
      write(2, av[1], my_strlen(av[1]));
      write(2, ": No such file or directory.\n", 29);
      return (1);
    }
  close(test);
  return (0);
}

int	aff_error(const char *str)
{
  int	i;

  write(2, "Error: ", 7);
  i = my_strlen(str);
  while (--i && str[i - 1] != '/');
  write(2, &str[i], my_strlen(&str[i]));
  write(2, " need a scene to work properly.\n", 32);
  return (1);
}
