/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/17 15:09:12 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

/*
**check si x et y sont bien des int < 0
**verifie que
*/

int new_checked_room_link(char *name, t_data *data, t_dll_l **ptr_link)
{
	static t_room room;
	static t_dll_l *room_link = NULL;
	static char *char_ptr;
	int ret;

	ret = ft_str_dup(&char_ptr, name) == OK &&
		  new_dll_l(&room, sizeof(t_room), &room_link) == OK;
	if (ret == OK)
	{
		if (dll_func(&data->room, is_right_room, room_link, ALL_LIST) != NULL)
		{
			destroy_dll_l(&room_link, NULL);
			ret = FAIL;
		}
		else
		{
			((t_room*)room_link->content)->name = char_ptr;
			*ptr_link = room_link;
		}
	}
	return (ret);
}

// todo check les numero ici
void add_x_y_surfinthenorme(int x, int y, t_room *room)
{
	room->x = x;
	room->y = y;
}

void destroy_room(void *room_ptr)
{
	t_room *room;

	room = room_ptr;
	ft_str_free(&room->name);
	free(room);
}
