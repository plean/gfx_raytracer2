/*
** list.c for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 27 06:14:14 2016 Jean PLANCHER
** Last update Tue May 31 16:15:40 2016 Jean PLANCHER
*/

#include "my.h"

t_list		*create_list(void)
{
  t_list	*list;
  list = my_bunny_malloc(sizeof(t_list));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return (list);
}

void		add_start(t_list **list, void *data)
{
  t_element	*tmp;

  tmp = my_bunny_malloc(sizeof(t_element));
  tmp->data = data;
  tmp->next = (*list)->first;
  if (tmp->next)
    tmp->next->prev = tmp;
  tmp->prev = NULL;
  (*list)->first = tmp;
  if ((*list)->last == NULL)
    (*list)->last = tmp;
  (*list)->length++;
}

void		add_end(t_list **list, void *data)
{
  t_element	*tmp;

  tmp = my_bunny_malloc(sizeof(t_element));
  tmp->data = data;
  tmp->prev = (*list)->last;
  if ((*list)->last)
    (*list)->last->next = tmp;
  (*list)->last = tmp;
  tmp->next = NULL;
  if ((*list)->first == NULL)
    (*list)->first = tmp;
  (*list)->length++;
}

void		del_list(t_list **list)
{
  t_element	*tmp;
  t_obj		*obj;

  while ((*list)->first != NULL)
    {
      tmp = (*list)->first->next;
      obj = (t_obj *)(*list)->first->data;
      bunny_free(obj->vec1);
      bunny_free(obj->vec2);
      bunny_free(obj->pos);
      bunny_free(obj);
      bunny_free((t_obj *)(*list)->first);
      (*list)->first = tmp;
      (*list)->length--;
    }
  bunny_free((*list));
}

void	aff_list(t_element *elem)
{
  t_obj	*obj;

  while (elem)
    {
      obj = (t_obj *)(elem->data);
      printf("type : %s\n", obj->type);
      printf("pos :\tx: %d\ty: %d\tz: %d\n",
	     obj->pos->x, obj->pos->y, obj->pos->z);
      printf("vec1 :\tx: %.4f\ty: %.4f\tz: %.4f\n",
	     obj->vec1->x, obj->vec1->y, obj->vec1->z);
      printf("vec2 :\tx: %.4f\ty: %.4f\tz: %.4f\n",
	     obj->vec2->x, obj->vec2->y, obj->vec2->z);
      printf("ray : %d\n", obj->ray);
      printf("color : %X\n", obj->color);
      (!strcmp(obj->type, "light")) ?
       printf("ia : %0.3f id : %0.3f is : %0.3f\n", obj->ia, obj->id, obj->is) :
       printf("ka : %0.3f kd : %0.3f ks : %0.3f alpha : %d\n",
	      obj->ka, obj->kd, obj->ks, obj->alpha);
      elem = elem->next;
    }
}
