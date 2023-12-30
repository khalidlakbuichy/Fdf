/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:43:59 by khalid            #+#    #+#             */
/*   Updated: 2023/12/28 08:23:12 by khalid           ###   ########.fr       */
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
}			t_data;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}			t_mlx;

int handle_input(int keysym, t_mlx *mlx_data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(mlx_data->ptr, mlx_data->ptr);
        mlx_destroy_display(mlx_data->ptr);
        free(mlx_data->ptr);
        exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);
    return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close(int keycode, t_mlx *mlx_data)
{
	mlx_destroy_window(mlx_data->ptr, mlx_data->win);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void drawline(t_data *data, int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
    
    dx = x1 - x0;
    dy = y1 - y0;
    
    x = x0;
    y = y0;
    
    p = (2 * dy) -dx;
    
    while(x < x1)
    {
        if(p >= 0)
        {
            my_mlx_pixel_put(data, x, y, create_trgb(0, 255, 0, 0));
            y = y + 1;
            p = p + (2 * dy) - (2 * dx);
        }
        else
        {
			my_mlx_pixel_put(data, x, y, create_trgb(0, 255, 0, 0));
            p = p + (2 * dy);
        }
        x = x + 1;
    }
}

int	main(void)
{
	t_mlx mlx_data;
	t_data img;

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
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	drawline(&img, 30, 20, 15, 51);
	mlx_put_image_to_window(mlx_data.ptr, mlx_data.win, img.img, 0, 0);
	mlx_key_hook(mlx_data.ptr, handle_input, &mlx_data);
	mlx_loop(mlx_data.ptr);
}