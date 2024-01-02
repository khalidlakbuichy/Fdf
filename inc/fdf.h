/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:57:30 by khalid            #+#    #+#             */
/*   Updated: 2024/01/02 10:19:10 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libs/libft/libft.h"
# include "../libs/minilibx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define TRUE 1
typedef struct s_data_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data_img;

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
}					t_mlx;

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
	unsigned int	color;
}					t_point;

char				*get_next_line(int fd);
void				parsing_map(int fd);
long int			ft_atoi_hex(const char *hex);

#endif