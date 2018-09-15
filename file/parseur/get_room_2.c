/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/17 15:31:46 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_includes.h"

int manage_comment(char *comment_str)
{
	if (ft_str_eq(comment_str, "##start") == TRUE)
		return (L_START);
	else if (ft_str_eq(comment_str, "##end") == TRUE)
		return (L_END);
	return (FALSE);
}

int lim_same_coord(t_room *current_room, t_room *new_room)
{
	if (current_room->x == new_room->x)
	{
		if (current_room->y == new_room->y)
		{
			ft_printf(
			 "la salle -- %s --  a les memes coord que la salle -- %s -- \n",
			 current_room->name,
			 new_room->name);
			return (TRUE);
		}
	}
	return (FALSE);
}

int lim_same_name(t_room *current_room, t_room *new_room)
{
	if (ft_str_eq(current_room->name, new_room->name) == TRUE)
	{
		ft_printf("la salle -- %s --  a le meme -- %s -- ",
				  current_room->name,
				  new_room->name);
		return (TRUE);
	}
	return (FALSE);
}

int is_right_room(t_dll_l *link, void *ptr_new_room)
{
	t_room *new_room;
	t_room *current_room;

	new_room = ptr_new_room;
	current_room = link->content;
	if (lim_same_coord(current_room, new_room) == TRUE)
		return (TRUE);
	if (lim_same_name(current_room, new_room) == TRUE)
		return (TRUE);
	return (FALSE);
}
