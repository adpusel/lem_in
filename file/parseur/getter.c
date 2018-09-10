/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:35:54 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 15:38:24 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

int get_nb_foumis(t_getter *get)
{
	static int result = 0;

	ask_gnl(get->utils.fd, &get->utils.line, NULL);
	if (str_is_int(get->utils.line, &result) == FAIL)
		return (print_err_retrun_int(ERR_FOURMIS_1, g_debug->print_err));
	else if (result <= 0)
		return (print_err_retrun_int(ERR_FOURMIS_2, g_debug->print_err));
	get->data->nb_fourmis = ft_atoi(get->utils.line);
	return (TRUE);
}

int lem_getter(t_getter *get)
{
	int ret;

	get->utils.fd = g_debug.fd_file;
	(void) " le reste n'est pas lancer en cas d'erreur   ";
	ret = TRUE
		  && get_nb_foumis(get) == FALSE
		  && get_room(get->data, &get.utils)
		  && get_tunnel(get->data, &get.utils) ?
		  TRUE : FAIL;
	free_str(&get.utils.line);
	return (ret);
}

//void check_data(t_data data)
//{
//	ft_printf("----> nb fourmis : %d\n---- \n", data->nb_fourmis);
//	ft_printf("----> les rooms \n");
//	ft_printf("----\n");
//	ft_printf("----> les tunnels \n");
//	dll_func_lim(data->tunnel, print_tunnel_dll, NULL, ALL_LIST);
//	ft_printf("---- \n");
//}

/*
** 	le parseur va get toute les err et lees stoker au fur et a mesure
** 	si err, le parseur les print et quitte
*/
// TODO : je set data et getter ici, comme getter va set directement dans data,
// je dois aussi get toute les data avec le parseur pour que c'est beau !!!

void     set_up_parser_data(t_data *data, t_getter *get)
{
    get->data = data;
	data->start_room = -1;
	data->end_room = -1;
}

int read_and_parse_data(t_data *data)
{
	int ret;
	t_getter get;

	set_up_parser_data(data, &get);
	ret = lem_getter(&get);
	if (g_debug->parseur == TRUE)
		check_data(data);
	return (ret);
}
