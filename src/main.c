/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:09:33 by khalid            #+#    #+#             */
/*   Updated: 2024/01/04 09:19:18 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	int fd;
	t_mlx *mlx;
	t_list *head;

	head = NULL;
	if (ac != 2)
	{
		// Error message like: please enter a map !!
		// exit with failure !
	}
	else
	{
		// check for the file extension
		fd = open(av[1], O_RDONLY);
		mlx = init();
		head = parsing_map(fd);
		printf("lstsize: %d\n", ft_lstsize(head));
		while (NULL != head)
		{
			printf("color: %ld\n", (head->content->color));
			printf("x: %ld\n", (head->content->x));
			printf("y: %ld\n", (head->content->y));
			printf("z: %ld\n", (head->content->z));
			head = head->next;
		}
		
		// drawLine(&mlx->img, 50, 50, 100, 200);
		// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0, 0);
		// mlx_loop(mlx->ptr);
	}
}