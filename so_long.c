/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:16:50 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/11 18:31:52 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	exitWindow(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		write (1, "Exiting\n", 8);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->dy = -1;
	else if (keycode == 1)
		vars->dy = 1;
	else if (keycode == 0)
		vars->dx = -1;
	else if (keycode == 2)
		vars->dx = 1;
	return (0);
}

void draw_cube(t_data img, int x, int y, int size, int color)
{
    int i;
    int j;

    i = y;
    while (i < y + size)
    {
        j = x;
        while (j < x + size)
        {
            my_mlx_pixel_put(&img, j, i, color);
            j++;
        }
        i++;
    }
}

int render_next_frame(void *vars_ptr)
{
    t_vars *vars;
    vars = (t_vars *)vars_ptr;

    // Update position based on dx and dy
    vars->x += vars->dx;
    vars->y += vars->dy;

    // Clear image
    draw_cube(vars->img, 0, 0, 300, COLOR_RED);

    // Draw cube at new position
    draw_cube(vars->img, vars->x, vars->y, 50, COLOR_RED);

    // Update window
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);

    return (0);
}

int	main(void)
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_vars		vars;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 300, 300, "Hello world");
	img.img = mlx_new_image(mlx, 300, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    vars.x = 100;
	vars.y = 100;
	vars.dx = 0;
	vars.dy = 0;
	draw_cube(img, vars.x, vars.y, 50, COLOR_RED);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	vars.mlx = mlx;
	vars.win = win;
	mlx_hook(vars.win, 2, 1L<<0, exitWindow, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop_hook(mlx, render_next_frame, &vars);
	mlx_loop(mlx);
}
