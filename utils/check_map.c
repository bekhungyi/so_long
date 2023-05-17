/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:48:42 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/17 01:28:24 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_filetype(char *str)
{
    int len;
    len = ft_strlen (str);
    str = ft_substr(str, len - 4, len);
    if (ft_strncmp(str, ".ber", 4) == 0)
    {
        ft_printf("Is a .ber file.\n");
        return (1);
    }
    else
        ft_printf("Not a .ber file.\n");
    return (0);
}