/*
** shadows.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Thu Jun  2 09:10:52 2016 Jean PLANCHER
** Last update Thu Jun  2 10:47:20 2016 Jean PLANCHER
*/

#include "my.h"

static int	compare_pos(double m, t_eye *eye, t_3dpos *light)
{
  t_3dpos	pos;

  pos.x = m * eye->vec.x + eye->pos.x;
  pos.y = m * eye->vec.y + eye->pos.y;
  pos.z = m * eye->vec.z + eye->pos.z;
  return (IS_BETWEEN(pos.x, eye->pos.x, light->x) &&
	  IS_BETWEEN(pos.y, eye->pos.y, light->y) &&
	  IS_BETWEEN(pos.z, eye->pos.z, light->z));
}

static double	test_obj(t_obj *obj, t_eye *eye)
{
  double	tmp;

  if (!strcmp(obj->type, "sphere"))
    tmp = my_sphere(eye, obj);
  else if (!strcmp(obj->type, "plan"))
    tmp = my_plan(eye, obj);
  else if (!strcmp(obj->type, "cylindre"))
    tmp = my_cylindre(eye, obj);
  else if (!strcmp(obj->type, "cone"))
    tmp = my_cone(eye, obj);
  return (tmp);
}

int		is_in_light(t_eye *eye, t_list *lights,
			    t_list *objects, t_obj *exept)
{
  t_element	*object;
  t_element	*light;
  double		m;

  light = lights->first;
  while (light)
    {
      calc_vec(&eye->pos, ((t_obj *)light->data)->pos, &eye->vec);
      eye->pos.x += ((eye->vec.x > 0) * 2 - 1) * 2;
      eye->pos.y += ((eye->vec.y > 0) * 2 - 1) * 2;
      eye->pos.z += ((eye->vec.z > 0) * 2 - 1) * 2;
      object = objects->first;
      m = -1;
      while (object)
	{
	  if (exept != (t_obj *)object->data)
	    m = test_obj((t_obj *)object->data, eye);
	  if (m != -1 && compare_pos(m, eye, ((t_obj *)light->data)->pos))
	    return (1);
	  object = object->next;
	}
      light = light->next;
    }
  return (0);
}
