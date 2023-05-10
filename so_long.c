/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:16:50 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/10 17:26:03 by bhung-yi         ###   ########.fr       */
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
    
    x = 100;
    y = 100;
    while (x <= 200)
    {
        horLine(img, x, y);
        x++;
    }
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
    vars.mlx = mlx;
    vars.win = win;
    mlx_hook(vars.win, 2, 1L<<0, exitWindow, &vars);
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(mlx);
}
