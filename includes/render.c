/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:28:08 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/23 03:20:12 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	close_win(int keycode, void *param)
// {
//     t_vars *vars = (t_vars *)param;
    
//     if (keycode == 53)
//     {
// 	    mlx_destroy_window(vars->mlx, vars->win);
//         vars->window_closed = 1;
//         return (1);
//     }
// 	return (0);
// }

int	check_step(t_vars *vars, char key)
{
	int		x, y;
	char	c;

	x = vars->x;
	y = vars->y;
	if (key == 'W' && x--)
	{
		c = vars->map[x][y];
		if (c == '1')
			return (0);
	}
	else if (key == 'S' && x++)
	{
		c = vars->map[x][y];
		if (c == '1')
			return (0);
	}
	else if (key == 'A' && y--)
	{
		c = vars->map[x][y];
		if (c == '1')
			return (0);
	}
	else if (key == 'D' && y++)
	{
		c = vars->map[x][y];
		if (c == '1')
			return (0);
	}
	return (1);
}

int handle_key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
	else if (keycode == 13 && check_step(vars, 'W') == 1)
	{
		vars->steps++;
		(vars->x)--;
	}
	else if (keycode == 1 && check_step(vars, 'S') == 1)
	{
		vars->steps++;
		(vars->x)++;
	}
	else if (keycode == 0 && check_step(vars, 'A') == 1)
	{
		vars->steps++;
		(vars->y)--;
	}
	else if (keycode == 2 && check_step(vars, 'D') == 1)
	{
		vars->steps++;
		(vars->y)++;
	}
	ft_printf ("Walked %i steps.\n", vars->steps);
    map_draw(vars);
    return (0);
}

void	render_px(t_vars *vars)
{
	vars->bg = mlx_xpm_file_to_image (vars->mlx, "./assets/space.xpm", &vars->img_l, &vars->img_h);
	vars->wall = mlx_xpm_file_to_image (vars->mlx, "./assets/wall.xpm", &vars->img_l, &vars->img_h);
	vars->player = mlx_xpm_file_to_image (vars->mlx, "./assets/player.xpm", &vars->img_l, &vars->img_h);
    vars->exit = mlx_xpm_file_to_image (vars->mlx, "./assets/exit.xpm", &vars->img_l, &vars->img_h);
	vars->collectibles = mlx_xpm_file_to_image (vars->mlx, "./assets/collect.xpm", &vars->img_l, &vars->img_h);
}

void	render(t_vars *vars)
{
	vars->steps = 0;
	vars->mlx = mlx_init();
	// size_window_init(vars);
	vars->win = mlx_new_window (vars->mlx, vars->map_length *32, vars->map_height *32, "so_long");

	render_px(vars);
    map_draw(vars);

	mlx_hook(vars->win, 2, (1L << 0), handle_key_press, vars);

    mlx_loop(vars->mlx);

	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
