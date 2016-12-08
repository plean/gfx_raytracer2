/*
** main.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/scenes/create_scene/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon May  9 17:56:08 2016 Jean PLANCHER
** Last update Sat May 21 21:09:44 2016 Jean PLANCHER
*/

#include "my.h"

int		main(void)
{
  FILE		*file;
  t_object	object;
  t_header	header;
  int		i;

  bzero(&header, sizeof(t_header));
  do_header(&header);
  if ((file = fopen(header.name, "w")) == NULL)
    {
      fprintf(stderr, "can't open %s\n", header.name);
      return (1);
    }
  fwrite(&header, sizeof(t_header), 1, file);
  i = -1;
  while (++i < atoi(header.objects))
    {
      bzero(&object, sizeof(t_object));
      do_object(&object);
      fwrite(&object, sizeof(t_object), 1, file);
    }
  return (0);
}
