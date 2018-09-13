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

#ifndef LEM_IN_ALL_INCLUDES_H
# define LEM_IN_ALL_INCLUDES_H

/*
**    LIBFT
*/
# include "ft_library_header.h"

/*
**    project includes
*/
# include "struct.h"
# include "getter.h"
# include "function.h"
# include "struct_parser.h"
# include "prog_option.h"
# include "main_struct.h"

/*
**    g_debug
*/
void	print_room_dll_l(void *room_ptr);

/*
**    DEFINE
*/
# define L_START 1
# define L_END -1
# define ERR_FOURMIS_1 "le nombre de fourmis n'est pas un integer"
# define ERR_FOURMIS_2 "le nb de fourmis n'est pas positif"


extern int g_build;
#endif
