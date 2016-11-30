/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:55:15 by cfrouin           #+#    #+#             */
/*   Updated: 2016/11/28 13:48:01 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

typedef struct			s_tetriminos
{
	char				letter;
	char				shape[4][4];
	int					length;
	int					height;
	struct s_tetriminos	*prev;
	struct s_tetriminos	*next;
}						t_tetriminos;

/*
** tet_list.c
*/

int						tet_list_pushback(t_tetriminos *list,
											t_tetriminos *new);
int						tet_list_popback(t_tetriminos *list);
void					tet_list_destroy(t_tetriminos *list);
t_tetriminos			*tet_list_index(t_tetriminos *list, size_t index);
size_t					tet_list_length(t_tetriminos *list);

/*
** file.c
*/

int						open_file(char *filename);
t_tetriminos			*check_file(char *filename);
t_tetriminos			*new_content(int fd, int i);

/*
** check_tetriminos.c
*/

void					tet_size(t_tetriminos *tetr);
void					tet_trim(t_tetriminos *tetr);
size_t					min_map(t_tetriminos *tetr);
int						check_tetriminos(t_tetriminos *tetr);
void					make_map(t_tetriminos *tetr, size_t sqr);

/*
** resolve.c
*/

void					set_tetr(t_tetriminos *tetr, char **map, int x, int y);
void					remove_tetr(t_tetriminos *tetr, char **map,
									int x, int y);
int						place_tetr(t_tetriminos *tetr, char **map,
									int x, int y);
int						solve_tetr(t_tetriminos *list, char **map, int size);
int						solve(t_tetriminos *list);

/*
** resolve_map.c
*/

char					**new_map(int size);
void					delete_map(char **tab);

/*
** ft_puttab.c
*/

void					ft_puttab(char **tab);
void					display_tetr(t_tetriminos *tetr);

#endif
