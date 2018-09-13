/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_algo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ALGO_H
# define STRUCT_ALGO_H

# include "ft_library_header.h"
# include "struct.h"

/*
**    stocke le cache et les data de recherche de path
*/
typedef struct		s_finder
{
	t_dll			working_path;
	t_dll			new_path;
	t_dll			*all_path;
	t_dll			*valid_path;
	int				end_room;
	int				start_room;
	char			*taken_room;
	int				option;
}					t_finder;

typedef struct		s_cache
{
	t_dll			all_path;
	t_dll			valid_path;
	t_dll			list_cache;
	int				end_room;
	int				start_room;
	int				option;
}					t_cache;

#endif
