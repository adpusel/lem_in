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

t_db g_debug;

//pas besoin de retour comme pas d'appelle memoire, mais peut avoir beug
// dans le get_argument, commet c'est un gnl, je fait un tab pour la premiere line
// si elle a un - au debut
int	set_debug(t_db *db)
{
	ft_memset(db, 0, sizeof(t_db));
	(void)"  set les demandes de g_debug  ";
	db->fd_file = 0;
	return (TRUE);
}
