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

// TODO : la fonction qui get les argv et les passe a db
// todo option qui output dans un file sans les # pcq ca marche pas dans mon visu pour les send a visu //  sa cappell trace 1 :)
// les option -p => manage correctement le parser

void p_lusage(char *option, char *all_option, char *text, int indent)
{
	ft_printf("%s %*s%s [%s] %s\n", option, indent, "", all_option, text);
}

void print_usage(char *name_prog)
{
	static int indent = 8;
	ft_printf("Usage %4s ./%s, [option] < $ARG | file\n", "", name_prog);
	printf("----- \n");
	p_lusage("-p", "parser", "print all data parsed", indent);
}

void print_list_data(t_debug *debug, t_dll *data_list)
{
	if (debug->print_parsing == TRUE)
	{
		sep(
		 "les datas sont mise avec gnl dans une liste chainee"
		 ": \nchaque ligne est un mailon de la list data.all_data");
		dll_func(data_list, print_list_input_fd, NULL, ALL_LIST);
		ft_printf(" \n");
	}
}

int split_and_get_option(char *line, t_debug *debug)
{
	int ret;
	t_split split;
	static char *real_option = { PARCER_DATA };

	ft_zero(&split);

	if (ft_str_split(line, " ", &split) != OK)
		return (FAIL);

	if (get_option_gnl(split.tab,
					   debug->option_finded,
					   real_option)
		== TRUE)
	{
		if (check_char_into_str(debug->option_finded, 'p'))
			debug->print_parsing = TRUE;
		ret = TRUE;
	}
	else
		ret = FALSE;
	ft_free_split(&split.tab);
	return (ret);
}

int lem_get_option(t_debug *deb, t_dll *data_list)
{
	char *line;
	static int ret = TRUE;

	if (ask_data_list(data_list, &line, FALSE) != TRUE)
		ft_printf("NO DATA\n");
	if (*line == '-')
	{
		if (split_and_get_option(line, deb) != TRUE)
		{
			print_usage(NAME_PROG);
			ret = FAIL;
		}
		if (data_list->length == 1)
		{
			ft_printf("Just options are given \n");;
			ret = FAIL;
		}
	}
	if (ret == OK)
		print_list_data(deb, data_list);
	return (ret);
}
