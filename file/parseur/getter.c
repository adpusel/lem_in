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
	static int ret;

	ask_gnl(get->utils.fd, &get->utils.line, NULL, FALSE);
	// je vais mettre le parseur ici c'est moins chiant
	// sinon je doit faire une struc pour gnl qui va get les data\
	// toute seul, que je passe, donc io, db, data, algo || c'est plutot claire
	// avec dedant un count qui set get next line ou pas :) ca me permet
	// de bien decouper le code et c'est tres claire !!
	//
	ret = str_is_int(get->utils.line, &result);
	if (ret != OK || result <= 0)
	{
		return (FAIL);
	}// todo err fourmis
	get->data->nb_fourmis = result;
	return (OK);
}

int lem_getter(t_getter *get)
{
	int ret;

	//	get->utils.fd = g_debug.fd_file;
	(void) " le reste n'est pas lancer en cas d'erreur   ";
	ret = get_nb_foumis(get) == OK
		  && get_room(get->data, &get->utils) == OK
		  && get_tunnel(get->data, &get->utils) == OK;
	ft_str_free(&get->utils.line);
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

void set_up_parser_data(t_data *data, t_getter *get)
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
	//	if (g_debug->parseur == TRUE)
	//		check_data(data);
	return (ret);
}
