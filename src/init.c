/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:12:04 by khalid            #+#    #+#             */
/*   Updated: 2024/01/04 08:47:36 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mlx	*init(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (NULL == mlx)
		return (NULL);
	mlx->ptr = mlx_init();
	printf("mlx->ptr: %p\n", mlx->ptr);
	if (NULL == mlx->ptr)
	{
		free(mlx);
		return (NULL);
	}
	puts("Hello");
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "Look at my fdf");
	puts("hi");
	if (mlx->win == NULL)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (NULL);
	}
	mlx->img.img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.line_length, &mlx->img.endian);
	return (mlx);
}
