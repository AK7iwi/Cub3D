/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:13:34 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/07 20:10:30 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

// static	void cpy_rgb(uint8_t tab[], char *rgb) 
// {
// 	uint8_t i;
// 	uint8_t j;
// 	char *tmp;
	
// 	i = 0;
// 	j = 0;	
	
// 	while ()
// 	while (rgb[i] != ",")
// 	{
// 		tmp[i] = rgb[i];
// 		i++;
// 	}
// }

static bool are_rgb_valid(char *rgb)
{
    uint8_t i;
	uint8_t j;
    int 	len;
	char 	*tmp;
	
    len = ft_strlen(rgb) - 1;
    if (len < FORMAT_MIN || len > FORMAT_MAX)
        return (false);
    i = 0;
	while (rgb[++i])
	{
		if (!is_digit(rgb[i]) && rgb[i] != "," && rgb[i] != "\n")
			return (false);
		j = 0;
		while (is_digit(rgb[i]))
			tmp[j++] = rgb[i++];
		if (ft_atoi(tmp) < 0 || ft_atoi(tmp) > 255 || i == 1) 
			return (false);
		tmp = 0;
	}
    return (true);
}

bool 	parse_rgb(t_infos *infos)
{
    t_rgb	rgb;
    
    rgb = (t_rgb){0};
	infos->rgb = &rgb;
	
	if (!are_rgb_valid(infos->infos[FLOOR]))
		return(EXIT_FAILURE);
	cpy_rgb(rgb.rgb_floor, infos->infos[FLOOR]);
    if (!are_rgb_valid(infos->infos[CEILING]))
		return(EXIT_FAILURE);
	cpy_rgb(rgb.rgb_ceiling, infos->infos[CEILING]);
	return(EXIT_SUCCESS);
}
