#ifndef FRACTOL_H
# define FRACTOL_H

# include "mcrlx.h"
# include "clct.h"
# include "libstr.h"
# include "fmath.h"

struct s_state;
struct s_args;
struct s_fseed;

typedef struct s_state	*t_state;
typedef struct s_args	*t_args;
typedef struct s_fseed	t_fseed;

struct					s_state
{
	double				scale;
	t_point				offset;
	int					changed;
	t_render			mode;
};

struct					s_args
{
	int					julia;
	int					mandel;
	int					error;
};

struct					s_fseed
{
	t_fract				fract;
	t_buffer			buf;
	t_state				state;
	void				(*init_fract)(t_point, t_fract*);
	int					(*iter_point)(t_point, t_fract*);
};

t_state					init_state(void);
void					render_mandelbrot(t_buffer buffer, void *data);
t_args					parse_args(int ac, char ** av);
t_state					init_mandelbrot(void);
void					plus_handler(int kc, t_evloop loop);
void					minus_handler(int kc, t_evloop loop);
void					render_handler(t_evloop loop);
void					offset_handler(t_point cur, t_point prev, t_evloop loop);
void					esc_handler(int c, t_evloop loop);
void					create_app(t_state state);
void    				iter_grid(t_point start, t_point max, void (*f)(int, int, void*), void *data);
int						continuous_color(double z);


t_state	init_julia(void);
#endif