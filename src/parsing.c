/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:09:06 by khalid            #+#    #+#             */
/*   Updated: 2024/01/04 09:33:57 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void del(void *ptr)
{
	if (NULL != ptr)
		free(ptr);	
}

int	slice_line(char **splited, t_point *point, t_list **head, int *xy)
{
	char	**splited_values;
	int		i;
	char	*comma;

	i = 0;
	while (NULL != splited[i])
	{
		comma = ft_strnstr(splited[i], ",", ft_strlen(splited[i]));
		if (NULL != comma)
		{
			splited_values = ft_split(splited[i], ',');
			if (NULL == splited_values)
				return (-1);
			point->z = ft_atoi(splited_values[0]);
			point->color = ft_atoi_hex(splited_values[1]);
		}
		else
		{
			point->z = ft_atoi(splited[i]);
			point->color = 0xffffffff;
		}
		point->x = xy[0]++;
		point->y = xy[1];
		printf("x: %d\t", point->x);
		printf("y: %d\t", point->y);
		printf("z: %d\t", point->z);
		printf("color: %ld\n", point->color);
		ft_lstadd_back(head, ft_lstnew(point));
		i++;
	}
	return (1);
}

t_list	*parsing_map(int fd)
{
	char	**splited_line;
	char	*line;
	int		xy[2];
	t_point	*point;
	t_list	*head;

	xy[0] = 0;
	xy[1] = 0;
	head = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (NULL == line)
		{
			puts("get_next_line buy");
			free(line);
			break;
		}
		splited_line = ft_split(line, ' ');
		if (NULL == splited_line)
		{
			puts("Leaks2");
			free(line);
			ft_lstclear(&head, del);
			return (NULL);
		}
		int i = 0;
		// while (splited_line[i] != 0)
		// {
		// 	i++;
		// }
		point = malloc(sizeof(t_point));
		if (NULL == point)
		{
			puts("Leaks3");
			free(line);
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (slice_line(splited_line, point, &head, xy) == -1)
		{
			puts("Leaks4");
			free(line);
			ft_lstclear(&head, del);
			return (NULL);
		}
		xy[1]++;
	}
	return (head);
}
