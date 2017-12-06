/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:52:07 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/01 15:52:09 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_state	state;

	state = parse_args(--ac, av + 1);
	if (!state)
	{
		print_help(av[0]);
		exit(1);
	}
	create_app(state, "FractMac");
	mcrlx_start();
	return (0);
}
