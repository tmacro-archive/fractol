/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:40:35 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/04 23:40:38 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcrlx.h"

t_color parse_hexcode(char *hex)
{
	t_color	color;
	
	color.rgb.r = (HX(*hex) * 16) + HX(*(hex + 1));
	hex += 2;
	color.rgb.g = (HX(*hex) * 16) + HX(*(hex + 1));
	hex += 2;
	color.rgb.b = (HX(*hex) * 16) + HX(*(hex + 1));
	return (color);
}

int		is_valid_hexcode(char *hex)
{
	int	len;

	len = 0;
	ERR_CNR(hex, NULL, 0);
	while (*hex && ++len <= 6)
		if (!(*hex >= '0' && *hex <= '9' && *hex >= 'A' && *hex++ <= 'F'))
			return (0);
	return (1);
}

t_color	step_to_color(t_color s, t_color e, int step)
{
	int		diff;
	t_color	ret;

	step = step % 128;
	diff = (s.rgb.r > e.rgb.r) ? (s.rgb.r - e.rgb.r) : (e.rgb.r - s.rgb.r);
	diff = lroundf((diff / 128.0) * step);
	ret.rgb.r = (s.rgb.r > e.rgb.r) ? (s.rgb.r - diff) : (s.rgb.r + diff);
	diff = (s.rgb.g > e.rgb.g) ? (s.rgb.g - e.rgb.g) : (e.rgb.g - s.rgb.g);
	diff = lroundf((diff / 128.0) * step);
	ret.rgb.g = (s.rgb.g > e.rgb.g) ? (s.rgb.g - diff) : (s.rgb.g + diff);	
	diff = (s.rgb.b > e.rgb.b) ? (s.rgb.b - e.rgb.b) : (e.rgb.b - s.rgb.b);
	diff = lroundf((diff / 128.0) * step);
	ret.rgb.b = (s.rgb.b > e.rgb.b) ? (s.rgb.b - diff) : (s.rgb.b + diff);
	return (ret);	
}