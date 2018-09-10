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

// todo verifier le x et le y avant de les ajouter
//	if (str_is_int(x, &room.x) == FALSE || ft_atoi(x) < 0)
//		return (print_err_retrun_null("x is fuck", g_debug->print_err));
//	if (str_is_int(y, &room.y) == FALSE || ft_atoi(x) < 0)
//		return (print_err_retrun_null("y is fuck", g_debug->print_err));
//				 *(room_splited + 1),
//				 *(room_splited + 2),  les room
t_dll_l add_room_link(t_data *data, t_get_utils *utils)
{
	static t_dll_l *room_link;
	char **room_splited;
	static int i = 0;
	int size_split;
	int ret;

	ret = ft_str_split(utils->line, " ", &room_splited, &size_split);
	 = new_checked_room_link(*room_splited, data, &room_link);
	if (room_link)
		((t_room *) room_link->content)->type = manage_end_start(i, data,
																 utils);
	dll_add_at_index(room_link, data->room, data->room->length);
	ft_free_split(&room_splited);
	i++;
	return (room_link);
}

/*
**	**** VARIABLES
**
**	**** RETURN
**
**	**** MAKING
**	verifie une fois toutes les rooms lue,
**	et affiche un message d'erreur en  consequence
*/

int check_err_room(t_data data)
{
	if (data->start_room < 0)
		return (print_err_retrun_int("pas de start", g_debug->print_err));
	if (data->end_room < 0)
		return (print_err_retrun_int("pas de end", g_debug->print_err));
	if (data->start_room == data->end_room)
		return (print_err_retrun_int("start et end sont les memes",
									 g_debug->print_err));
	else
		return (TRUE);
}

/*
**si count space == 2 --> je split et donne les 3 a create room_link
**si pas de space je stop
*/

int get_room(t_data *data, t_get_utils *utils)
{
	while (ask_gnl(utils->fd, &utils->line, NULL))
	{
		if (utils->line[0] == '#')
			utils->type_salle = manage_comment(utils->line);
		else if (ft_how_many_char(' ', utils->line) == 2)
		{
			if (ft_how_many_char('-', utils->line) > 0 ||
				utils->line[0] == 'L')
			{
				// TODO : ici print des err de normes
				// print_err_retrun_int("- dans le nom de la room",
				//									 g_debug->print_err);
				break;
			}
			if (add_room_link(data, utils) == FALSE)
				break;
		}
		else
			break;
	}
	return (check_err_room(data));
}
