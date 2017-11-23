/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 18:40:49 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/16 18:40:52 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mcrlx.h"
#include "clct.h"

t_image	create_image(int width, int height)
{
	t_display	display;
	t_image		img;

	NULL_GUARD((display = get_display()));
	NULL_GUARD((img = (t_image)(memalloc(sizeof(struct s_image)))));
	img->img = mlx_new_image(display->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img,
								&img->bpp, &img->s_line, &img->endian);
	img->width = width;
	img->height = height;
	pthread_mutex_init(&img->lock, NULL);
	return (img);
}

void	draw_image(t_window win, t_image img, int x, int y)
{
	t_display display;

	NULL_GUARD_NR((display = get_display()));
	mlx_put_image_to_window(display->mlx, win->window, img->img, x, y);
}

char	*get_pixel_addr(t_image img, int x, int y)
{
	int		offset;

	offset = (x * 4) + (y * img->s_line);
	return (img->addr + offset);
}

void	img_set_pixel(t_image img, int x, int y, int color)
{
	char			*addr;
	unsigned int	clr;

	// printf("img setting pixel at: %i, %i\n", x, y);
	if (!(x < img->width) || !(y < img->height))
		return ;
	// if (pthread_mutex_lock(&img->lock))
	// 	return ;
	addr = get_pixel_addr(img, x, y);
	clr = mlx_get_color_value(get_display()->mlx, color);
	// printf("%p\n", addr);
	// printf("%i - %i\n", img->bpp, img->s_line);
	// printf("%i\n", mlx_get_color_value(get_display()->mlx, color));
	*addr = color;
	*++addr = color >> 8;
	*++addr = color >> 16;
	// pthread_mutex_unlock(&img->lock);
}