/*
** load_scene.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 15 00:31:55 2016 Jean PLANCHER
** Last update Tue May 31 16:16:30 2016 Jean PLANCHER
*/

#include "my.h"

static void	init_vec_pos(t_object *object, t_obj *obj)
{
  obj->pos = my_bunny_malloc(sizeof(t_3dpos));
  obj->vec1 = my_bunny_malloc(sizeof(t_vec));
  obj->vec2 = my_bunny_malloc(sizeof(t_vec));
  obj->pos->x = atoi(object->posx);
  obj->pos->y = atoi(object->posy);
  obj->pos->z = atoi(object->posz);
  obj->vec1->x = atof(object->vec1x);
  obj->vec1->y = atof(object->vec1y);
  obj->vec1->z = atof(object->vec1z);
  obj->vec2->x = atof(object->vec2x);
  obj->vec2->y = atof(object->vec2y);
  obj->vec2->z = atof(object->vec2z);
  obj->ka = atof(object->ka);
  obj->kd = atof(object->kd);
  obj->ks = atof(object->ks);
  obj->ia = atof(object->ia);
  obj->id = atof(object->id);
  obj->is = atof(object->is);
  obj->alpha = atoi(object->alpha);
}

static int	load_obj(t_start *infos, int fd)
{
  t_object	object;
  t_obj		*obj;

  if (read(fd, &object, 512) == -1)
    return (ON_ERROR);
  obj = my_bunny_malloc(sizeof(t_obj));
  my_strncpy(obj->type, object.type, 10);
  init_vec_pos(&object, obj);
  obj->ray = atoi(object.ray);
  obj->color = my_getnbr_base(object.color, "0123456789ABCDEF");
  if (!my_strcmp("light", obj->type))
    add_end(&infos->light, obj);
  else if (!my_strcmp("sphere", obj->type) ||
	   !my_strcmp("plan", obj->type) ||
	   !my_strcmp("cone", obj->type) ||
	   !my_strcmp("cylindre", obj->type))
    add_end(&infos->object, obj);
  else
    {
      write(1, obj->type, my_strlen(obj->type));
      write(1, ": not known.\n", 13);
    }
  return (ON_SUCCESS);
}

int		load_scene(t_start *infos, const char *str)
{
  t_header	header;
  int		objs;
  int		i;
  int		fd;

  if ((fd = open(str, O_RDONLY)) == -1 ||
      read(fd, &header, 512) < 512 ||
      my_strcmp(header.magic, MAGIC))
    {
      write(1, str, my_strlen(str));
      write(1, ": file not supported.\n", 22);
      if (fd != -1)
	close(fd);
      return (ON_ERROR);
    }
  objs = atoi(header.objects);
  i = -1;
  while (++i < objs && !load_obj(infos, fd));
  close(fd);
  return (ON_SUCCESS);
}
