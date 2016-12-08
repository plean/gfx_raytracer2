/*
** pixel.c for  in /home/planch_j/rendu/Info/gfx_raytracer1/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Feb 23 13:59:21 2016 Jean PLANCHER
** Last update Fri Apr 15 00:26:13 2016 Jean PLANCHER
*/

#include <stdio.h>
#include <lapin.h>

void	screen_full(t_bunny_pixelarray *pix, unsigned int color)
{
  unsigned int	*pixel;
  int	i;

  i = -1;
  pixel = (unsigned int *)pix->pixels;
  while (++i < pix->clipable.clip_width * pix->clipable.clip_height)
    pixel[i] = color;
}

unsigned int		my_get_color(const t_bunny_pixelarray *pix,
				     int x,
				     int y)
{
  t_bunny_position	pos;
  unsigned int		*pixel;

  if (x < 0 || y < 0 || x >= pix->clipable.clip_width ||
      y >= pix->clipable.clip_height)
    return (0);
  pos.x = x;
  pos.y = y;
  pixel = (unsigned int*)pix->pixels;
  return (pixel[pix->clipable.clip_width * pos.y + pos.x]);
}

void		pixel_tr(t_bunny_pixelarray *pix,
			 const t_bunny_position *pos,
			 unsigned int color)
{
  unsigned int	*pixel;
  double	percent;
  t_color	t;
  t_color	c;

  t.full = color;
  percent = (double)t.argb[3] / 255.0;
  if (percent != 1)
    {
      c.full = my_get_color(pix, pos->x, pos->y);
      c.argb[2] = t.argb[2] * percent + c.argb[2] * (1 - percent);
      c.argb[1] = t.argb[1] * percent + c.argb[1] * (1 - percent);
      c.argb[0] = t.argb[0] * percent + c.argb[0] * (1 - percent);
    }
  else
    c.full = t.full;
  pixel = (unsigned int *)pix->pixels;
  if (pos->y >= 0 && pos->x >= 0 && pos->x < pix->clipable.clip_width
      && pos->y < pix->clipable.clip_height)
  pixel[pix->clipable.clip_width * pos->y + pos->x] = c.full;
}

void		pixel(t_bunny_pixelarray *pix,
		      const t_bunny_position *pos,
		      unsigned int color)
{
  unsigned int	*pixel;

  pixel = (unsigned int *)pix->pixels;
  if (pos->y >= 0 && pos->x >= 0 && pos->x < pix->clipable.clip_width
      && pos->y < pix->clipable.clip_height)
    pixel[pix->clipable.clip_width * pos->y + pos->x] = color;
}
