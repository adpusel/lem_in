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

int get_all_data_fd(int fd, t_dll *list)
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
	return (ret);
}

/**
 * \brief 	au premier appel la function keep la list,
 * 			elle fonctionne comme ask gnl
 * @param next_line 	next_line si TRUE, passe a la seconde line
 * @param ptr_nb_line  	le nb de la line current
 * @param data_list 	set la premiere fois pour get
 * @return
 */
int ask_data_list(
 int next_line,
 char **line,
 int *ptr_nb_line,
 t_dll *data_list)
{
	static t_dll_l *link = NULL;
	static int cur_line = 0;

	t_dll_l *dev_link;
	link = link == NULL ? data_list->top : link;
	if (link != NULL)
	{
		if (next_line == NEXT)
		{
			cur_line++;
			link = link->next;
		}
		if (next_line == PREV)
			link = link->prev;
		if (ptr_nb_line != NULL)
			*ptr_nb_line = cur_line;
		dev_link = link;
		*line = link != NULL ? link->content : NULL;
		return (link != NULL ? OK : FALSE);
	}
	else
		return (FALSE);
}