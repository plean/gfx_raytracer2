/*
** equation_forms.c for  in /home/planch_j/rendu/Info/gfx_raytracer1/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Mar  4 20:26:15 2016 Jean PLANCHER
** Last update Mon May 23 16:00:17 2016 Jean PLANCHER
*/

#include "my.h"

double		my_sphere(t_eye *eye, t_obj *obj)
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	sol1;
  double	sol2;

  a = CAR(eye->vec.x) + CAR(eye->vec.y) + CAR(eye->vec.z);
  b = 2 * ((eye->pos.x - obj->pos->x) * eye->vec.x +
	   (eye->pos.y - obj->pos->y) * eye->vec.y +
	   (eye->pos.z - obj->pos->z) * eye->vec.z);
  c = -2 * (eye->pos.x * obj->pos->x + eye->pos.y * obj->pos->y
	    + eye->pos.z * obj->pos->z) + CAR(eye->pos.x) + CAR(eye->pos.y)
    + CAR(eye->pos.z) + CAR(obj->pos->x) + CAR(obj->pos->y)
    + CAR(obj->pos->z) - CAR(obj->ray);
  d = CAR(b) - (4 * a * c);
  sol1 = (-b + sqrt(d)) * 0.5 / a;
  sol2 = (-b - sqrt(d)) * 0.5 / a;
  if (d < 0 || (sol1 * obj->pos->z < 0 && sol2 * obj->pos->z < 0))
    return (-1);
  return (sol1 * obj->pos->z < 0 ? sol2 : sol2 * obj->pos->z < 0 ?
	  sol1 : MIN(sol1, sol2));
}

double		my_plan(t_eye *eye, t_obj *obj)
{
  t_vec		norm;
  double	d;
  double	t;

  norm.x = obj->vec1->y * obj->vec2->z - obj->vec1->z * obj->vec2->y;
  norm.y = obj->vec1->z * obj->vec2->x - obj->vec1->x * obj->vec2->z;
  norm.z = obj->vec1->x * obj->vec2->y - obj->vec1->y * obj->vec2->x;
  d = -(norm.x * obj->pos->x + norm.y * obj->pos->y + norm.z * obj->pos->z);
  t = -(norm.x * eye->pos.x + norm.y * eye->pos.y + norm.z * eye->pos.z + d) /
      (norm.x * eye->vec.x + norm.y * eye->vec.y + norm.z * eye->vec.z);
   return ((t < 0) ? NO_SOLUTIONS : t);
}

double		my_cylindre(t_eye *eye, t_obj *obj)
{
  double	a[3];
  double	d;
  double	n[2];

  a[0] = CAR(eye->vec.x) + CAR(eye->vec.y) + CAR(eye->vec.z) - C1;
  a[1] = 2 * ((eye->pos.x - obj->pos->x) * eye->vec.x +
	   (eye->pos.y - obj->pos->y) * eye->vec.y +
	   (eye->pos.z - obj->pos->z) * eye->vec.z) - C2;
  a[2] = -2 * (eye->pos.x * obj->pos->x + eye->pos.y * obj->pos->y
	    + eye->pos.z * obj->pos->z) + CAR(eye->pos.x) + CAR(eye->pos.y)
    + CAR(eye->pos.z) + CAR(obj->pos->x) + CAR(obj->pos->y)
    + CAR(obj->pos->z) - CAR(obj->ray) - C3;
  d = a[1] * a[1] - (4 * a[0] * a[2]);
  n[0] = (-a[1] + sqrt(d)) * 0.5 / a[0];
  n[1] = (-a[1] - sqrt(d)) * 0.5 / a[0];
  if (d < 0 || (n[0] * obj->pos->z < 0 && n[1] * obj->pos->z < 0))
    return (-1);
  return (n[0] * obj->pos->z < 0 ? n[1] : n[1] * obj->pos->z < 0 ?
	  n[0] : MIN(n[0], n[1]));
}

double		my_cone(t_eye *eye, t_obj *obj)
{
  double	sol1;
  double	sol2;
  double	d;

  d = cone(eye, obj, &sol1, &sol2);
  if (d < 0 || (sol1 * obj->pos->z < 0 && sol2 * obj->pos->z < 0))
    return (-1);
  return (sol1 * obj->pos->z < 0 ? sol2 : sol2 * obj->pos->z < 0 ?
	  sol1 : MIN(sol1, sol2));
}
