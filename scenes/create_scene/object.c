/*
** object.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/scenes/create_scene/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue May 10 15:56:43 2016 Jean PLANCHER
** Last update Sat May 21 18:50:30 2016 Jean PLANCHER
*/

#include "my.h"

static void	get_color(t_object *object)
{
  char		*str;

  printf("Enter the color in hex of the object:\n");
  while ((str = get_next_line(0)))
    {
      if (strtoul(str, NULL, 16) > 0xFFFFFFFF)
	printf("Type's too long, it must be smaller than FFFFFFFF.\n");
      else
	{
	  strcpy(object->color, str);
	  free(str);
	  return ;
	}
      free(str);
    }
}

static void	get_vec(t_object *object, int nb)
{
  char		*str;

  printf("Enter the x pos of the vec%d, it must be smaller than 10000:\n", nb);
  str = get_next_line(0);
  if (str)
    {
      strncpy((nb == 1) ? object->vec1x : object->vec2x, str, 6);
      free(str);
    }
  printf("Enter the y pos of the vec%d, it must be smaller than 10000:\n", nb);
  str = get_next_line(0);
  if (str)
    {
      strncpy((nb == 1) ? object->vec1y : object->vec2y, str, 6);
      free(str);
    }
  printf("Enter the z pos of the vec%d, it must be smaller than 10000:\n", nb);
  str = get_next_line(0);
  if (str)
    {
      strncpy((nb == 1) ? object->vec1z : object->vec2z, str, 6);
      free(str);
    }
}

static void	get_pos(t_object *object)
{
  char		*str;

  printf("Enter the x pos of the object, it must be smaller than 10000:\n");
  str = get_next_line(0);
  if (str)
    {
      strncpy(object->posx, str, 6);
      free(str);
    }
  printf("Enter the y pos of the object, it must be smaller than 10000:\n");
  str = get_next_line(0);
  if (str)
    {
      strncpy(object->posy, str, 6);
      free(str);
    }
  printf("Enter the z pos of the object, it must be smaller than 10000:\n");
  str = get_next_line(0);
  if (str)
    {
      strncpy(object->posz, str, 6);
      free(str);
    }
}

static void	get_type(t_object *object)
{
  char		*str;

  printf("Enter the type of the object:\n");
  while ((str = get_next_line(0)))
    {
      if (strlen(str) >= 10)
	printf("Type's too long, it must be smaller than 10.\n");
      else
	{
	  strcpy(object->type, str);
	  free(str);
	  return ;
	}
      free(str);
    }
}

void	do_object(t_object *object)
{
  char	*str;

  get_type(object);
  get_pos(object);
  get_vec(object, 1);
  get_vec(object, 2);
  printf("Enter the size of the ray, it must be smaller than 100000:\n");
  str = get_next_line(0);
  if (str)
    {
      strncpy(object->ray, str, 6);
      free(str);
    }
  get_color(object);
  get_spec(object);
}
