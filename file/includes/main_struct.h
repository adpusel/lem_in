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


#ifndef MAIN_STRUCT_H
#define MAIN_STRUCT_H

#include "dll.h"
#include "struct_parser.h"
#include "struct_algo.h"

/*
**    data
*/
typedef struct		s_data
{
	t_dll			*room;
	t_dll			*tunnel;
	int				start_room;
	int				end_room;
	int				nb_fourmis;
	int				lim;

}					t_data;

typedef struct		s_algo
{
	t_cache			cache;
	t_map			map;
}					t_algo;


typedef struct		s_debug
{
	char			option_finded[10];
	int				print_parsing;
} 					t_debug;

/*
**    lem ========================================================
*/
typedef struct		s_lem
{
	t_data			data;
	t_algo			algo;
	t_debug			debug;
}				t_lem;


#endif
