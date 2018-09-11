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

#include "../../includes/all_includes.h"

void	print_path_link(void *link)
{
	t_path *path;

	path = link;
	ft_printf("%d-", path->room + 1);
}

void	print_path(t_path *path)
{
	while (path)
	{
		ft_printf("%c %d -- ", path->room + 'A', path->size);
		path = path->prev;
	}
	ft_printf(" \n");
}

void	print_path_dll(void *link)
{
	print_path(link);
}
