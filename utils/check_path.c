/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:52:20 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/21 20:01:40 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char    **clone_map(t_vars *vars)
{
    int     i;
    char    **map_clone;

    map_clone = (char**)malloc(vars->map_height * sizeof(char*));

    i = 0;
    while (i < vars->map_height)
    {
        map_clone[i] = strdup(vars->map[i]);
        i++;
    }
    return map_clone;
}

void free_map_clone(char** map_clone, t_vars *vars)
{
    int i;

    i = 0;
    while (i < vars->map_height)
    {
        free(map_clone[i]);
        i++;
    }
    free(map_clone);
}

int check_valid_path(t_vars *vars)
{
    int     i;
    char    **map_clone;

    i = 0;
    map_clone = clone_map(vars);
    ft_printf ("%s", map_clone[5]);
    return (1);
}