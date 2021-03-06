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

#ifndef LEM_IN_FUNCTION_H
# define LEM_IN_FUNCTION_H

# include "all_includes.h"

/*
**    g_debug ========================================================
*/
extern t_db g_debug;
int set_debug(t_db *db);

/*
**    print db
*/
void sep(char *text);
int print_list_input_fd(t_dll_l *link, void *ptr);
void print_room_parsing(t_data *data, t_debug *debug);
void print_tunnel_parsing(t_data *data, t_debug *debug);

/*
**   get input
*/
int ask_data_list(
 int next_line,
 char **line,
 int *ptr_nb_line,
 t_dll *data_list);
int get_all_data_fd(int fd, t_dll *list);

/*
**    get option
*/
int lem_get_option(t_debug *deb, t_dll *data_list);


/*
**    destroy
*/
void		*destroy_finder(t_finder *finder);



/*
**    Parseur ==================================================================
*/

int read_and_parse_data(t_data *data, t_debug *debug);
int check_valid_room_name(char *line, t_dll *room_list, t_room **room_1,
 t_room **room_2);
/*
**    split
*/
void	split_path(t_map *map, t_finder *finder, t_path *cur_path);
size_t	split_all_path(t_finder *finder, t_map *map);

/*
**    run_algo
*/
int run_algo(t_algo *algo, t_data *data, t_move *move, t_debug *debug);
int shorty_baby(t_finder **finder, t_cache *cache, t_data *data, t_map *map);
void	print_name(int a);
void	print_map(char *tab_room, size_t size_line);
int set_up_tunnel_map(t_map *map, t_data *data, t_debug *debug);

/*
**    debugs
*/
void	print_tunnel_dll(void *room_link);
void	print_map(char *tab_room, size_t size_line);
void	print_path_dll(void *link);
void	print_path_link(void *link);
void	print_path_map(char *tab_room, size_t size_line, size_t col);
void	print_line_first(char *tab_room, size_t size_line, int cur_line);
void	print_path_dll_order(void *link);
void	print_line_first_int(char *tab_room, size_t size_line, int cur_line);
int		is_free(t_move *move, size_t nb_path);
int		add_f(t_move *move, size_t nb_path, int f_nb);
int		put_f_all_start(t_move *move);
int		move_all_f(t_move *move);
void	print_data(t_data *data);
void	kill_move(t_move *move, size_t lim);

t_best	*new_best_path(size_t nb_path);
t_move	*new_move(t_data *data, t_b_path *best_path, t_finder *finder);
void	manage_move(t_move *move);

/*
**    path
*/
t_dll_l	*new_path_link(int room, t_path *prev, t_dll *all_path, int size);
void	print_path(t_path *path);
t_map	*generate_path_map(t_dll *room, t_dll *path_lst);
void	find_best_path(t_map *map, t_best *best);


void	init_cache(t_cache *cache, t_data *data);
void	clean_woking(t_finder *finder);

void	destroy_map(t_map *map);

void	free_lem(t_lem *lem);

int lem_getter(t_getter *get);
int get_tunnel(t_data *data, t_get_utils *utils, t_debug *debug);
int get_room(t_data *data, t_get_utils *utils, t_debug *debug);
void fill_map_with_tunnel(t_data *data, t_map *map, t_debug *debug);

/*
**    paseur utils
*/
int		manage_comment(char *comment_str);
int		is_right_room(t_dll_l *link, void *ptr_new_room);
int		check_err_room(t_data *data);

/*
**    contruct ========================================================
*/
int	new_tunnel_link(t_room *room_1, t_room *room_2, t_dll_l **tunnel_link);
int new_checked_room_link(char *name, t_data *data, t_dll_l **ptr_link);
t_finder	*new_finder(t_data *data, int new_room_start, t_map *map, t_cache *cache);
void add_x_y_surfinthenorme(int x, int y, t_room *room);
/*
**    destroy ========================================================
*/
void	destroy_tunnel(void *ptr_tunnel);
//void	destroy_room(void *room_ptr);

#endif
