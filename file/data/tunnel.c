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
	size_t	i;

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


int		same_name(t_dll_l *current_link, void *ptr)
{
	t_room	*room;

	room = current_link->content;
	if (ft_str_eq(room->name, ptr) == TRUE)
		return (TRUE);
	return (FALSE);
}

void	fill_map_with_tunnel(t_data *data, t_map *map)
{
	t_dll_l		*tunnel_link;
	t_tunnel	*tunnel;
	size_t		x;
	size_t		y;

	tunnel_link = data->tunnel.top;
	while (tunnel_link)
	{
		tunnel = tunnel_link->content;
		x = dll_func_index(&data->room, same_name, tunnel->room_1->name, ALL_LIST);
		y = dll_func_index(&data->room, same_name, tunnel->room_2->name, ALL_LIST);
		map->map[(y * map->line) + x] = 1;
		map->map[(x * map->line) + y] = 1;
		tunnel_link = tunnel_link->next;
	}
}
