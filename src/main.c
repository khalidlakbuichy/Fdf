/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:09:33 by khalid            #+#    #+#             */
/*   Updated: 2024/01/01 17:29:11 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	int fd;

	if (ac != 2)
	{
		// Error message like: please enter a map !!
		// exit with failure !
	}
	else
	{
        // check for the file extension
        fd = open(av[1], O_RDONLY);
        parsing_map(fd);
        
	}
}