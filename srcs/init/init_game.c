/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:57:27 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/29 13:29:08 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_first_orientation_two(t_data *data, char c)
{
	if (c == 'N')
	{
		data->game->player_or_x = 0;
		data->game->player_or_y = 1;
		data->game->plane_x = -0.66;
		data->game->plane_y = 0;
	}
	if (c == 'W')
	{
		data->game->player_or_x = -1;
		data->game->player_or_y = 0;
		data->game->plane_x = 0;
		data->game->plane_y = -0.66;
	}
}

void	set_first_orientation(t_data *data, char c)
{
	if (c == 'S')
	{
		data->game->player_or_x = 0;
		data->game->player_or_y = -1;
		data->game->plane_x = 0.66;
		data->game->plane_y = 0;
	}
	if (c == 'E')
	{
		data->game->player_or_x = 1;
		data->game->player_or_y = 0;
		data->game->plane_x = 0; 
		data->game->plane_y = 0.66;
	}
	set_first_orientation_two(data, c);
}

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'W')
			{
				data->game->player_pos_x = (double)j + 0.5;
				data->game->player_pos_y = (double)i + 0.5;
				set_first_orientation(data, data->map[i][j]); //to deplace 
			}
			j++;
		}
		i++;
	}
}
