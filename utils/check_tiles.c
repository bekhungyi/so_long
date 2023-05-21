/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:00:40 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/21 16:53:39 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_len(t_vars *vars)
{
    int     i;
    int     len;
    
    i = 0;
    len = ft_strlen(vars->map[i]);
    while(vars->map[++i])
    {
        if (len != ft_strlen(vars->map[i]))
            return (0);
    }
    vars->rows = i;
    return (1);
}

int check_walls(t_vars *vars)
{
    int		i;
    int		r_side;
    char	*buffer_top;
	char	*buffer_bottom;

	i = vars->rows;
	buffer_top = vars->map[0];
	buffer_bottom = vars->map[--i];
	r_side = ft_strlen(vars->map[0]) - 1;
	i = -1;
	while (++i < r_side)
	{
		if (buffer_top[i] != '1' || buffer_bottom[i] != '1')
			return (0);
	}
	i = 0;
	while (++i < vars->rows)
	{
		buffer_top = vars->map[i];
		{
			if (buffer_top[0] != '1' || buffer_top[r_side] != '1')
				return (0);
		}
	}
    return (1);
}

int check_tiles(t_vars *vars)
{
    if (check_len(vars) == 0)
        return (0);
    else if (check_walls(vars) == 0)
        return (0);

    return (1);
}