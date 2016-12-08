/*
** spec.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/scenes/create_scene/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat May 21 18:50:38 2016 Jean PLANCHER
** Last update Sat May 21 19:17:56 2016 Jean PLANCHER
*/

#include "my.h"

static void	get_spec_light(t_object *object)
{
  char		*str;

  printf("Enter the ambient lighting of the light,"
	 " it must be between 0 and 1:\n");
  if ((str = get_next_line(0)) && strncpy(object->ia, str, 5))
    free(str);
  printf("Enter the diffuse intensities of the light,"
	 " it must be between 0 and 1:\n");
  if ((str = get_next_line(0)) && strncpy(object->id, str, 5))
    free(str);
  printf("Enter the specular intensities of the light,"
	 " it must be between 0 and 1:\n");
  if ((str = get_next_line(0)) && strncpy(object->is, str, 5))
    free(str);
}

static void	get_spec_object(t_object *object)
{
  char		*str;

  printf("Enter the ambient reflection of the object,"
	 " it must be between 0 and 1:\n");
  if ((str = get_next_line(0)) && strncpy(object->ka, str, 5))
    free(str);
  printf("Enter the diffuse reflection of the object,"
	 " it must be between 0 and 1:\n");
  if ((str = get_next_line(0)) && strncpy(object->kd, str, 5))
    free(str);
  printf("Enter the specular reflection of the object,"
	 " it must be between 0 and 1:\n");
  if ((str = get_next_line(0)) && strncpy(object->ks, str, 5))
    free(str);
  printf("Enter the shininess of the object,"
	 " it must be positive and smaller than 9999\n");
  if ((str = get_next_line(0)) && strncpy(object->alpha, str, 5))
    free(str);
}

void	get_spec(t_object *object)
{
  printf("Enter the type of the object:\n");
  if (!strcmp(object->type, "light"))
    get_spec_light(object);
  else
    get_spec_object(object);
}
