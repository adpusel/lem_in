/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/17 16:31:46 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/all_includes.h"

void		add_all_path(char *map, t_dll_l *path_link, size_t line)
{
	t_path	*path;

	path = path_link->content;
	path = path->prev;
	while (path->prev)
	{
		map[path->room + line] = 1;
		path = path->prev;
	}
}

t_map		*generate_path_map(t_dll *room, t_dll *path_lst)
{
	t_dll_l		*link;
	t_map		*map;
	size_t		i;

	i = 0;
	link = path_lst->top;
	//todo deux malloc
	map = NULL;
//	map = ft_0_new_memory(sizeof(t_map_00));
	map->col = room->length;
	map->line = path_lst->length;
//	map->map = ft_0_new_memory(sizeof(char) * map->line * map->col);
	while (link)
	{
		add_all_path(map->map, link, i * map->col);
		link = link->next;
		++i;
	}
//	if (g_debug->map_path)
//	{
//		ft_printf("\n\n \n");
//		print_path_map(map->map, map->col, map->line);
//		ft_printf("\n \n");
//	}
	return (map);
}
