/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:48:42 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/17 17:33:37 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int read_map(char *filename)
{
    int fd;

    fd = open (filename, O_RDONLY);
    
    return (fd);
}

int check_filetype(char *str)
{
    int len;
    len = ft_strlen (str);
    str = ft_substr(str, len - 4, len);
    if (ft_strncmp(str, ".ber", 4) == 0)
        return (1);
    return (0);
}

int check_map(int ac, char **av, t_vars vars)
{
    int ret;

    if (ac == 2 && check_filetype(av[1]) == 1)
    {
        if (read_map(av[1]) != -1)
            return (1);
    }
    return (0);
}