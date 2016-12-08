/*
** main.c for  in /home/planch_j/rendu/Info/gfx_raytracer1/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon Feb 22 18:23:07 2016 Jean PLANCHER
** Last update Wed Jun  1 14:45:34 2016 Jean PLANCHER
*/

#include <stdio.h>
#include "my.h"

static t_bunny_response	test_exit(t_bunny_event_state state,
				t_bunny_keysym key,
				void *data)
{
  t_start		*b;

  b = (t_start*)data;
  (void)b;
  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

static t_bunny_response	refresh(void *a)
{
  t_start		*b;
  t_bunny_position	pos;

  b = (t_start*)a;
  pos.x = 0;
  pos.y = 0;
  bunny_blit(&(b->win->buffer), &(b->pix->clipable), &pos);
  bunny_display(b->win);
  return (GO_ON);
}

int		main(int ac, char *const *av)
{
  t_start	a;
  int		i;

  if (ac < 2)
    return (aff_error(av[0]));
  a.light = create_list();
  a.object = create_list();
  i = 0;
  while (++i < ac)
    if (load_scene(&a, av[i]))
      return (ON_ERROR);
  a.win = bunny_start_style(WIDTH, HEIGHT, 5, "Raytracer");
  a.pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  a.font = bunny_load_pixelarray(((ac == 2 && strcmp(av[1], "damier"))
				  ? "font/font3.png" : "font/font2.jpeg"));
  (a.font && a.object->first) ? stretch(a.pix, a.font) : screen_full(a.pix, BLACK);
  if (a.object->first)
    aff_obj(&a);
  save_bmp(a.pix, "sample.bmp");
  bunny_set_loop_main_function(&refresh);
  bunny_set_key_response(&test_exit);
  bunny_loop(a.win, 5, (void*)&a);
  bunny_stop(a.win);
  bunny_delete_clipable(&(a.pix->clipable));
  aff_list(a.light->first);
  aff_list(a.object->first);
  return (0);
}
