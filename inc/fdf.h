/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:57:30 by khalid            #+#    #+#             */
/*   Updated: 2024/01/04 09:08:16 by khalid           ###   ########.fr       */
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
typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
	t_img			img;
}					t_mlx;


t_mlx				*init(void);
char				*get_next_line(int fd);
t_list				*parsing_map(int fd);
void				drawLine(t_img *img, int x0, int y0, int x1, int y1);
long int			ft_atoi_hex(const char *hex);
void				drawing_points(t_list *head, t_mlx *mlx);

#endif