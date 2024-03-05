/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:26:54 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/04 01:43:17 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_path_xpm(char *path)
{
	int	i;

	i = ft_strlen(path) - 5; 
	return (path[i] == '.' && path[i + 1] == 'x'
		&& path[i + 2] == 'p' && path[i + 3] == 'm');
}