/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 01:37:29 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/22 02:23:20 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	walk_player(char **map, int x, int y, t_vars *vars)
{
	if (map[x][y] == 'E')
		return (1);
	
	map[x][y] = 'V';
	
	// Explore up
	if (x > 0 && map[x-1][y] != 'V' && map[x-1][y] != '1') {
		if (walk_player(map, x-1, y, vars) == 1) {
			return 1;
		}
	}

	// Explore down
	if (x < vars->map_height - 1 && map[x+1][y] != 'V' && map[x+1][y] != '1') {
		if (walk_player(map, x+1, y, vars) == 1) {
			return 1;
		}
	}

	// Explore left
	if (y > 0 && map[x][y-1] != 'V' && map[x][y-1] != '1') {
		if (walk_player(map, x, y-1, vars) == 1) {
			return 1;
		}
	}

	// Explore right
	if (y < vars->map_length - 1 && map[x][y+1] != 'V' && map[x][y+1] != '1') {
		if (walk_player(map, x, y+1, vars) == 1) {
			return 1;
		}
	}

	return (0);
}