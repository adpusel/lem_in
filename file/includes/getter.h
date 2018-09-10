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

#ifndef GETTER_H
# define GETTER_H
# include "all_includes.h"

/*
**    data
*/
typedef struct		s_data
{
	t_dll			room;
	t_dll			tunnel;
	int				start_room;
	int				end_room;
	int				x;
	int				y;
	int				nb_fourmis;
	int				lim;
}					t_data;

/*
**    utils
*/
typedef struct		s_get_utils
{
	char			*line;
	int				fd;
	int				type_salle;
}					t_get_utils;

/*
**    getter
*/
typedef struct		s_getter
{
	t_data			*data;
	t_get_util		utils;
}					t_getter;

#endif
