/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/17 15:43:34 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_includes.h"

int check_err_room(t_data *data)
{
	int ret;

	ret = OK;
	if (data->start_room < 0)
	{
		ft_printf("pas de room start \n");
		ret = FALSE;
	}
	else if (data->end_room < 0)
	{
		ft_printf("pas de room end");
		ret = FALSE;
	}
	else if (data->start_room == data->end_room)
	{
		ft_printf("la room start et la room end sont les memes \n");
		ret = FALSE;
	}
	return (ret);
}

int manage_end_start(int i, t_data *data, t_get_utils *utils)
{
	static int res;

	res = 0;
	if (utils->type_salle == L_START)
	{
		data->start_room = i;
		res = L_START;
	}
	if (utils->type_salle == L_END)
	{
		data->end_room = i;
		res = L_END;
	}
	utils->type_salle = 0;
	return (res);
}

int init_room_check_xy(t_room *room, char *line, int nb_line, int nb_room)
{
	t_split split;
	int ret;

	ret = OK;
	if (ft_str_split(line, " ", &split) != OK
		|| ft_str_dup(&room->name, *split.tab) != OK)
		return (FALSE);
	if (str_is_int(*(split.tab + 1), &room->x) != OK || room->x <= 0)
	{
		ft_printf("ligne %d, x n'est pas un int | positif", nb_line);
		ret = FALSE;
	}
	if (str_is_int(*(split.tab + 2), &room->y) != OK || room->y <= 0)
	{
		ft_printf("ligne %d, y n'est pas un int | positif", nb_line);
		ret = FALSE;
	}
	room->nb = nb_room;
	ft_free_split(&split.tab);
	return (ret);
}

/*
**    test et ajoute apres verification le link
*/

int test_add_room_link(t_data *data, t_get_utils *utils, int nb_line)
{
	static int nb_room = 0;
	t_room room;
	t_dll_l *room_link;

	static int t = 0;
	if (t == 1)
		(void) 1;
	t++;
	ft_zero(&room, sizeof(room));
	if (1
		&& init_room_check_xy(&room, utils->line, nb_line, nb_room) == OK
		&& dll_func(&data->room, is_right_room, &room, ALL_LIST) == NULL
		&& new_dll_l(&room, sizeof(t_room), &room_link) == OK)
	{

		dll_add_at_index(room_link, &data->room, ALL_LIST);
		manage_end_start(nb_room, data, utils);
	}
	else
	{
		ft_printf("err est a la ligne %d\n", nb_line);
		return (FALSE);
	}
	++nb_room;
	return (TRUE);
}

/*
**    tant que maillons est correct
*/

int get_room(t_data *data, t_get_utils *utils, t_debug *debug)
{
	static int nb_line;
	int ret;

	while (ask_data_list(TRUE, &utils->line, &nb_line, NULL) == OK)
	{
		if (utils->line[0] == '#')
			utils->type_salle = manage_comment(utils->line);
		else if (ft_how_many_char(' ', utils->line) == 2)
		{
			if (ft_how_many_char('-', utils->line) > 0
				|| utils->line[0] == 'L')
			{
				ft_printf("line %d --> err dans les rooms \n", nb_line);
				return (FALSE);
			}
			if (test_add_room_link(data, utils, nb_line) != OK)
				return (FALSE);
		}
		else
			break;
	}
	ret = check_err_room(data);
	if (ret == OK)
		print_room_parsing(data, debug);
	return (ret);
}
