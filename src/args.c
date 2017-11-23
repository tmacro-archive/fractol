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

# include "fractol.h"

int		is_valid_flag(char *arg)
{
	ERR_CNR(arg, NULL, 0);
	ERR_CNR(ft_strcmp(arg, "--julia"), 0, 1);
	ERR_CNR(ft_strcmp(arg, "--mandelbrot"), 0, 1);
	return (0);
}

void	parse_arg(char *token, char **rem, t_args args)
{
	if (!ft_strcmp(token, "--julia"))
		args->julia = 1;
	if (!ft_strcmp(token, "--mandelbrot"))
		args->mandel = 1;
}

t_args	parse_args(int ac, char **av)
{
	char	*token;
	t_args	args;

	NULL_GUARD((args = memalloc(sizeof(struct s_args))));
	args->julia = 0;
	args->mandel = 0;
	args->error = 0;
	while (ac--)
	{
		token = *av++;
		printf("token: %s\n", token);
		if (is_valid_flag(token))
			parse_arg(token, av, args);
	}
	return (args);
}