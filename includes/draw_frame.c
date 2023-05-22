/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:00:23 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/23 02:16:10 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// draw img

void	img_draw(t_vars *vars, void *image, int x, int y)
{
	mlx_put_image_to_window
		(vars->mlx, vars->win, image, x * 32, y *32);
}

// sets the player pos and then img_draw

static void	player_draw(t_vars *vars, void *image, int x, int y)
{
	vars->x = x;
	vars->y = y;
	img_draw(vars, image, x, y);
}

// loops through the double array and renders the img

// int	map_draw(t_vars	*vars)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (vars->map[++y])
// 	{
// 		x = -1;
// 		while (vars->map[y][++x])
// 		{
// 			if (vars->map[y][x] == '1')
// 				img_draw(vars, vars->wall, x, y);
// 			else if (vars->map[y][x] == '0')
// 				img_draw(vars, vars->bg, x, y);
// 			else if (vars->map[y][x] == 'P')
// 				player_draw(vars, vars->player, x, y);
// 			else if (vars->map[y][x] == 'C')
// 				img_draw(vars, vars->collectibles, x, y);
// 			else if (vars->map[y][x] == 'E')
// 				img_draw(vars, vars->exit, x, y);
// 			// else if (vars->map[y][x] == 'N')
// 			// 	img_draw(vars, vars->img_n, x, y);
// 		}
// 	}
// 	return (0);
// }

void map_draw(t_vars *vars)
{
    int x, y;

    x = 0;
    while (x < vars->map_height)
    {
        y = 0;
        while (y < vars->map_length)
        {
            // Check if the current cell is the player's position
            if (x == vars->x && y == vars->y)
                mlx_put_image_to_window(vars->mlx, vars->win, vars->player, y * 32, x * 32);
            else
            {
                // Draw the corresponding image based on the cell value
                if (vars->map[x][y] == '1')
                    mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, y * 32, x * 32);
                else if (vars->map[x][y] == 'E')
                    mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, y * 32, x * 32);
                else if (vars->map[x][y] == 'C')
                    mlx_put_image_to_window(vars->mlx, vars->win, vars->collectibles, y * 32, x * 32);
                else
                    mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, y * 32, x * 32);
            }
            y++;
        }
        x++;
    }
}