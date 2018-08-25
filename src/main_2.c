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

void	print_tunnel_end(void *tunnel_ptr)
{
	t_tunnel tunnel;

	tunnel = tunnel_ptr;
	ft_printf("%s-%s\n", tunnel->room_1->name, tunnel->room_2->name);
}

void	print_room_end(void *room_ptr)
{
	t_room room;

	room = room_ptr;
	if (room->type == L_START)
		ft_printf("##start\n");
	if (room->type == L_END)
		ft_printf("##end\n");
	ft_printf("%s %d %d\n", room->name, room->x, room->y);
}

void	print_data(t_data data)
{
	ft_printf("%d \n", data->nb_fourmis);
	dll_func(data->room, &print_room_end);
	dll_func(data->tunnel, print_tunnel_end);
	ft_printf(" \n");
}

void	kill_move(t_move move, size_t lim)
{
	t_real_path	real;
	size_t		i;

	i = 0;
	while (i < lim)
	{
		real = move->tab[i];
		destroy_dll(&real->list_path);
		free(real);
		++i;
	}
	free(move->tab);
	free(move);
}
