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
	ft_printf("link --> \n");
	ft_printf("n =      %10d \n", room->nb);
	ft_printf("name :   %10s\n", room->name);
	ft_printf("X        %10d\n", room->x);
	ft_printf("Y        %10d\n", room->y);
	ft_printf("=================== \n\n");
	return (FALSE);
}

void print_room_parsing(t_data *data, t_debug *debug)
{
	(void) data;
	if (debug->print_parsing == TRUE)
	{
		//		sep("les room parses \nde la struct data.room");
		//		dll_func(&data->room, print_parsing_room_dll, NULL, ALL_LIST);
	}
}
