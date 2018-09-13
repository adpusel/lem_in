/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

# include "ft_library_header.h"
# include "getter.h"
# include "struct_parser.h"
# include "struct_algo.h"


typedef struct		s_d
{
	int				error_handler;
	int				parseur;
	int				print_err;
	int				map_tunnel;
	int				map_path;
	int				print_split;
	int				final_path;
	int				fd_file;
	int				little;
	char			option_finded[10];
}					t_db;


/*
**    struct_path
*/
typedef struct		s_b_path
{
	char			*tab;
	int				nb;
	int				line;
}					t_b_path;

/*
**    best_path ========================================================
*/
typedef struct		s_best_path
{
	t_b_path		cache;
	t_b_path		data;

}					t_best;

/*
**    real_path ========================================================
*/
typedef struct		s_real_path
{
	int				size;
	int				free;
	t_dll			list_path;
}					t_real_path;

typedef struct		s_move
{
	t_data			*data;
	int				nb_fourmis;
	size_t			size_tab;
	t_real_path		**tab;
	int				end_room;
}					t_move;

#endif
