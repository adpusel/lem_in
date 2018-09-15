/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tunnel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:38:48 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 15:42:02 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

int check_same_tunnel_link(t_dll_l *link, void *ptr_tunnel)
{
	t_tunnel *new_t;
	t_tunnel *list_t;

	list_t = link->content;
	new_t = ptr_tunnel;
	if ((list_t->room_1 == new_t->room_1 || list_t->room_1 == new_t->room_2)
		&& (list_t->room_2 == new_t->room_1 || list_t->room_2 == new_t->room_2))
		return (TRUE);
	else
		return (FALSE);
}

int check_exist_tunnel(t_dll *tunnel_list, t_room *room_1, t_room *room_2)
{
	t_tunnel tunnel;
	int ret;

	tunnel.room_1 = room_1;
	tunnel.room_2 = room_2;

	ret = dll_func(tunnel_list,
				   check_same_tunnel_link, &tunnel, ALL_LIST)
		  == NULL ? OK : FAIL;
	return (ret);
}

int new_tunnel_link(t_room *room_1, t_room *room_2, t_dll_l **tunnel_link)
{
	t_tunnel tunnel; //todo mettre en static
	int ret;

	tunnel.room_1 = room_1;
	tunnel.room_2 = room_2;
	ret = new_dll_l(&tunnel, sizeof(t_tunnel), tunnel_link);
	return (ret);
}

int test_build_tunnel_link(t_data *data, t_get_utils *utils)
{
	t_dll_l *tunnel_link;
	t_room *room_1;
	t_room *room_2;

	if (check_valid_room_name(utils->line, &data->room, &room_1, &room_2) == OK
		&& check_exist_tunnel(&data->tunnel, room_1, room_2) == OK
		&& new_tunnel_link(room_1, room_2, &tunnel_link) == OK)
	{
		dll_add_at_index(tunnel_link, &data->tunnel, ALL_LIST);
		return (TRUE);
	}
	return (FALSE);
}

int get_tunnel(t_data *data, t_get_utils *utils, t_debug *debug)
{
	ask_data_list(PREV, &utils->line, NULL, NULL);
	while (ask_data_list(NEXT, &utils->line, &utils->nb_line, NULL) == OK)
	{
		if (utils->line[0] == '#')
			continue;
		else if (ft_how_many_char('-', utils->line) == 1)
		{
			if (test_build_tunnel_link(data, utils) == FALSE)
				return (FALSE);
		}
		else
			break;
	}
	print_tunnel_parsing(data, debug);
	return (TRUE);
}
