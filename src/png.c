/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:34:16 by khalid            #+#    #+#             */
/*   Updated: 2023/12/27 10:42:18 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minilibx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	void *mlx;
	void *win;
	void *img;
	int width, height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Image Display");

	img = mlx_xpm_file_to_image(mlx, "open.xpm", &width, &height);
	if (img == NULL)

	mlx_put_image_to_window(mlx, win, img, 0, 0);

	mlx_loop(mlx);
}
