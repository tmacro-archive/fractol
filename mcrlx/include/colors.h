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

struct					s_color
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
};

typedef struct s_color	t_color;

t_color					step_to_color(t_color s, t_color e, int step);
int						parse_hexcode(char *hex, t_color *color);
int						is_valid_hexcode(char *hex);

#endif
