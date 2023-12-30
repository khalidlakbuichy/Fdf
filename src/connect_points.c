/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 08:50:18 by khalid            #+#    #+#             */
/*   Updated: 2023/12/28 12:10:20 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_linux/mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}			t_mlx;

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	drawline(t_data_img *img, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	x = x0, y;
	int	x_inc;
	int	y_inc;
	int	p;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	x = x0, y = y0;
	x_inc = (x1 > x0) ? 1 : -1;
	y_inc = (y1 > y0) ? 1 : -1;
	if (dx > dy)
	{
		p = 2 * dy - dx;
		while (x != x1)
		{
			my_mlx_pixel_put(img, x, y, create_trgb(0, 255, 0, 0));
			x += x_inc;
			if (p >= 0)
			{
				y += y_inc;
				p += 2 * (dy - dx);
			}
			else
			{
				p += 2 * dy;
			}
		}
	}
	else
	{
		p = 2 * dx - dy;
		while (y != y1)
		{
			my_mlx_pixel_put(img, x, y, create_trgb(0, 255, 0, 0));
			y += y_inc;
			if (p >= 0)
			{
				x += x_inc;
				p += 2 * (dx - dy);
			}
			else
			{
				p += 2 * dx;
			}
		}
	}
}

int	main(void)
{
	t_mlx mlx_data;
	t_data_img img;

	mlx_data.ptr = mlx_init();
	if (mlx_data.ptr == NULL)
		return (1);

	mlx_data.win = mlx_new_window(mlx_data.ptr, WIDTH, HEIGHT, "first window!");
	if (mlx_data.win == NULL)
	{
		free(mlx_data.ptr);
		return (1);
	}

	img.img = mlx_new_image(mlx_data.ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	int x;
	int y;

	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			drawline(&img, x, y, x + 1, y);
			drawline(&img, x, y, x, y + 50);
			x += 50;
		}
		y += 50;
	}

	mlx_put_image_to_window(mlx_data.ptr, mlx_data.win, img.img, 0, 0);
	mlx_loop(mlx_data.ptr);
}