/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:01:37 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/07 19:58:28 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	void	sort_infos(t_infos *infos)
{
	uint8_t i; 
	 
	while (infos->sort_index < INFOS_LEN)
	{
		i = infos->sort_index;	
		if (infos->infos[i][0] == 'N' && infos->infos[i][1] == 'O')
			ft_swap(infos, 0);
		else if (infos->infos[i][0] == 'S' && infos->infos[i][1] == 'O')
			ft_swap(infos, 1);
		else if (infos->infos[i][0] == 'W' && infos->infos[i][1] == 'E')
			ft_swap(infos, 2);
		else if (infos->infos[i][0] == 'E' && infos->infos[i][1] == 'A')
			ft_swap(infos, 3);
		else if (infos->infos[i][0] == 'F')
			ft_swap(infos, 4);
		else if (infos->infos[i][0] == 'C')
			ft_swap(infos, 5);
		infos->sort_index++;
	}
	infos->infos[6] = NULL;
}

static	void	get_clean_infos(t_scene *scene)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < INFOS_LEN)
	{
		j = 0;
		k = 0;
		tmp = scene->scene[i];
		while (tmp[j]) // && != "\n" 
		{
			if (tmp[j] != ' ')
				scene->scene[i][k++] = tmp[j++];
			else
				j++;
		}
		scene->scene[i][k] = '\0';
		scene->infos->infos[i] = scene->scene[i];
		i++;
	}
	scene->infos->infos[i] = NULL;
}

bool	get_infos(t_scene *scene) // in parse info
{
	scene->infos->infos = malloc(sizeof(char *) * (7));
	if (!scene->infos->infos)
		return (EXIT_FAILURE);
	get_clean_infos(scene);
	sort_infos(scene->infos);
	return (EXIT_SUCCESS);
}
