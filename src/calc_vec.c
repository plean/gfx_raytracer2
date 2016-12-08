/*
** calc_vec.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 15 18:28:22 2016 Jean PLANCHER
** Last update Mon May 23 04:14:06 2016 David Zeng
*/

#include "my.h"

inline void	calc_vec(const t_3dpos *pos1, const t_3dpos *pos2, t_vec *vec)
{
  vec->x = pos2->x - pos1->x;
  vec->y = pos2->y - pos1->y;
  vec->z = pos2->z - pos1->z;
}

inline double	prod_scal(const t_vec *vec1, const t_vec *vec2)
{
  return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

inline void	print_vec(const t_vec *vec)
{
  printf("vec: [%.3f, %.3f, %.3f]\n", vec->x, vec->y, vec->z);
}

inline double	norm_vec(register const t_vec *vec)
{
  return (sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2)));
}

inline void		normalized_vec(register t_vec *vec)
{
  register double	norm;

  norm = norm_vec(vec);
  vec->x /= norm;
  vec->y /= norm;
  vec->z /= norm;
}
