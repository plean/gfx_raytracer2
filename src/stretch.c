/*
** stretch.c for  in /home/planch_j/rendu/Info/gfx_raytracer2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue May 31 17:33:55 2016 Jean PLANCHER
** Last update Tue May 31 17:35:20 2016 Jean PLANCHER
*/

#include "my.h"

static int	fox_calc_pos(int x, int y, t_bunny_pixelarray *pix)
{
  return (y * pix->clipable.clip_width + x);
}

void	stretch(t_bunny_pixelarray *pix,
		t_bunny_pixelarray *ori)
{
  int	x_ratio;
  int	y_ratio;
  int	i;
  int	j;
  int	xy[2];

  x_ratio = (int)((ori->clipable.clip_width << 16)
	     / pix->clipable.clip_width) + 1;
  y_ratio = (int)((ori->clipable.clip_height << 16)
	     / pix->clipable.clip_height) + 1;
  i = 0;
  while (i < pix->clipable.clip_height)
    {
      j = 0;
      while (j < pix->clipable.clip_width)
	{
	  xy[0] = ((j * x_ratio) >> 16);
	  xy[1] = ((i * y_ratio) >> 16);
	  ((t_color *)pix->pixels)[fox_calc_pos(j, i, pix)] =
	  ((t_color *)ori->pixels)[fox_calc_pos(xy[0], xy[1], ori)];
	  j = j + 1;
	}
      i = i + 1;
    }
}
