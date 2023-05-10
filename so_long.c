/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:16:50 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/10 18:10:29 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_circle(t_data *img, int x0, int y0, int radius, int color)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        my_mlx_pixel_put(img, x0 + x, y0 + y, color);
        my_mlx_pixel_put(img, x0 + y, y0 + x, color);
        my_mlx_pixel_put(img, x0 - y, y0 + x, color);
        my_mlx_pixel_put(img, x0 - x, y0 + y, color);
        my_mlx_pixel_put(img, x0 - x, y0 - y, color);
        my_mlx_pixel_put(img, x0 - y, y0 - x, color);
        my_mlx_pixel_put(img, x0 + y, y0 - x, color);
        my_mlx_pixel_put(img, x0 + x, y0 - y, color);

        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }
        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void    horLine(t_data  img, int x, int y)
{   
    while (y <= 200)
    {
        my_mlx_pixel_put(&img, y, x, 0x00FFFF00);
        y++;
    }
}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

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
    printf("Keycode is: %d\n", keycode);
    return (0);
}

int render_next_frame(int keycode, t_vars *data)
{
    if (keycode == 0)
        data->win;
    return (0);
}

int	main(void)
{
	void	    *mlx;
    void        *win;
    t_data      img;
    int         x, y;
    t_vars      vars;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 300, 300, "Hello world");
	img.img = mlx_new_image(mlx, 300, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    x = 150;
    y = 150;
    draw_circle(&img, x, y, 25, 0x00FF0000);
    // while (x <= 200)
    // {
    //     horLine(img, x, y);
    //     x++;
    // }
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
    vars.mlx = mlx;
    vars.win = win;
    mlx_hook(vars.win, 2, 1L<<0, exitWindow, &vars);
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(mlx, render_next_frame, &vars);
    mlx_loop(mlx);
}
