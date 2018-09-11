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

#include "all_includes.h"

void set_up_algo(t_lem *lem, t_data *data)
{
	t_map *map;
	t_cache *cache;
	t_algo *algo;

	// faire les allocation de memoire
	(void) "  set up cache  ";
	algo = &lem->algo;
	cache = &algo->cache;
	// TODO : pas besoin de protection si je fais dans la stack
	cache->end_room = data->end_room;

	(void) "  set up map  ";
	map = &algo->map;
	map->col = data->room->length;
	map->size = data->room->length * data->room->length;
	fill_map_with_tunnel(data, map);
}

int g_malloc_lack;

int main(void)
{
	t_lem lem;
	//	t_move move;
	//	int ret;


	// TODO : get les options ici  || si bad option return un usage
	// TODO : set le debug avec les options
	//	set_debug(&g_debug);
	// TODO : check si le sizeof marche bien
	ft_zero(&lem);
	// je gere l'erreur ici c'est plus clair
	if (read_and_parse_data(&lem.data) == FAIL)
		ft_printf("ERROR in data given \n");
	{
		// TODO : set directement dans algo sont setup
		//		set_up_algo(lem, lem->data);
		// TODO : comme ca je peux mettre directement dans unr boucle de if les retour
		//		move = algo(&lem->algo->cache, lem->data, lem->algo->map);
		// TODO : refaire bien ici avec le print des data aussi dans une boucle
		//		if (move != NULL)
		//		{
		//			print_data(lem->data);
		//			manage_move(move);
		//			kill_move(move, move->size_tab);
		//		}
		//		else
		//			ft_printf("NO SOLUTION\n");
	}
	//	else
	//	ft_printf("NO SOLUTION\n");
	free_lem(&lem);
	//	free(g_debug);
	return (EXIT_SUCCESS);
}
