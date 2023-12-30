/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:57:37 by khalid            #+#    #+#             */
/*   Updated: 2023/12/27 10:21:20 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_linux/mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_mlx {
	void	*ptr;
	void	*win;
}				t_mlx;

int	mouse_click(int button, int x, int y, void *param)
{
	(void)button; // Unused parameter
	printf("Mouse clicked at: (%d, %d)\n", x, y);
	return (0);
}

int	main(void)
{
	t_mlx	mlx_data;

	mlx_data.ptr = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.ptr, 800, 800, "First window");
	mlx_mouse_hook(mlx_data.win, mouse_click, &mlx_data);
	mlx_loop(mlx_data.ptr);
}
