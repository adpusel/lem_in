/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:38:36 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 16:38:41 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_includes.h"

int g_build;

void t_dev(t_debug *db)
{
	db->print_parsing = TRUE;
	db->print_algo = TRUE;
}

int main()
{
	t_lem lem;
	ft_zero(&lem, sizeof(t_lem));
	t_move move;
	//	int ret;

	/*------------------------------------*\
	    get les data
	\*------------------------------------*/
	g_build = open_file(
	 "/Users/adpusel/code/42/lem_in/test/dur_test/test_2_test");
	get_all_data_fd(g_build, &lem.data.all_data);


	// si c'est une option file ? --> je regarde direct dedans comment faire :)
	// TODO : get les options ici  || si bad option return un usage
	// je vais faire du gnl pour get tout le temps, donc si la premiere ligne commence par un - --> je get des options !
	if (lem_get_option(&lem.debug, &lem.data.all_data) == FALSE)
		return (EXIT_FAILURE);
	t_dev(&lem.debug);


	// TODO : set le debug avec les options
	//	set_debug(&g_debug);

	// TODO : si err, quitter en free tout correctement
	read_and_parse_data(&lem.data, &lem.debug);
	{
		run_algo(&lem.algo.cache, &lem.data, &lem.algo.map, &move);
		// TODO : comme ca je peux mettre directement dans unr boucle de if les retour
		//		move = algo(&lem->algo->cache, lem->data, lem->run_algo->map);
		// TODO : refaire bien ici avec le print des data aussi dans une boucle
		//		if (move != NULL)
		//		{
		//			print_data(lem->data);
		//			manage_move(move);
		//			kill_move(move, move->size_tab);
		//		}
		//		else
		//			ft_printf("NO SOLUTION\n");
	}
	//	else
	//	ft_printf("NO SOLUTION\n");
	//	free_lem(&lem);
	//	free(g_debug);
	return (EXIT_SUCCESS);
}

