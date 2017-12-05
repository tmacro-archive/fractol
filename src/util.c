/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:56:46 by tmckinno          #+#    #+#             */
/*   Updated: 2017/11/12 13:56:47 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(char *name)
{
	ft_putstr("Usage: ");
	ft_putstr(name);
	ft_putstr(" [--mandelbrot, --julia, --bship]\n");
}

void	e_handler(t_evloop loop)
{
	REF_LOG;
	REF_CLN;
	REF_LOG;
	exit(0);
}

void	esc_handler(int c, t_evloop loop)
{
	c = 0;
	e_handler(loop);
}

/*
** ft_putstr("Multiple arguments can be specified\n");
*/
