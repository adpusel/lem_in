/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_includes.h"
// la map avec les tunnels --> je fait :
// je dois printe les lignes et les legende// print juste le tab
// je dois printer les colomnes


void test_col(t_map *map)
{
	size_t i;
	size_t y;

	i = 0;
	y = 0;
	while (y < map->col)
	{
		ft_printf("%2c", map->map[i + y * map->col] ? 'X' : '.');
		if (i == map->col)
		{
			ft_printf(" \n");
			++y;
			i = 0;
		}
		i++;
	}
}

void print_tunnel_map(t_debug *debug, t_map *map)
{
	if (debug->print_algo)
	{
		print_path_map(map->map, map->col, map->col);
	}
}

int same_name(t_dll_l *current_link, void *ptr)
{
	t_room *room;

	room = current_link->content;
	if (ft_str_eq(room->name, ptr) == TRUE)
		return (TRUE);
	return (FALSE);
}

void fill_map_with_tunnel(t_data *data, t_map *map, t_debug *debug)
{
	t_dll_l *tunnel_link;
	t_tunnel *tunnel;


	tunnel_link = data->tunnel.top;
	while (tunnel_link)
	{
		tunnel = tunnel_link->content;
		map->map[(tunnel->room_1->nb * map->line) + tunnel->room_2->nb] = 1;
		map->map[(tunnel->room_2->nb * map->line) + tunnel->room_1->nb] = 1;
		tunnel_link = tunnel_link->next;
	}
}

int set_up_tunnel_map(t_map *map, t_data *data, t_debug *debug)
{
	map->col = data->room.length;
	map->size = data->room.length * data->room.length;
	if (ft_str_new(&map->map, map->size) != OK)
		return (FAIL);
	fill_map_with_tunnel(data, map, debug);
//	print_path_map(map->map, map->col, map->col);
	test_col(map);
	// if debug algo je print la map ici :) // je fais aussi write tout l'outpout quelque par !!

	return (OK);
}