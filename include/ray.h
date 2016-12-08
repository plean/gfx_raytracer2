/*
** ray.h for  in /home/planch_j/rendu/Info/gfx_raytracer2/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 15 00:12:06 2016 Jean PLANCHER
** Last update Thu Jun  2 10:46:45 2016 Jean PLANCHER
*/

#ifndef RAY_H_
# define RAY_H_

# include <lapin.h>
# include "list.h"

/*
** Value
*/

# define ON_SUCCESS (0)
# define ON_ERROR (1)
# define NO_SOLUTIONS (-1)

/*
** Screen
*/

# define HEIGHT (1000)
# define WIDTH (1400)

/*
** Thread
*/

# define NB_THREAD (4)

/*
** Calc
*/

# define IS_BETWEEN(n, x, y) (((n < x && n > y) || (n > x && n < y)))
# define BETWEEN(n, min, max) (n < min ? min : (n > max ? max : n))
# define CAR(x) (x * x)
# define MAX(x, y) ((x) > (y) ? (x) : (y))
# define MIN(x, y) ((x) < (y) ? (x) : (y))

/*
** Eye
*/

# define DIST_EYE (-3000)
# define EYE_POS { WIDTH / 2, HEIGHT / 2, DIST_EYE }

/*
** Cylindre
*/

# define DIV_E (CAR(obj->vec1->x) + CAR(obj->vec1->y) + CAR(obj->vec1->z))

# define MUL_EX CAR(obj->vec1->x)
# define MUL_EY CAR(obj->vec1->y)
# define MUL_EZ CAR(obj->vec1->z)

# define CYL1X (MUL_EX * CAR(eye->vec.x))
# define CYL1Y (MUL_EY * CAR(eye->vec.y))
# define CYL1Z (MUL_EZ * CAR(eye->vec.z))
# define C1 ((CYL1X + CYL1Y + CYL1Z) / DIV_E)

# define CYL2X (MUL_EX * 2 * ((eye->pos.x - obj->pos->x) * eye->vec.x))
# define CYL2Y (MUL_EY * 2 * ((eye->pos.y - obj->pos->y) * eye->vec.y))
# define CYL2Z (MUL_EZ * 2 * ((eye->pos.z - obj->pos->z) * eye->vec.z))
# define C2 ((CYL2X + CYL2Y + CYL2Z) / DIV_E)

# define CYL3X (MUL_EX * (-2 * (eye->pos.x * obj->pos->x)\
			  + CAR(eye->pos.x) + CAR(obj->pos->x)))
# define CYL3Y (MUL_EY * (-2 * (eye->pos.y * obj->pos->y)\
			  + CAR(eye->pos.y) + CAR(obj->pos->y)))
# define CYL3Z (MUL_EZ * (-2 * (eye->pos.z * obj->pos->z)\
			  + CAR(eye->pos.z) + CAR(obj->pos->z)))
# define C3 ((CYL3X + CYL3Y + CYL3Z) / DIV_E)

/*
** Magic
*/

# define tokenpaster(n) printf ("token" #n " = %d\n", token##n)
# define MAGIC ("keeek")

/* Cylindre's Macros */
/* obj->vec */
# define VA obj->vec1->x
# define VB obj->vec1->y
# define VC obj->vec1->z

/* eye->pos */
# define XA eye->pos.x
# define YA eye->pos.y
# define ZA eye->pos.z

/* eye->vec */
# define UX eye->vec.x
# define UY eye->vec.y
# define UZ eye->vec.z

/* obj->pos */
# define X0 obj->pos->x
# define Y0 obj->pos->y
# define Z0 obj->pos->z

typedef struct	s_object
{
  char		type[10];
  char		posx[6];
  char		posy[6];
  char		posz[6];
  char		vec1x[6];
  char		vec1y[6];
  char		vec1z[6];
  char		vec2x[6];
  char		vec2y[6];
  char		vec2z[6];
  char		ray[6];
  char		color[9];
  char		ka[5];
  char		kd[5];
  char		ks[5];
  char		ia[5];
  char		id[5];
  char		is[5];
  char		alpha[5];
  char		prefix[398];
}		t_object;

typedef struct	s_header
{
  char		name[100];
  char		objects[8];
  char		magic[6];
  char		prefix[398];
}		t_header;

typedef struct	s_vec
{
  double	x;
  double	y;
  double	z;
}		t_vec;

typedef struct	s_3dpos
{
  int		x;
  int		y;
  int		z;
}		t_3dpos;

typedef struct	s_eye
{
  t_3dpos	pos;
  t_vec		vec;
}		t_eye;

/*
** ka￼, which is a specular reflection constant, the ratio of reflection of the specular term of incoming light,
￼** kd, which is a diffuse reflection constant, the ratio of reflection of the diffuse term of incoming light (Lambertian reflectance),
￼** ks, which is an ambient reflection constant, the ratio of reflection of the ambient term present in all points in the scene rendered,
￼** alpha, which is a shininess constant for this material, which is larger for surfaces that are smoother and more mirror-like. When this constant is large the specular highlight is small,
** id￼ and is,￼ are defined as the intensities (often as RGB values) of the specular and diffuse components of the light sources, and
** ia, controls the ambient lighting.
*/

typedef struct	s_obj
{
  char		type[10];
  t_3dpos	*pos;
  t_vec		*vec1;
  t_vec		*vec2;
  double	ka;
  double	kd;
  double	ks;
  double	ia;
  double	id;
  double	is;
  int		alpha;
  int		ray;
  unsigned int	color;
}		t_obj;

typedef struct	s_ipo
{
  double	n;
  unsigned int	c;
  t_obj		*obj;
  int		pos;
}		t_ipo;

typedef struct		s_start
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*font;
  t_list		*object;
  t_list		*light;
}			t_start;

/*
** Init
*/

int		load_scene(t_start *a, const char *str);

/*
** Light
*/

void		light(t_eye *eye, t_list *light, t_ipo *m);

/*
** Calc
*/

double		my_sphere(t_eye *eye, t_obj *obj);
double		my_plan(t_eye *eye, t_obj *obj);
double		my_cylindre(t_eye *eye, t_obj *obj);
double		my_cone(t_eye *eye, t_obj *obj);
double		cone(t_eye *eye, t_obj *obj, double *sol1, double *sol2);
void		aff_obj(t_start *a);
int		is_in_light(t_eye *eye, t_list *ligths,
			    t_list *object, t_obj *exept);

/*
** Tekfuctions
*/

void		screen_full(t_bunny_pixelarray *pix, unsigned int color);
unsigned int	my_get_color(const t_bunny_pixelarray *pix,
			     int x,
			     int y);
void		pixel_tr(t_bunny_pixelarray *pix,
			 const t_bunny_position *pos,
			 unsigned int color);
void		pixel(t_bunny_pixelarray *pix,
		      const t_bunny_position *pos,
		      unsigned int color);

/*
** Errors
*/

int     	file_errors(const char **av);
int		aff_error(const char *str);

/*
** Vec
*/

void		calc_vec(const t_3dpos *pos1, const t_3dpos *pos2, t_vec *vec);
void		print_vec(const t_vec *vec);
void		normalized_vec(t_vec *vec);
double		prod_scal(const t_vec *vec1, const t_vec *vec2);
double		norm_vec(const t_vec *vec);

/*
** Scene
*/

void		do_header(t_header *header);
void		do_object(t_object *object);

/*
** Misc
*/

void		*my_bunny_malloc(size_t nb);
void		aff_list(t_element *elem);
void		stretch(t_bunny_pixelarray *pix,
			t_bunny_pixelarray *ori);

#endif /* !RAY_H_ */
