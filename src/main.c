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

void	print_map(char *tab_room, size_t size_line)
{
	size_t	i;
	size_t	line;
	int		letter;
	size_t	lim;

	i = 0;
	line = 0;
	letter = 'B';
	lim = size_line * size_line;
	print_name(size_line);
	ft_printf("\nA   ");
	while (i < lim)
	{
		ft_printf("%2c ", tab_room[i] ? 'X' : '.');
		++i;
		++line;
		if (line == size_line && i < lim)
		{
			ft_printf(" \n%c   ", letter);
			letter++;
			line = 0;
		}
	}
	ft_printf("\n");
}

void	set_up_algo(t_lem lem, t_data data)
{
	t_map	map;
	t_cache	cache;
	t_algo	algo;

	(void)"  set up cache  ";
	lem->algo = ft_0_new_memory(sizeof(t_algo_00));
	algo = lem->algo;
	cache = &algo->cache;
	cache->all_path = new_dll();
	cache->valid_path = new_dll();
	cache->end_room = data->end_room;
	(void)"  set up map  ";
	algo->map = ft_0_new_memory(sizeof(t_map_00));
	map = algo->map;
	map->col = data->room->length;
	map->line = data->room->length;
	map->size = data->room->length * data->room->length;
	map->map = ft_0_new_memory(map->size * sizeof(char));
	fill_map_with_tunnel(data, map);
}

int		main(void)
{
	t_lem	lem;
	t_move	move;

	g_debug = set_debug(FALSE, FALSE, FALSE);
	lem = ft_0_new_memory(sizeof(t_lem_00));
	if (read_and_parse_data(lem) == TRUE)
	{
		set_up_algo(lem, lem->data);
		move = algo(&lem->algo->cache, lem->data, lem->algo->map);
		if (move != NULL)
		{
			print_data(lem->data);
			manage_move(move);
			kill_move(move, move->size_tab);
		}
		else
			ft_printf("ERROR\n");
	}
	else
		ft_printf("ERROR\n");
	free_lem(lem);
	free(g_debug);
	return (EXIT_SUCCESS);
}
