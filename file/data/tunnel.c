/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/17 16:40:34 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

void	get_max_path(t_data *data, t_map *map_ptr)
{
	char	*map;
	int		end;
	int		start;
	int		i;

	i = -1;
	map = map_ptr->map + (data->start_room * map_ptr->col);
	print_map(map, map_ptr->col);
	print_line_first(map, map_ptr->col, 1);
	end = 0;
	while (++i < map_ptr->col)
	{
		if (map[i] == 1)
			end++;
	}
	i = 0;
	map = map_ptr->map + (data->end_room * map_ptr->col);
	start = 0;
	while (i < map_ptr->col)
	{
		if (map[i] == 1)
			start++;
		++i;
	}
	data->lim = start > end ? end : start;
}


