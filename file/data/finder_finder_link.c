/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_finder_link.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:07:02 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 15:08:09 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

t_finder *new_finder(t_data *data, int new_room_start,
 t_map *map, t_cache *cache)
{
	t_finder *finder;
	char *char_ptr;
	int ret;

	ret = ft_memory((void **) &finder, sizeof(t_finder)) == OK &&
		  ft_memory((void **) &char_ptr, (sizeof(char) * map->line)) == OK;
	if (ret != OK)
		return (NULL);
	finder->valid_path = &cache->valid_path;
	finder->all_path = &cache->all_path;
	finder->end_room = data->end_room;
	finder->start_room = new_room_start;
	finder->taken_room = char_ptr;
	return (finder);
}
