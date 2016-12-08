/*
** my.h for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Wed Mar 23 15:17:46 2016 Jean PLANCHER
** Last update Tue May 31 17:21:01 2016 David Zeng
*/

#ifndef MY_H_
# define MY_H_

# include <pthread.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "ray.h"
# include "bmp.h"

# define INT_SIZE 4

/*
** Libmy
*/

int		is_num(const char *str, char c);
void    	my_putnbr_base(const char *str, int nb, int n);
void		my_putunbr_base(const char *str, unsigned int nb, int n);
int		my_getnbr_base(const char *str, const char *base);
unsigned int	my_getunbr_base(const char *str, const char *base);
char		**my_str_to_tab(const char *str, char sep1, char sep2);
int		my_strcmp(const char *str1, const char *str2);
int		my_strncmp(const char *str1, const char *str2, size_t n);
void		my_strcopy(char **new_string, const char *old_string);
char		*my_strncpy(char *dest, const char *src, size_t n);
char		*my_strcpy(char *dest, const char *src);
size_t		my_strlen(const char *s);
void            *my_memset(void *s, int c, size_t n);
void		*my_memcpy(void *dest, const void *src, size_t n);
void		my_exit(int nb);
off_t		my_lseek(int fd, off_t offset, int whence);
int		my_execve(const char *filename, char *const argv[],
			  char *const envp[]);
int		my_access(const char *pathname, int mode);
void		*my_malloc(size_t nb);

#endif /* !MY_H_ */
