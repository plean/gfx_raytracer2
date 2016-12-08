/*
** header.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/scenes/create_scene/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue May 10 15:55:20 2016 Jean PLANCHER
** Last update Fri May 13 17:18:14 2016 Jean PLANCHER
*/

#include "my.h"

static void	get_name(t_header *header)
{
  char		*str;

  printf("Enter the name of your file:\n");
  while ((str = get_next_line(0)))
    {
      if (strlen(str) >= 100)
	printf("Name's too long, it must be smaller than 100.\n");
      else
	{
	  strcpy(header->name, str);
	  free(str);
	  return ;
	}
      free(str);
    }
}

static void	get_objects(t_header *header)
{
  char		*str;

  printf("Enter the number of objects:\n");
  while ((str = get_next_line(0)))
    {
      if (atoi(str) >= 1000000)
	printf("Number of objects is too long, it must be smaller than 1000000.\n");
      else
	{
	  strcpy(header->objects, str);
	  free(str);
	  return ;
	}
      free(str);
    }
}

void	do_header(t_header *header)
{
  get_name(header);
  get_objects(header);
  strcpy(header->magic, MAGIC);
}
