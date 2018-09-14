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

#include "../includes/all_includes.h"

// todo repenser les message d'err pour le petit lemin
int check_err_room(t_data *data)
{
	(void) data;

	//	if (data->start_room < 0)
	//		return (print_err_retrun_int("pas de start", g_debug->print_err));
	//	if (data->end_room < 0)
	//		return (print_err_retrun_int("pas de end", g_debug->print_err));
	//	if (data->start_room == data->end_room)
	//		return (print_err_retrun_int("start et end sont les memes",
	//									 g_debug->print_err));
	//	else
	return (TRUE);
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

int init_room_check_xy(t_room *room, char *line, int nb_line)
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
	ft_free_split(&split.tab);
	return (ret);
}

// je ne suis pas proteger ici si j'ai deux start ? // plus simple de le set a la
// fin au cas ou :)
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
		&& init_room_check_xy(&room, utils->line, nb_line) == OK
		&& dll_func(&data->room, is_right_room, &room, ALL_LIST) == NULL
		&& new_dll_l(&room, sizeof(t_room), &room_link) == OK)
	{
		room.nb = nb_room;
		dll_add_at_index(room_link, &data->room, ALL_LIST);
	}
	else
	{
		return (FALSE);
	}
	++nb_room;
	return (TRUE);
}

/*
**si count space == 2 --> je split et donne les 3 a create room_link
**si pas de space je stop
*/

int get_room(t_data *data, t_get_utils *utils)
{
	static int nb_line;

	while (ask_data_list(TRUE, &utils->line, &nb_line, NULL) == OK)
	{
		// TODO : set le start et and a la fin en recherchant la room par nom
		// a check si pas trop chiant, par nb plus rapide
		if (utils->line[0] == '#')
			utils->type_salle = manage_comment(utils->line);

		else if (ft_how_many_char(' ', utils->line) == 2)
		{
			if (ft_how_many_char('-', utils->line) > 0 ||
				utils->line[0] == 'L')
			{
				ft_printf("line %d --> err dans les rooms \n", nb_line);
				return (FALSE);
			}
			if (test_add_room_link(data, utils, nb_line) != OK)
				break;
		}
		else
			break;
	}
	return (check_err_room(data));
}
