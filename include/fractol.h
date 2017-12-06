/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:12:09 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/04 17:12:10 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mcrlx.h"
# include "clct.h"
# include "libstr.h"
# include "libio.h"

# define DEBUG_GRID_ENABLED 0
# define WINDOW_WIDTH 1500
# define WINDOW_HEIGHT 1000

struct s_state;
struct s_args;

typedef struct s_state	*t_state;
typedef struct s_args	*t_args;
typedef t_state			(*t_init)(void);
typedef	t_color			(*t_palette)(t_color, t_color, int);

struct					s_state
{
	double				scale;
	int					changed;
	int					threads;
	t_render			mode;
	t_init				reset;
	t_point				offset;
	t_point_d			c;
	t_color				cstart;
	t_color				cend;
	t_palette			color;
};

struct					s_args
{
	int					julia;
	int					mandel;
	int					bship;
	int					error;
};

t_state					init_mandelbrot(void);
t_state					init_bship(void);
t_state					init_julia(void);
void					render_bship(t_buffer buffer, void *data);
void					render_mandelbrot(t_buffer buffer, void *data);
t_state					parse_args(int ac, char **av);
void					plus_handler(int kc, t_evloop loop);
void					minus_handler(int kc, t_evloop loop);
void					render_handler(t_evloop loop);
void					pan_handler(t_point cur, t_point prev, t_evloop loop);
void					focal_handler(t_point cur, t_point prev, t_evloop loop);
void					esc_handler(int c, t_evloop loop);
void					create_app(t_state state, char *title);
void					arrow_handler(int kc, t_evloop loop);
void					print_help(char *name);
void					e_handler(t_evloop loop);
int						colr(t_state state, int step);
void					reset_handler(int kc, t_evloop loop);
t_color					grad_gen(t_color s, t_color e, int z);
t_color					sine_gen(t_color s, t_color e, int z);

#endif
