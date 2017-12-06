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

int		parse_hexcode(char *hex, t_color *color)
{
	if (!is_valid_hexcode(hex))
		return (0);
	color->r = (HX(*hex) * 16) + HX(*(hex + 1));
	hex += 2;
	color->g = (HX(*hex) * 16) + HX(*(hex + 1));
	hex += 2;
	color->b = (HX(*hex) * 16) + HX(*(hex + 1));
	return (1);
}

int		is_valid_hexcode(char *hex)
{
	int	len;

	len = 0;
	ERR_CNR(hex, NULL, 0);
	while (*hex && ++len <= 6)
		if (!((*hex >= '0' && *hex <= '9') || (*hex >= 'A' && *hex <= 'F')))
			return (0);
		else
			hex++;
	return (1);
}

t_color	step_to_color(t_color s, t_color e, int step)
{
	int		diff;
	t_color	ret;

	step = step % 64;
	diff = (s.r > e.r) ? (s.r - e.r) : (e.r - s.r);
	diff = lroundf((diff / 64.0) * step);
	ret.r = (s.r > e.r) ? (s.r - diff) : (s.r + diff);
	diff = (s.g > e.g) ? (s.g - e.g) : (e.g - s.g);
	diff = lroundf((diff / 64.0) * step);
	ret.g = (s.g > e.g) ? (s.g - diff) : (s.g + diff);
	diff = (s.b > e.b) ? (s.b - e.b) : (e.b - s.b);
	diff = lroundf((diff / 64.0) * step);
	ret.b = (s.b > e.b) ? (s.b - diff) : (s.b + diff);
	return (ret);
}
