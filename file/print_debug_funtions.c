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

#include "all_includes.h"

void	print_map(char *tab_room, size_t size_line)
{
	size_t	i;
	size_t	line;
	int		letter;
	size_t	lim;

	i = 0;
	line = 0;
	letter = 'B';
	lim = size_line * size_line;
	print_name(size_line);
	ft_printf("\nA   ");
	while (i < lim)
	{
		ft_printf("%2c ", tab_room[i] ? 'X' : '.');
		++i;
		++line;
		if (line == size_line && i < lim)
		{
			ft_printf(" \n%c   ", letter);
			letter++;
			line = 0;
		}
	}
	ft_printf("\n");
}
