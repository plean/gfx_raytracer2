/*
** obj.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon May  9 10:27:59 2016 Jean PLANCHER
** Last update Thu Jun  2 10:47:34 2016 Jean PLANCHER
*/

#include <stdio.h>
#include "my.h"

static t_ipo		find_obj(t_obj *obj, t_eye *eye, unsigned int c)
{
  static t_ipo	m;
  double	tmp;

  if (obj == NULL || eye == NULL)
    {
      m.n = -1;
      m.c = c;
      m.obj = NULL;
      return (m);
    }
  if (!strcmp(obj->type, "sphere"))
    tmp = my_sphere(eye, obj);
  else if (!strcmp(obj->type, "plan"))
    tmp = my_plan(eye, obj);
  else if (!strcmp(obj->type, "cylindre"))
    tmp = my_cylindre(eye, obj);
  else if (!strcmp(obj->type, "cone"))
    tmp = my_cone(eye, obj);
  if (tmp != -1 && (m.n > tmp || m.n == -1))
    {
      m.n = tmp;
      m.c = obj->color;
      m.obj = obj;
    }
  return (m);
}

static void	do_light(t_list *lights, t_ipo *m, t_eye *eye, t_list *object)
{
  t_eye		pix;

  if (!m->obj)
    return ;
  pix.pos.x = m->n * eye->vec.x + eye->pos.x;
  pix.pos.y = m->n * eye->vec.y + eye->pos.y;
  pix.pos.z = m->n * eye->vec.z + eye->pos.z;
  if (!is_in_light(&pix, lights, object, m->obj))
    light(&pix, lights, m);
  else
    m->c = BLACK;
}

void			aff_obj(t_start *a)
{
  t_element		*elem;
  t_3dpos		poz;
  t_eye			eye;
  t_bunny_position	pos;
  t_ipo			m;
  int			i;

  poz.z = 0;
  eye.pos = (t_3dpos)EYE_POS;
  i = -1;
  while (++i < WIDTH * HEIGHT)
    {
      pos.x = poz.x = i % WIDTH;
      pos.y = poz.y = i / WIDTH;
      calc_vec(&eye.pos, &poz, &eye.vec);
      find_obj(NULL, NULL, my_get_color(a->pix, pos.x, pos.y));
      elem = a->object->first;
      while (elem)
	{
	  m = find_obj((t_obj *)elem->data, &eye, 0);
	  elem = elem->next;
	}
      (m.n != -1) ? do_light(a->light, &m, &eye, a->object) : (void)0;
      pixel(a->pix, &pos, m.c);
    }
}
