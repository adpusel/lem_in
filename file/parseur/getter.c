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
	static int nb_line;

	ask_data_list(FALSE, &get->utils.line, &nb_line, NULL);
	if (str_is_int(get->utils.line, &result) == OK
		&& result <= 0)
	{
		ft_printf("ligne %d, le nb fourmis est incorrect \n", nb_line);
		return (FAIL);
	}
	get->data->nb_fourmis = result;
	return (OK);
}

/*
** 	le parseur va get toute les err et lees stoker au fur et a mesure
** 	si err, le parseur les print et quitte
*/

void set_up_parser_data(t_data *data, t_getter *get, t_debug *debug)
{
	get->data = data;
	get->debug = debug;
	data->start_room = -1;
	data->end_room = -1;
}

int read_and_parse_data(t_data *data, t_debug *debug)
{
	int ret;
	t_getter get;

	set_up_parser_data(data, &get, debug);
	ret = get_nb_foumis(&get) == OK
		  && get_room(get.data, &get.utils, debug) == OK
		  && get_tunnel(get.data, &get.utils, debug) == OK;
	ft_str_free(&get.utils.line);
	return (ret);
}
