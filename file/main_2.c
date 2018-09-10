/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:38:36 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 16:38:41 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/function.h"

int print_tunnel_end(t_dll_l *tunnel_link, void *ptr)
{
	t_tunnel *tunnel;

	(void)ptr;
	tunnel = tunnel_link->content;
	ft_printf("%s-%s\n", tunnel->room_1->name, tunnel->room_2->name);
	return (FALSE);
}

int print_room_end(t_dll_l *room_link, void *ptr)
{
	t_room *room;

	(void)ptr;
	room = room_link->content;
	if (room->type == L_START)
		ft_printf("##start\n");
	if (room->type == L_END)
		ft_printf("##end\n");
	ft_printf("%s \n", room->name);
	return (FALSE);
}

void print_data(t_data *data)
{
	ft_printf("%d \n", data->nb_fourmis);
	dll_func(data->room, &print_room_end, NULL, ALL_LIST);
	dll_func(data->tunnel, print_tunnel_end, NULL, ALL_LIST);
	ft_printf(" \n");
}

void kill_move(t_move *move, size_t lim)
{
	t_real_path *real;
	size_t i;

	i = 0;
	while (i < lim)
	{
		real = &move->tab[i];
		destroy_dll_stack(&real->list_path, NULL);
		free(real);
		++i;
	}
	free(move->tab);
	free(move);
}
