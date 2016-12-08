/*
** light.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 15 15:42:37 2016 Jean PLANCHER
** Last update Thu Jun  2 09:19:54 2016 Jean PLANCHER
*/

#include "my.h"

static void	calc_normal(t_3dpos *pos, t_obj *obj, t_vec *n)
{
  double	angle;

  if (!strcmp(obj->type, "sphere"))
    calc_vec(obj->pos, pos, n);
  else if (!strcmp(obj->type, "plan"))
    {
      n->x = obj->vec1->y * obj->vec2->z - obj->vec1->z * obj->vec2->y;
      n->y = obj->vec1->z * obj->vec2->x - obj->vec1->x * obj->vec2->z;
      n->z = obj->vec1->x * obj->vec2->y - obj->vec1->y * obj->vec2->x;
    }
  else if (!strcmp(obj->type, "cylindre"))
    {
      n->x = pos->x - (obj->vec1->x) ? obj->pos->x * (pos->x - obj->pos->x): 0;
      n->y = pos->y - (obj->vec1->y) ? obj->pos->y * (pos->y - obj->pos->y): 0;
      n->z = pos->z - (obj->vec1->z) ? obj->pos->z * (pos->z - obj->pos->z): 0;
    }
  else if (!strcmp(obj->type, "cone"))
    {
      angle = CAR(tan(obj->ray * M_PI / 180));
      (void)angle;
      n->x = pos->x - (obj->vec1->x) ? obj->pos->x * (pos->x - obj->pos->x): 0;
      n->y = pos->y - (obj->vec1->y) ? obj->pos->y * (pos->y - obj->pos->y): 0;
      n->z = pos->z - (obj->vec1->z) ? obj->pos->z * (pos->z - obj->pos->z): 0;
      normalized_vec(n);
    }
}

/*
** l, which is the direction vector from the point on the surface toward each light source (￼specifies the light source),
** n, which is the normal at this point on the surface,
** r￼, which is the direction that a perfectly reflected ray of light would take from this point on the surface,
**￼ v, which is the direction pointing towards the viewer (such as a virtual camera),
** cos_theta, vector product, and
** id and is, light intensities.
*/

static double	diffuse(t_eye *pix, t_obj *obj, t_ipo *m, t_vec *n)
{
  double		tmp;
  t_vec			l;

  calc_vec(&pix->pos, obj->pos, &l);
  normalized_vec(&l);
  tmp = m->obj->kd * obj->id * prod_scal(n, &l);
  return (BETWEEN(tmp, 0, 1));
}

static double	specular(t_eye *pix, t_obj *obj, t_ipo *m, t_vec *n)
{
  double		tmp;
  double		cos_theta;
  t_vec			v;
  t_vec			r;
  t_vec			l;

  calc_vec(&pix->pos, &(t_3dpos)EYE_POS, &v);
  normalized_vec(&v);
  calc_vec(&pix->pos, obj->pos, &l);
  normalized_vec(&l);
  cos_theta = -2 * prod_scal(&l, n);
  r.x = cos_theta * n->x + l.x;
  r.y = cos_theta * n->y + l.y;
  r.z = cos_theta * n->z + l.z;
  normalized_vec(&r);
  tmp = m->obj->ks * obj->is * pow(prod_scal(&v, &r), m->obj->alpha);
  return (BETWEEN(tmp, 0, 1));
}

static unsigned int	calc_light(t_eye *pix, t_list *lights,
				   t_ipo *m, unsigned char c, int n)
{
  t_element	*elem;
  t_obj		*light;
  double	diff;
  double	spec;
  double	tmp;
  t_color	color;
  t_vec		norm;

  elem = lights->first;
  diff = spec = tmp = 0;
  calc_normal(&pix->pos, m->obj, &norm);
  normalized_vec(&norm);
  while (elem)
    {
      light = (t_obj *)elem->data;
      color.full = light->color;
      diff += diffuse(pix, light, m, &norm) * color.argb[n] / 255;
      spec += specular(pix, light, m, &norm) * color.argb[n];
      tmp = m->obj->ka * light->ia;
      elem = elem->next;
    }
  return (BETWEEN(tmp + diff * c + spec, 0, 255));
}

void		light(t_eye *pix, t_list *light, t_ipo *m)
{
  t_color	color;
  int		n;

  n = -1;
  color.full = m->c;
  while (++n < 3)
    color.argb[n] = calc_light(pix, light, m, color.argb[n], n);
  m->c = color.full;
}
