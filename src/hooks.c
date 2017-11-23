#include "fractol.h"

void	plus_handler(int kc, t_evloop loop)
{
	t_state	state;

	state = (t_state)(loop->model);
	if (state->scale >= 0.075)
	{
		state->scale -= 0.075;
		state->changed = 1;
	}
	printf("%f\n", state->scale);
}

void	minus_handler(int kc, t_evloop loop)
{
	t_state	state;

	state = (t_state)(loop->model);
	state->scale += 0.075;
	state->changed = 1;	
	printf("%f\n", state->scale);
}

void	render_handler(t_evloop loop)
{
	t_state		state;

	state = (t_state)(loop->model);
	// printf("TICK!\n");
	if (state->changed)
	{
		threaded_render(loop->window->frame, state->mode, loop->model);
		state->changed = 0;
	}
	// REF_SWP;
}

void	offset_handler(t_point cur, t_point prev, t_evloop loop)
{
	int		delta_x;
	int		delta_y;
	t_state	state;

	state = (t_state)(loop->model);

	if ((!prev[0] && !prev[1]))
		return ;
	if (GET_KEY(loop->keys, KEY_LCTRL) || GET_KEY(loop->keys, KEY_RCTRL))
		return ;
	delta_x = cur[0] - prev[0];
	delta_y = cur[1] - prev[1];
	state->offset[0] -= delta_x;
	state->offset[1] -= delta_y;
	state->changed = 1;
	// printf("offset: %i, %i\n", state->offset[0], state->offset[1]);
}

void	esc_handler(int c, t_evloop loop)
{
	REF_LOG;
	REF_CLN;
	exit(0) ;
}