/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:49:40 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/19 12:49:42 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"

int		pack_color(int r, int g, int b)
{
	int color;

	color = 0;
	color |= (0 & 255) << 24;
	color |= (r & 255) << 16;
	color |= (g & 255) << 8;
	color |= (b & 255);
	return (color);
}

void	zero_int_array(int *ar, int size)
{
	while (--size >= 0)
		ar[size] = 0;
}

void	null_ptr_array(void **ar, int size)
{
	while (--size >= 0)
		ar[size] = 0;
}
