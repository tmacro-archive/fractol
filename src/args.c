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
	ft_putstr("Invalid arguement \"");
	ft_putstr(token);
	ft_putstr("\"\n");
}

t_state	parse_type(char *token)
{
	if (!ft_strcmp(token, "--julia"))
		return (init_julia());
	if (!ft_strcmp(token, "--mandelbrot"))
		return (init_mandelbrot());
	if (!ft_strcmp(token, "--bship"))
		return (init_bship());
	log_invalid_arg(token);
	return (NULL);
}

t_state	parse_args(int ac, char **av)
{
	t_state	state;

	if (!(ac && av && *av && **av) || ac > 3)
		return (NULL);
	NULL_GUARD((state = parse_type(*av++)));
	if (ac == 3)
	{
		state->cstart = parse_hexcode(*av++);		
		state->cend = parse_hexcode(*av);
	}
	else if (ac == 2)
	{
		state->cstart = parse_hexcode(*av);
		state->cend = parse_hexcode("FFFFFF");
	}
	else
	{
		state->cstart = parse_hexcode("010101");
		state->cend = parse_hexcode("FFFFFF");
	}
	return (state);
}