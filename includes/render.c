/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:28:08 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/22 19:30:32 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../so_long.h"

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

// void    gfx_init(t_vars *vars)
// {
//     vars->bg = mlx_xpm_file_to_image (vars->mlx, "../assets/bg.xpm", &vars->img_l, &vars->img_h);
// }

// void	render_bg(t_vars *vars)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < vars->map_height)
// 	{
// 		j = 0;
// 		while (j < vars->map_length)
// 		{
//             mlx_put_image_to_window(vars->mlx, vars->win, vars->img, i, j);
// 		}
// 		++i;
// 	}
// }

// int render(t_vars *vars)
// {
//     render_background();
//     mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
//     return (0);
// }

// void	win_init(t_vars *vars)
// {
//     void    *image;
//     int width, height;
//     vars->window_closed = 0;

//     vars->mlx = mlx_init();
//     vars->win = mlx_new_window(vars->mlx, vars->map_length *32, vars->map_height *32, "so_long");
//     mlx_loop_hook(vars->mlx, &render, &vars);
// }

////////////////////////////////////

#include "../so_long.h"

static void	img_init(t_vars *vars)
{
	vars->bg = mlx_xpm_file_to_image (vars->mlx, "./assets/bg.xpm", &vars->img_l, &vars->img_h);
    if (vars->bg == NULL)
        ft_printf("No xpm.\n");
	vars->wall = mlx_xpm_file_to_image (vars->mlx, "./assets/1.xpm", &vars->img_l, &vars->img_h);
    if (vars->wall == NULL)
        ft_printf("No xpm.\n");
	vars->player = mlx_xpm_file_to_image (vars->mlx, "./assets/1.xpm", &vars->img_l, &vars->img_h);
    if (vars->player == NULL)
        ft_printf("No xpm.\n");
	vars->collectibles = mlx_xpm_file_to_image (vars->mlx, "./assets/1.xpm", &vars->img_l, &vars->img_h);
    if (vars->collectibles == NULL)
        ft_printf("No xpm.\n");
	vars->exit = mlx_xpm_file_to_image (vars->mlx, "./assets/1.xpm", &vars->img_l, &vars->img_h);
    if (vars->exit == NULL)
        ft_printf("No xpm.\n");
}

static void	size_window_init(t_vars *vars)
{
	int	i;

	vars->map_length = ft_strlen(vars->map[0]) * 32;
	i = 0;
	while (vars->map[i] != NULL)
		i++;
	vars->map_height = i * 32 + 32;
}

void	game_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	size_window_init(vars);
	vars->win = mlx_new_window (vars->mlx, vars->map_length, vars->map_height, "so_long");

	img_init(vars);
    map_draw(vars);
}