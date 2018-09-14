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

int check_same_tunnel_link(t_dll_l *link, void *ptr_tunnel)
{
	t_tunnel *new_t;
	t_tunnel *list_t;

	list_t = link->content;
	new_t = ptr_tunnel;
	if ((list_t->room_1 == new_t->room_1 || list_t->room_1 == new_t->room_2)
		&& (list_t->room_2 == new_t->room_1
			|| list_t->room_2 == new_t->room_2))
		return (TRUE);
	else
		return (FALSE);
}

// todo err si la room n'est pas trouv3
t_room *find_room_name_tunnel(char *name_room, t_dll *room_list)
{
	// parse et set les room, check la taille des data et les sends.
	// split la line, et set les deux rooms, return err si fail
	static t_dll_l *link;

	link = NULL;
	link = dll_func(room_list, find_room, name_room, ALL_LIST);
	return (link ? link->content : NULL);
}

int check_valid_room_name(char *line, t_dll *room_list, t_room **room_1,
 t_room **room_2)
{
	char **tunnel_line_splitted;
	t_split split;

	if (ft_str_split(line, "-", &split) != OK)
		return (MEM_LACK);
	if (split.size == 2)
	{
		*room_1 = find_room_name_tunnel(*split.tab, room_list);
		*room_2 = find_room_name_tunnel(*(split.tab + 1), room_list);
	}
	ft_free_split(&tunnel_line_splitted);
	return (*room_1 && *room_2 ? OK : FAIL);
}

// s
int check_exist_tunnel(t_dll *tunnel_list, t_room *room_1, t_room *room_2)
{
	t_tunnel tunnel;

	tunnel.room_1 = room_1;
	tunnel.room_2 = room_2;

	return (dll_func(tunnel_list,
					 check_same_tunnel_link, &tunnel, ALL_LIST)
			!= NULL ? OK : FAIL);
}

int build_tunnel_link(t_data *data, t_get_utils *utils)
{
	t_dll_l *tunnel_link;
	t_room *room_1;
	t_room *room_2;
	int ret;

	tunnel_link = NULL;
	ret =
	 check_valid_room_name(utils->line, &data->room, &room_1, &room_2) != OK
	 && check_exist_tunnel(&data->tunnel, room_1, room_2) == OK
	 && new_tunnel_link(room_1, room_2, &tunnel_link) == OK;
	if (ret == OK)
		dll_add_at_index(tunnel_link, &data->tunnel, ALL_LIST);
	return (ret);
}

int get_tunnel(t_data *data, t_get_utils *utils)
{
	int last_line;

	last_line = 1;
	while (utils->line && (last_line || ask_gnl(utils->fd, &utils->line, NULL, TRUE)))
	{
		if (utils->line[0] == '#')
			continue;
		else if (ft_how_many_char('-', utils->line) == 1)
		{
			if (build_tunnel_link(data, utils) == FALSE)
				return (FALSE);
		}
		else
			break;
		last_line = 0;
	}
	return (TRUE);
}
