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


void print_legende(int size)
{
	int i;

	i = 0;
	ft_printf("  ");
	while (i < size)
	{
		ft_printf("%2c", i + 'A');
		++i;
	}
	ft_printf(" \n");
}

void test_col(t_map *map)
{
	size_t i;
	size_t y;

	i = 0;
	y = 0;
	print_legende(map->line);
	ft_printf("1 ");
	while (y < map->col)
	{
		ft_printf("%2c", map->map[i + (y * map->col)] ? 'X' : '.');
		if (i == map->col - 1)
		{
			if (y < map->line - 1)
				ft_printf(" \n%c ", y + '1' + 1);
			++y;
			i = 0;
			continue;
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

void fill_map_with_tunnel(t_data *data, t_map *map, t_debug *debug)
{
	t_dll_l *tunnel_link;
	t_tunnel *tunnel;
	int x;
	int y;

	tunnel_link = data->tunnel.top;
	while (tunnel_link)
	{
		tunnel = tunnel_link->content;

		x = (tunnel->room_1->nb * map->line) + tunnel->room_2->nb;
		y = (tunnel->room_2->nb * map->line) + tunnel->room_1->nb;

		map->map[(tunnel->room_1->nb * map->line) + tunnel->room_2->nb] = 1;
		map->map[(tunnel->room_2->nb * map->line) + tunnel->room_1->nb] = 1;
		tunnel_link = tunnel_link->next;
		test_col(map);
	}
}

int set_up_tunnel_map(t_map *map, t_data *data, t_debug *debug)
{
	map->col = data->room.length;
	map->line = data->room.length;
	map->size = data->room.length * data->room.length;
	if (ft_str_new(&map->map, map->size) != OK)
		return (FAIL);
	fill_map_with_tunnel(data, map, debug);
	//	print_path_map(map->map, map->col, map->col);
	test_col(map);
	// if debug algo je print la map ici :) // je fais aussi write tout l'outpout quelque par !!

	return (OK);
}