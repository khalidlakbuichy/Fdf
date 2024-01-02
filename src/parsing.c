/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:09:06 by khalid            #+#    #+#             */
/*   Updated: 2024/01/01 17:36:10 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	parsing_map(int fd)
{
	char	*line;
	char	**splited_line;
	int		**map;

	line = get_next_line(fd);
	splited_line = ft_split(line, ' ');
	
}