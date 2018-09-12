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

void set_up_algo(t_lem *lem, t_data *data)
{
	t_map *map;
	t_cache *cache;
	t_algo *algo;

	// faire les allocation de memoire
	(void) "  set up cache  ";
	algo = &lem->algo;
	cache = &algo->cache;
	// TODO : pas besoin de protection si je fais dans la stack
	cache->end_room = data->end_room;

	(void) "  set up map  ";
	map = &algo->map;
	map->col = data->room->length;
	map->size = data->room->length * data->room->length;
	fill_map_with_tunnel(data, map);
}

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


int lem_get_option(t_debug *deb, int fd)
{
	static char *real_option = { PARCER_DATA };
	char *line;
	char **option_splitted;
	int size_tab;
	int ret;

	ret = TRUE;
	ask_gnl(fd, &line, NULL, TRUE);
	if (*line == '-')
	{
		if (ft_str_split(line, " ", &option_splitted, &size_tab) != OK)
			return (FAIL);
		if (get_option_gnl(option_splitted, deb->option_finded, real_option)
			== TRUE)
		{
			// set les option dans ma stucture :)
		}
		else
		{
			print_usage(NAME_PROG);
			ret = FAIL;
		}
	}
	return (ret);
}

int g_build;

int main(void)
{
	t_lem lem;
	//	t_move move;
	//	int ret;

	// TODO : get les options ici  || si bad option return un usage
	// je vais faire du gnl pour get tout le temps, donc si la premiere ligne commence par un - --> je get des options !
	lem_get_option(&lem.debug, open_file(
	 "/Users/adpusel/Dropbox/42/projects/lem_in/rendu/test/0__test_option/test_option_good"));

	// TODO : set le debug avec les options
	//	set_debug(&g_debug);
	// TODO : check si le sizeof marche bien
	ft_zero(&lem);
	// je gere l'erreur ici c'est plus clair
	//		if (read_and_parse_data(&lem.data) == FAIL)
	//		ft_printf("ERROR in data given \n");
	{
		// TODO : set directement dans algo sont setup
		//		set_up_algo(lem, lem->data);
		// TODO : comme ca je peux mettre directement dans unr boucle de if les retour
		//		move = algo(&lem->algo->cache, lem->data, lem->algo->map);
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
