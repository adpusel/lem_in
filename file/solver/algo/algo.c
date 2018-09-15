/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/17 16:23:56 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/all_includes.h"


t_move		*is_solution(t_finder *finder, t_data *data)
{
	t_move		*move;
	t_map		*path_map;
	t_best		*best = NULL;

	move = NULL;
	path_map = generate_path_map(&data->room, finder->valid_path);
//	best = new_best_path(path_map->line);
	find_best_path(path_map, best);
//	move = new_move(data, &best->data, finder);
	ft_str_free(&best->cache.tab);
	ft_str_free(&best->data.tab);
	free(best);
//	destroy_map(path_map);
	return (move);
}



//int init_algo()
//{
//
//}

// TODO : set la map, ensuite set la
int run_algo(t_algo algo, t_data *data, t_move *move, t_debug *debug)
{
//	t_finder		*finder;
//	t_dll_l			*path_l;

	(void)move;
	algo.cache.end_room = data->end_room;
	// TODO : appel memoir a check !!
	set_up_tunnel_map(&algo.map, data, debug);
//	finder = new_finder(data, data->start_room, map, cache);
//	path_l = new_path_link(finder->start_room, NULL, finder->all_path, 0);
//	split_path(map, finder, path_l->content);
//	clean_woking(finder);
//	destroy_dll_l(&path_l, NULL);
//	if (
//			 g_debug->little == TRUE ||
//	 split_all_path(finder, map) == FALSE)
//	{
//		split_all_path(finder, map);
//		destroy_finder(finder);
//		 todo check le malloc ici
//		shorty_baby(&finder , cache, data, map);
//	}
//	if (finder->valid_path->length > 0)
//		move = is_solution(finder, data);
//	destroy_finder(finder);
	return (TRUE);
}