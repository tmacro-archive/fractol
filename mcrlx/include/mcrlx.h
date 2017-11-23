/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:49:19 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/13 14:49:21 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MCRLX_H
# define MCRLX_H

# include <mlx.h>
# include "macs.h"
# include "keys.h"
# include "string.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "libutil.h"

/*
** MAX_WINDOWS defines the maximum number of windows that the framework supports
** This can be changed at compile time to supported any number of windows
*/

# define MAX_WINDOWS 5

/*
** SEG_X is used to instruct the framework to subdivide a window into X buffers
** This is used by the multi-threaded frame renderer to reduce frame render time
*/

# define SEG_1 1
# define SEG_4 2
# define SEG_9 3
# define SEG_16 4
# define SEG_64 8
# define SEG_100 10
# define SEG_144 12
# define SEG_256 16
# define SEG_400 20

/*
** The following define constants to identify different events
*/

# define MAX_EVENTS 7
# define EV_INIT 0
# define EV_EXIT 1
# define EV_EXPOSE 2
# define EV_KEY 3
# define EV_MOUSE 4
# define EV_MOTION 5
# define EV_TICK 6

/*
** TICK_FREQ controls to rate of tick events inserted into the event queue
** Higher numbers result in a greater interval between ticks
** Set to 0 to  disable
*/

# define TICK_FREQ 1500
/*
** Declare all of our structs and types here to simplify struct declarations
*/

typedef int					t_point[2];
typedef double				t_point_d[2];
typedef int					t_key[MAX_KC];
typedef int					t_mouse[MAX_MOUSE + 2];

struct s_display;
struct s_window;
struct s_image;
struct s_buffer;
struct s_frame;
struct s_evloop;
struct s_rndrdata;
// struct s_handler;
struct s_event;

typedef struct s_display	*t_display;
typedef struct s_window		*t_window;
typedef struct s_image		*t_image;
typedef struct s_buffer		*t_buffer;
typedef struct s_frame		*t_frame;
typedef struct s_evloop		*t_evloop;
typedef struct s_rndrdata	*t_rndrdata;
typedef struct s_event		*t_event;

typedef void				(*t_handler)(t_event, t_evloop);
typedef void				(*t_render)(t_buffer, void*);
typedef void				(*t_genhandler)(t_evloop);
typedef void				(*t_keyhandler)(int, t_evloop);
typedef void				(*t_mousehandler)(int, int, int, t_evloop);
typedef void				(*t_motionhandler)(t_point, t_point, t_evloop);

typedef t_handler			*t_handlers;			
typedef t_keyhandler		t_keyhandlers[MAX_KC];
typedef t_mousehandler		t_mousehandlers[MAX_MOUSE];
// typedef	void				(*t_render)(t_rndrdata);

/*
** define some macros to make working woth our types easier
*/

# define SET_TUPLE(tuple, x, y) tuple[0] = x; tuple[1] = y
# define EXP_TUPLE(tuple) tuple[0], tuple[1]

/*
** Root mlx display structure, contains count and pointers to child windows
*/

struct						s_display
{
	void					*mlx;
	int						count;
	t_window				windows[MAX_WINDOWS];
};

/*
** Container for indiviual windows
*/

struct						s_window
{
	void					*window;
	t_frame					frame;
	int						width;
	int						height;
	t_display				display;
	t_evloop				loop;
};

/*
** 
*/

struct						s_image
{
	void					*img;
	char					*addr;
	int						width;
	int						height;
	int						bpp;
	int						s_line;
	int						endian;
	pthread_mutex_t			lock;
};

struct						s_buffer
{
	t_frame					frame;
	t_image					image;
	t_point					tl;
	t_point					rndros;
	t_point					size;
	int						changed;
};

struct						s_frame
{
	t_window				window;
	t_buffer				*buffers;
	int						segments;
	pthread_mutex_t			lock;
};

struct						s_event
{
	int						id;
	int						kc;
	int						state;
	int						x;
	int						y;
	t_point					mpos_cur;
	t_point					mpos_prev;
};

struct						s_evloop
{
	t_window				window;
	t_key					keys;
	t_mouse					mouse;
	void					*model;
	t_handler				*handlers;
	t_queue					events;
	t_genhandler			on_init;
	t_genhandler			on_exit;
	t_genhandler			on_expose;
	t_genhandler			on_tick;
	t_keyhandlers			on_key_press;
	t_keyhandlers			on_key_release;
	t_mousehandlers			on_mouse_press;
	t_mousehandlers			on_mouse_release;
	t_motionhandler			on_mouse_motion;
};

struct						s_rndrdata
{
	t_buffer				buffer;
	t_render				func;
	void					*data;
};

t_display					create_display();
t_display					get_display();
t_window					get_window(int index);
t_window					create_window(t_point size, char *title, int segs, void *data);
t_image						create_image(int width, int height);
t_frame						create_frame(t_window window, int segments);
t_buffer					create_buffer(void);
t_buffer					*create_buffers(t_frame frame, int len);
char						*get_pixel_addr(t_image img, int x, int y);
void						img_set_pixel(t_image img, int x, int y, int clr);
void						draw_image(t_window win, t_image img, int x, int y);
void						draw_buffer(t_buffer buffer);
void						buf_set_pixel(t_buffer buf, int x, int y, int clr);
void						render_frame(t_frame frame);
void						iter_frame(t_frame frame, t_render f, void *data);
void						draw_frame(t_frame frame);
int							pack_color(int r, int g, int b);
void						render(t_frame frame, t_render rdr, void *data);
int							on_key_press(int kc, t_evloop loop);
int							on_key_release(int kc, t_evloop loop);
void						setup_hooks(t_evloop lp, t_window win);
t_evloop					create_loop(t_window win, void *model);
void						register_tick_hook(t_evloop lp, t_genhandler hdlr);
void						register_expose_hook(t_evloop lp, t_genhandler hdlr);
void						register_init_hook(t_evloop lp, t_genhandler hdlr);
void						register_exit_hook(t_evloop lp, t_genhandler hdlr);
void						register_motion_hook(t_evloop lp, t_motionhandler hdlr);
void						register_key_hook(t_evloop lp,
										t_keyhandler hdlr, int kc, int st);
void						register_mouse_hook(t_evloop lp, t_mousehandler hdlr,
								int btn, int state);
int							on_mouse_press(int btn, int x, int y, t_evloop loop);
int							on_mouse_release(int btn, int x, int y, t_evloop loop);
int							on_mouse_motion(int x, int y, t_evloop loop);
void						zero_int_array(int *ar, int size);
void						null_ptr_array(void **ar, int size);
void						iter_frame_t(t_frame frame, t_render f, void *data);
void						threaded_render(t_frame frame, t_render rdr, void *data);
t_event						create_event(int id);
pthread_t					mcrlx_start(void);
t_handlers					init_handlers(void);
void	init_handler(t_event event, t_evloop loop);
void	exit_handler(t_event event, t_evloop loop);
void	expose_handler(t_event event, t_evloop loop);
void	key_handler(t_event event, t_evloop loop);
void	mouse_handler(t_event event, t_evloop loop);
void	motion_handler(t_event event, t_evloop loop);



struct						s_keyevent
{
	int						type;
	t_key					keys;
	int						code;

};

struct						s_mouseevent
{
	int						type;
};

#endif

