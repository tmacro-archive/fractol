/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:42:37 by tmckinno          #+#    #+#             */
/*   Updated: 2017/12/04 23:42:39 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define HX(x) ((x >= 'A') ? (x - 'A' + 10) : (x - '0'))

union					u_color
{
	unsigned int		i;
	struct				s_color
	{
		unsigned int	a:8;
		unsigned int	r:8;
		unsigned int	g:8;
		unsigned int	b:8;
	}					rgb;
};

typedef union u_color	t_color;

t_color					step_to_color(t_color s, t_color e, int step);
t_color 				parse_hexcode(char *hex);
int						is_valid_hexcode(char *hex);

#endif
