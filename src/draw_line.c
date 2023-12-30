/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:00:12 by khalid            #+#    #+#             */
/*   Updated: 2023/12/28 12:00:30 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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