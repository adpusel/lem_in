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

int find_room(t_dll_l *link, void *ptr_str)
{
	char *current_room;
	char *room;

	current_room = ((t_room *) link->content)->name;
	room = ptr_str;
	if (ft_str_eq(current_room, room) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_room *find_room_name_tunnel(char *name_room, t_dll *room_list)
{
	static t_dll_l *link;

	link = dll_func(room_list, find_room, name_room, ALL_LIST);
	return (link ? link->content : NULL);
}

int check_valid_room_name(char *line, t_dll *room_list, t_room **room_1,
 t_room **room_2)
{
	t_split split;

	if (ft_str_split(line, "-", &split) != OK)
		return (MEM_LACK);
	if (split.size == 2)
	{
		*room_1 = find_room_name_tunnel(*split.tab, room_list);
		*room_2 = find_room_name_tunnel(*(split.tab + 1), room_list);
	}
	ft_free_split(&split.tab);
	return (*room_1 && *room_2 ? OK : FAIL);
}