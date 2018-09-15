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

void sep(char *text)
{
	ft_printf(" \n\n");

	ft_printf("=========================================================== \n");
	ft_printf("=========================================================== \n");
	ft_printf("=========================================================== \n");
	ft_printf("\n"
			  "\033[32m--> %s  <--\033[0m \n", text);
}

int print_list_input_fd(t_dll_l *link, void *ptr)
{
	static int nb_line = 0;
	static char *line;

	(void) ptr;
	line = link->content;
	ft_printf("ligne nb = %4d -->     %s \n", nb_line, link->content);
	++nb_line;

	return (FALSE);
}

int print_parsing_room_dll(t_dll_l *link, void *ptr)
{
	t_room *room;

	(void) ptr;
	room = link->content;
	ft_printf("room link --> \n");
	ft_printf("n =      %10d \n", room->nb);
	ft_printf("name :   %10s\n", room->name);
	ft_printf("X        %10d\n", room->x);
	ft_printf("Y        %10d\n", room->y);
	ft_printf("=================== \n\n");
	return (FALSE);
}

int get_start_end(t_dll_l *link, void *nb_room)
{
	t_room *room;

	room = link->content;
	if (room->nb == *(int *) nb_room)
		return (TRUE);
	return (FALSE);
}

void print_room_parsing(t_data *data, t_debug *debug)
{
	(void) data;
	if (debug->print_parsing == TRUE)
	{
		sep("les room parses \nde la struct data.room");
		dll_func(&data->room, print_parsing_room_dll, NULL, ALL_LIST);
		ft_printf(" \n");
		ft_printf("******************************************************* \n");
		ft_printf("le nom de la start : %s\n",
				  ((t_room *) dll_func(&data->room, &get_start_end,
									   &data->start_room,
									   ALL_LIST)->content)->name);
		ft_printf("le nom de la end   : %s\n",
				  ((t_room *) dll_func(&data->room, &get_start_end,
									   &data->end_room,
									   ALL_LIST)->content)->name);
		ft_printf("******************************************************* \n");
	}
}

int print_tunnel_parsing_dll(t_dll_l *link, void *ptr)
{
	t_tunnel *tunnel;

	(void) ptr;
	tunnel = link->content;

	ft_printf("tunnel link --> \n");
	ft_printf("room 1 :  %s\n", tunnel->room_1->name);
	ft_printf("room 2 :  %s\n", tunnel->room_2->name);
	ft_printf("=================== \n\n");
	return (FALSE);
}

void print_tunnel_parsing(t_data *data, t_debug *debug)
{
	(void) data;
	if (debug->print_parsing == TRUE)
	{
		sep("les tunnel parses \nde la struct data.tunnel");
		dll_func(&data->tunnel, print_tunnel_parsing_dll, NULL, ALL_LIST);
	}
}