/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:09:06 by khalid            #+#    #+#             */
/*   Updated: 2024/01/02 11:01:19 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	parsing_map(int fd)
{
	int i;
	int x;
	int y;
	char	*line;
	char	**splited_line;
	char 	**splited_values;
	t_point *point;
	t_list	*head;

	x = 0;
	y = 0;
	head = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (NULL == line)
		{
			free(line);
			break;
		}
		splited_line = ft_split(line, ' ');
		point = malloc(sizeof(t_point));
		if (NULL == point)
			return ;
		printf("line: %s\n", line);
		i = 0;
		while (NULL != splited_line[i])
		{
			char *comma = ft_strnstr(splited_line[i], ",", ft_strlen(splited_line[i]));
			if (NULL != comma)
			{
				splited_values = ft_split(splited_line[i], ',');
				point->z = ft_atoi(splited_values[0]);
				point->color = ft_atoi_hex(splited_values[1]);
			}
			else
			{
				point->z = ft_atoi(splited_line[i]);
				point->color = 0xffffffff;
			}
			point->x = x++;
			point->y = y;
			// printf("x: %d\t", point->x);
			// printf("y: %d\t", point->y);
			// printf("z: %d\t", point->z);
			// printf("color: %ld\n", point->color);
			ft_lstadd_back(&head, ft_lstnew(point));
			i++;
		}
		y++;
	}	
}
