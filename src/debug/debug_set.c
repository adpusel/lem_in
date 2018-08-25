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

#include "../includes/all_includes.h"

t_debug g_debug;

t_debug	set_debug(int is_on, int little, int err)
{
	t_debug db;

	db = ft_0_new_memory(sizeof(t_db));
	db->little = little;
	db->print_err = err;
	(void)"  set les demandes de g_debug  ";
	if (is_on == TRUE)
	{
		db->map_tunnel = TRUE;
		db->print_split = TRUE;
		db->map_path = TRUE;
		db->final_path = TRUE;
	}
	(void)"  set le fichier a check  ";
//	db->fd_file = open_file("/Users/adpusel/Dropbox/42/projects/lem_in/vog/test/dur_test/test_1");
	db->fd_file = 0;
	g_debug = db;
	return (db);
}
