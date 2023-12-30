#include "../minilibx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 400
#define HEIGHT 400

int	main(void)
{
	void *mlx_ptr;
	void *mlx_window1;
	void *mlx_window2;

	/* connecting to the x-window server */
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (-1);

	/* making new window */
	mlx_window1 = mlx_new_window(mlx_ptr, HEIGHT, WIDTH, "First_window");
	if (mlx_window1 == NULL)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return (1);
	}

	mlx_window2 = mlx_new_window(mlx_ptr, HEIGHT, WIDTH, "second_window");
	if (mlx_window2 == NULL)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return (1);
	}

	/* the event loop for making the window alive */
	mlx_loop(mlx_ptr);
}