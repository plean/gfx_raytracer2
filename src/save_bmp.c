/*
** save_bmp.c for save bmp in /home/zeng_d/test/tekpaint
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jan 26 19:09:04 2016 David Zeng
** Last update Wed Jun  1 04:06:44 2016 David Zeng
*/

#include <stdio.h>
#include "bmp.h"

static void		my_write_pixel(int fd, t_bunny_pixelarray *pix)
{
  t_color		color;
  t_bunny_position	pos;
  unsigned int		*pixels;

  pos.y = pix->clipable.clip_height;
  pixels = (unsigned int *)pix->pixels;
  while (pos.y >= 0)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width)
	{
	  color.full = pixels[pos.y * pix->clipable.clip_width + pos.x];
	  write(fd, &color.argb[2], 1);
	  write(fd, &color.argb[1], 1);
	  write(fd, &color.argb[0], 1);
	  pos.x += 1;
	}
      pos.y -= 1;
    }
}

static void	my_write_all(int fd, t_write *file)
{
  int		size;

  size = 0;
  size += write(fd, &file->signe, 2);
  size += write(fd, &file->size, 4);
  size += write(fd, &file->reserve, 4);
  size += write(fd, &file->shift, 4);
  size += write(fd, &file->size_head, 4);
  size += write(fd, &file->width, 4);
  size += write(fd, &file->height, 4);
  size += write(fd, &file->plan, 2);
  size += write(fd, &file->nb_bit_pixel, 2);
  size += write(fd, &file->compress, 4);
  size += write(fd, &file->size_picture, 4);
  size += write(fd, &file->color_pal, 4);
  size += write(fd, &file->nb_color_im, 4);
}

static int	my_write_head(t_write *file,
			      t_bunny_pixelarray *pix, char *filename)
{
  int		fd;

  if ((fd = open(filename, O_CREAT | O_WRONLY, MODE)) < 3)
    {
      write(2, "error open file", 15);
      return (-1);
    }
  my_write_all(fd, file);
  my_write_pixel(fd, pix);
  return (0);
}

void		save_bmp(t_bunny_pixelarray *pix, char *filename)
{
  t_write	file;

  file.signe[0] = 'B';
  file.signe[1] = 'M';
  file.size = 0;
  file.reserve = 0;
  file.shift = 46;
  file.width = pix->clipable.clip_width;
  file.height = pix->clipable.clip_height;
  file.plan[0] = 1;
  file.plan[1] = 0;
  file.nb_bit_pixel[0] = 24;
  file.nb_bit_pixel[1] = 0;
  file.compress = 0;
  file.size_picture = file.width * file.height;
  file.color_pal = 3780;
  file.nb_color_im = 3780;
  file.size_head = 46;
  my_write_head(&file, pix, filename);
}
