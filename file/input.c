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

int get_all_data_fd(int fd, t_dll *list, t_debug *db)
{
	t_dll_l *link;
	char *lines;
	int ret;

	ret = OK;
	while (ask_gnl(fd, &lines,
				   NULL,
				   TRUE) == OK)
	{
		if (new_dll_l(lines,
					  ft_strlen(lines) + 1,
					  &link) != OK)
		{
			ret = FALSE;
			break;
		}
		dll_add_at_index(link, list, ALL_LIST);
	}
	if (ret == OK && db->print_parsing == TRUE)
	{

	}
	return (ret);
}

int ask_data_list(t_dll *data_list, char **line, int next_line)
{
	static t_dll_l *link = NULL;
	static int counter = 0;
	t_dll_l *dev_link;

	dev_link = link;
	if (counter == 0)
	{
		link = data_list->top;
		counter = 1;
	}
	if (link != NULL)
	{
		*line = link->content;
		if (next_line == TRUE)
			link = link->next;
		return (TRUE);
	}
	else
		return (FALSE);
}