/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:31:06 by khalid            #+#    #+#             */
/*   Updated: 2023/12/26 09:12:04 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_linux/mlx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    void *mlx_ptr;
    
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (1);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
        
}