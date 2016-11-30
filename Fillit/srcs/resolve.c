/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:25:56 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/28 13:44:56 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		set_tetr(t_tetriminos *tetr, char **map, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetr->shape[j][i] == '#')
			{
				map[j + y][i + x] = tetr->letter;
			}
			i++;
		}
		j++;
	}
}

void		remove_tetr(t_tetriminos *tetr, char **map, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < tetr->height)
	{
		i = 0;
		while (i < tetr->length)
		{
			if (tetr->shape[j][i] == '#')
				map[j + y][i + x] = '.';
			i++;
		}
		j++;
	}
}

int			place_tetr(t_tetriminos *tetr, char **map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < tetr->height)
	{
		while (i < tetr->length)
		{
			if (map[j + y][i + x] != '.' && tetr->shape[j][i] == '#')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	set_tetr(tetr, map, x, y);
	return (1);
}

int			solve_tetr(t_tetriminos *list, char **map, int size)
{
	int		x;
	int		y;

	y = 0;
	while (size - y >= list->height)
	{
		x = 0;
		while (size - x >= list->length)
		{
			if (place_tetr(list, map, x, y) == 1)
			{
				if (list->next == NULL
					|| solve_tetr(list->next, map, size) == 1)
					return (1);
				else
					remove_tetr(list, map, x, y);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

int			solve(t_tetriminos *list)
{
	int		size;
	char	**map;

	size = ft_ceil_sqrt(tet_list_length(list) * 4);
	if ((map = new_map(size)) == NULL)
		return (-1);
	while (solve_tetr(list, map, size) == -1)
	{
		size++;
		delete_map(map);
		if ((map = new_map(size)) == NULL)
			return (-1);
	}
	ft_puttab(map);
	delete_map(map);
	return (1);
}
