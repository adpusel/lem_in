/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:02:33 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 15:03:27 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

// TODO : free map
void kill_algo(t_algo *algo)
{
	destroy_map(&algo->map);
	destroy_dll_stack(&algo->cache.all_path, NULL);
	destroy_dll_stack(&algo->cache.valid_path, NULL);
	free(algo);
}

void free_lem(t_lem *lem)
{
	destroy_dll_stack(&lem->data.room, &destroy_room);
	destroy_dll_stack(&lem->data.tunnel, &destroy_tunnel);
	kill_algo(&lem->algo);
}

void		*destroy_finder(t_finder *finder)
{
	free(finder->taken_room);
	destroy_dll_stack(&finder->working_path, NULL);
	destroy_dll_stack(&finder->new_path, NULL);
	free(finder);
	return (NULL);
}