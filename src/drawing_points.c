/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:45:02 by khalid            #+#    #+#             */
/*   Updated: 2024/01/04 08:54:44 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// void	drawing_points(t_list *head, t_mlx *mlx)
// {
// 	t_list			*curr;
// 	unsigned int	scale;
// 	unsigned int	tmp_y;

// 	curr = head;
// 	scale = 30;
// 	while (curr != NULL)
// 	{
// 		tmp_y = curr->content->y;
// 		if (curr)
// 		drawLine(&mlx->img, (curr->content->x * scale),
// 		(curr->content->y * scale), (curr->content->x * scale + 10),
// 		(curr->content->y * scale));
// 		drawLine(&mlx->img, (curr->content->x * scale),
// 		(curr->content->y * scale), (curr->content->x * scale),
// 		(curr->content->y * scale + 10));
// 		curr = curr->next;
// 	}
// }
