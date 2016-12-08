/*
** list.h for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 27 04:31:11 2016 Jean PLANCHER
** Last update Thu May 12 15:35:32 2016 Jean PLANCHER
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct		s_element
{
  void			*data;
  struct s_element	*next;
  struct s_element	*prev;
}			t_element;

typedef struct	s_list
{
  int		length;
  t_element	*first;
  t_element	*last;
}		t_list;

/*
** List
*/

t_list		*create_list(void);
void		add_end(t_list **list, void *data);
void		add_start(t_list **list, void *data);
void		del_list(t_list **list);
t_list		*my_list(void *tmp);

#endif /* !LIST_H_ */
