/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:40:53 by tmckinno          #+#    #+#             */
/*   Updated: 2017/11/11 12:40:54 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	log_invalid_arg(char *token)
{
	ft_putstr("Invalid argument '");
	ft_putstr(token);
	ft_putstr("'\n");
}

t_init	parse_type(char *token)
{
	if (!ft_strcmp(token, "julia"))
		return (&init_julia);
	if (!ft_strcmp(token, "mandelbrot"))
		return (&init_mandelbrot);
	if (!ft_strcmp(token, "bship"))
		return (&init_bship);
	log_invalid_arg(token);
	return (NULL);
}

int		parse_flag(char *token, char **rem, int left, t_state state)
{
	IF_RET((is_valid_hexcode(token)), 1);
	if (!ft_strcmp(token, "--start") && left > 0)
		ERR_CNR((parse_hexcode(*rem, &state->cstart)), 1, 1);
	if (!ft_strcmp(token, "--end") && left > 0)
		ERR_CNR((parse_hexcode(*rem, &state->cend)), 1, 1);
	if (!ft_strcmp(token, "--sine") && !(state->color))
		IF_RET((state->color = &sine_gen), 1);
	if (!ft_strcmp(token, "--gradient") && !(state->color))
		IF_RET((state->color = &grad_gen), 1);
	return (0);
}

t_state	parse_args(int ac, char **av)
{
	t_state	state;
	t_init	init;

	if (!(ac && av && *av && **av))
		return (NULL);
	NULL_GUARD((init = parse_type(*av++)));
	state = init();
	state->reset = init;
	state->color = NULL;
	parse_hexcode("FFD64F", &state->cstart);
	parse_hexcode("00C5A1", &state->cend);
	while (ac - 1 > 0)
	{
		IFTR((!parse_flag(*av, av + 1, --ac, state)),
				log_invalid_arg(*av), NULL);
		av++;
	}
	IFTR((!state->color), ft_putstr("No color mode provided!\n"), NULL);
	return (state);
}
