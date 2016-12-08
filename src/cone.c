/*
** cone.c for cone in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun May 22 18:49:41 2016 David Zeng
** Last update Mon May 23 03:13:23 2016 David Zeng
*/

#include "my.h"

inline static double	cone_x(t_eye *eye, t_obj *obj, double *sol1, double *sol2)
{
  double	a;
  double	b;
  double	c;
  double	angle;
  double	d;

  angle = CAR(tan(obj->ray * M_PI / 180));
  a = CAR(UZ) + CAR(UY) - angle * CAR(UX);
  b = 2 * (ZA * UZ - UZ * Z0 + YA * UY - UY * Y0 - angle * (XA * UX - UX * X0));
  c = CAR(ZA) + CAR(YA) - angle * CAR(XA) + CAR(Z0) + CAR(Y0) - angle * CAR(X0) -
    2 * ZA * Z0 - 2 * YA * Y0 + angle * 2 * XA * X0;
  d = CAR(b) - (4 * a * c);
  *sol1 = (-b + sqrt(d)) * 0.5 / a;
  *sol2 = (-b - sqrt(d)) * 0.5 / a;
  return (d);
}

inline static double	cone_y(t_eye *eye, t_obj *obj, double *sol1, double *sol2)
{
  double	a;
  double	b;
  double	c;
  double	angle;
  double	d;

  angle = CAR(tan(obj->ray * M_PI / 180));
  a = CAR(UX) + CAR(UZ) - angle * CAR(UY);
  b = 2 * (XA * UX - UX * X0 + ZA * UZ - UZ * Z0 - angle * (YA * UY - UY * Y0));
  c = CAR(XA) + CAR(ZA) - angle * CAR(YA) + CAR(X0) + CAR(Z0) - angle * CAR(Y0) -
    2 * XA * X0 - 2 * ZA * Z0 + angle * 2 * YA * Y0;
  d = CAR(b) - (4 * a * c);
  *sol1 = (-b + sqrt(d)) * 0.5 / a;
  *sol2 = (-b - sqrt(d)) * 0.5 / a;
  return (d);
}

inline static double	cone_z(t_eye *eye, t_obj *obj, double *sol1, double *sol2)
{
  double	a;
  double	b;
  double	c;
  double	angle;
  double	d;

  angle = CAR(tan(obj->ray * M_PI / 180));
  a = CAR(UX) + CAR(UY) - angle * CAR(UZ);
  b = 2 * (XA * UX - UX * X0 + YA * UY - UY * Y0 - angle * (ZA * UZ - UZ * Z0));
  c = CAR(XA) + CAR(YA) - angle * CAR(ZA) + CAR(X0) + CAR(Y0) - angle * CAR(Z0) -
    2 * XA * X0 - 2 * YA * Y0 + angle * 2 * ZA * Z0;
  d = CAR(b) - (4 * a * c);
  *sol1 = (-b + sqrt(d)) * 0.5 / a;
  *sol2 = (-b - sqrt(d)) * 0.5 / a;
  return (d);
}

double		cone(t_eye *eye, t_obj *obj, double *sol1, double *sol2)
{
  double	d;

  if (obj->vec1->x == 1)
    d = cone_x(eye, obj, sol1, sol2);
  else if (obj->vec1->y == 1)
    d = cone_y(eye, obj, sol1, sol2);
  else
    d = cone_z(eye, obj, sol1, sol2);
  return (d);
}
