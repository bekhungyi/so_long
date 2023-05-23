/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:44:22 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/23 19:00:28 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_game(void *param)
{
	exit(0);
}

void	pickup(t_vars *vars, int x, int y)
{
	vars->map[x][y] = '0';
	vars->total_collected++;
}

void	reach_exit(t_vars *vars, int x, int y)
{
	if (vars->total_collected == vars->c_count)
		exit_game(NULL);
	else
		return;
}

void	event(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->x;
	y = vars->y;
	if (vars->map[x][y] == 'C')
		pickup(vars, x, y);
	if (vars->map[x][y] == 'E')
		reach_exit(vars, x, y);
}
